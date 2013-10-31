// *********************************************************************************************************************
// file:
// author: Juan Pablo Crossley (crossleyjuan@gmail.com)
// created:
// updated:
// license:
// 
// This file is part of the djondb project, for license information please refer to the LICENSE file,
// the application and libraries are provided as-is and free of use under the terms explained in the file LICENSE
// Its authors create this application in order to make the world a better place to live, but you should use it on
// your own risks.
// 
// Also, be adviced that, the GPL license force the committers to ensure this application will be free of use, thus
// if you do any modification you will be required to provide it for free unless you use it for personal use (you may 
// charge yourself if you want), bare in mind that you will be required to provide a copy of the license terms that ensures
// this program will be open sourced and all its derivated work will be too.
// *********************************************************************************************************************

#include "logger.h"
#include "stringfunctions.h"

#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include "settings.h"
#include "defs.h"
#ifndef WINDOWS
	#include <syslog.h>
#else
#if WINDOWS_SERVICE
	#using <mscorlib.dll> 
	#include <vcclr.h> 
	using namespace System; 

	struct WinString {
		gcroot<String ^> str;

		WinString(const char* c) {
			str = gcnew String(c);
		}

		~WinString() {
			delete str;
		}
	};

	struct LogWrapper {
		static gcroot<System::Diagnostics::EventLog ^> log;
		LogWrapper() {
		}

		~LogWrapper() {
		}

		static void writeLog(const char* ctype, const char* c) {
			WinString sLogEntry(c);
			
			System::Diagnostics::EventLogEntryType type;
			if (strcmp(ctype, "DEBUG") == 0) {
				type = System::Diagnostics::EventLogEntryType::Information;
			} else if (strcmp(ctype, "INFO") == 0) {
				type = System::Diagnostics::EventLogEntryType::Information;
			} else if (strcmp(ctype, "WARN") == 0) {
				type = System::Diagnostics::EventLogEntryType::Warning;
			} else if (strcmp(ctype, "ERROR") == 0) {
				type = System::Diagnostics::EventLogEntryType::Error;
			}
			System::Diagnostics::EventLog::WriteEntry("djondb", sLogEntry.str, type);
		}
	};
#endif

#endif

#include <boost/algorithm/string.hpp>

Logger::Config* Logger::_configSettings;

Logger* __logger = NULL;

#define PRINT(TYPE, CLAZZ) \
	const char* cmessage = message.c_str(); \
	int log_Print_bufferSize = 10000; \
	char* log_Print_buffer = (char*)malloc(log_Print_bufferSize + 1); \
	memset(log_Print_buffer, 0, log_Print_bufferSize + 1); \
va_list args; \
va_start (args, message); \
vsprintf (log_Print_buffer, cmessage, args); \
va_end(args); \
std::string result; \
std::stringstream ss; \
ss << log_Print_buffer; \
result = ss.str(); \
free(log_Print_buffer); \
print(TYPE, result);

timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp; 
} 

Logger* getLogger(void* clazz) {
	if (__logger == NULL) {
		__logger = new Logger(clazz);

	}
	return __logger;
}

Logger::Logger(void* clazz) {
	m_clazz = clazz;
	_timerRunning = false;
	if (_configSettings == NULL) {
		// this will be readed from a configuration file
		// but right now it'll be hardcoded by config.h
		bool debug = false;
		std::string debug_conf = getSetting("debug");
		if (boost::iequals(debug_conf, std::string("true"))) {
			debug = true;
		} else {
			debug = false;
		}

		std::string logLevel = getSetting("loglevel");
		int detail = 0;
		if (debug && (logLevel.length() > 0)) {
			detail = atoi(logLevel.c_str());
			if (detail > 3) {
				warn("loglevel is greater than 3, adjusted to be equals to 3");
				detail = 3;
			}
			if (detail < 0) {
				warn("loglevel is less than 0, adjusted to be equals to 0");
				detail = 0;
			}
		}
		_configSettings = new Logger::Config();
		_configSettings->m_debug = debug;
		_configSettings->m_warn = true;
		_configSettings->m_info = true;
		_configSettings->_detail = detail;
	}
}

Logger::~Logger() {
}

void Logger::print(std::string type, std::string text) {

#ifndef WINDOWS
	if (isDaemon()) {
		syslog(LOG_DEBUG, text.c_str());
	} else {
		pthread_t thread = pthread_self();
		printf("%s:%lx: %s\n", type.c_str(), thread, text.c_str());
		//cout << type << ":" << hex << thread << ":" << text << endl;
	}
#else
#ifdef WINDOWS_SERVICE
	LogWrapper::writeLog(type.c_str(), text.c_str());
#else
		cout << type << ": " << text << endl;
#endif
#endif
}

/*
	std::string format(const char * message, ...) {
	char* buffer = (char*)malloc(1000);
	memset(buffer, 0, 1000);
	va_list args;
	va_start (args, message);
	vsprintf (buffer,message, args);
	va_end(args);
	std::string result;
	std::stringstream ss;
	ss << buffer;
	free(buffer);
	}
	*/

void Logger::debug(string message, ...) {
	// default debug behaviour is maximum detail
	if (_configSettings->_detail >= 3) {
		PRINT("DEBUG", m_clazz);
	}
}

void Logger::debug(int detail, string message, ...) {
	if (detail <= _configSettings->_detail) {
		PRINT("DEBUG", m_clazz);
	}
}

void Logger::info(string message, ...) {
	PRINT("INFO", m_clazz);
}


void Logger::warn(string message, ...) {
	PRINT("WARN", m_clazz);
}


void Logger::error(string message, ...) {
	PRINT("ERROR", m_clazz);
}

void Logger::error(exception ex) {
	cout << m_clazz << ":" << ex.what() << endl;
}

bool Logger::isDebug() {
	return _configSettings->m_debug;
}

bool Logger::isInfo() {
	return _configSettings->m_info;
}

bool Logger::isWarn() {
	return _configSettings->m_warn;
}

void Logger::startTimeRecord() {
	int interval = 0;
	_timerRunning = true;
#ifdef LINUX
	interval = CLOCK_REALTIME;// CLOCK_PROCESS_CPUTIME_ID;
#endif

	clock_gettime(interval, &_ts1);
}

void getCurrentTime(struct timespec* ts) {
#ifdef LINUX
	int interval = CLOCK_REALTIME;// CLOCK_PROCESS_CPUTIME_ID;
#else
	int interval = 0;// CLOCK_PROCESS_CPUTIME_ID;
#endif
	clock_gettime(interval, ts);
}

void Logger::stopTimeRecord() {
	_timerRunning = false;
	getCurrentTime(&_ts2);
}

DTime Logger::recordedTime() {
	struct timespec ts;
	if (_timerRunning) {
		getCurrentTime(&ts);
	} else {
		ts = _ts2;
	}
	timespec etime = diff(_ts1, ts);
	double secs = etime.tv_sec + ((double)etime.tv_nsec / 1000000000.0);

	DTime result(secs);

	return result;
}
