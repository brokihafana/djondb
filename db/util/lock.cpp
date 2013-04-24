/*
 * =====================================================================================
 *
 *       Filename:  lock.cpp
 *
 *    Description:  Thread Lock implementation
 *
 *        Version:  1.0
 *        Created:  12/05/2012 10:32:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Juan Pablo Crossley (Cross), crossleyjuan@gmail.com
 *   Organization:  djondb
 *
 * This file is part of the djondb project, for license information please refer to the LICENSE file,
 * the application and libraries are provided as-is and free of use under the terms explained in the file LICENSE
 * Its authors create this application in order to make the world a better place to live, but you should use it on
 * your own risks.
 * 
 * Also, be adviced that, the GPL license force the committers to ensure this application will be free of use, thus
 * if you do any modification you will be required to provide it for free unless you use it for personal use (you may 
 * charge yourself if you want), bare in mind that you will be required to provide a copy of the license terms that ensures
 * this program will be open sourced and all its derivated work will be too.
 * =====================================================================================
 */
#include "lock.h"
#include "logger.h"

Lock::Lock() {
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&_mutexLock, &mutexattr);
	
	pthread_cond_init(&_cond, NULL);
}

Lock::~Lock() {
	pthread_mutex_destroy(&_mutexLock);
	pthread_cond_destroy(&_cond);
}

void Lock::lock() {
	Logger* log = getLogger(NULL);
	if (log->isDebug()) log->debug(3, "Lock::lock() %d", (long)this);
	pthread_mutex_lock(&_mutexLock);
}

void Lock::unlock() {
	Logger* log = getLogger(NULL);
	if (log->isDebug()) log->debug(3, "Lock::unlock() %d", (long)this);
	pthread_mutex_unlock(&_mutexLock);
}

void Lock::wait() {
	pthread_cond_wait(&_cond, &_mutexLock);
}

void Lock::wait(__int32 timeout) {
	struct timespec timeToWait;
	time_t now;
	int rt;

	time(&now);

	timeToWait.tv_sec = now+timeout;
	pthread_cond_timedwait(&_cond, &_mutexLock, &timeToWait);
}

void Lock::notify() {
	pthread_cond_signal(&_cond);
}