// =====================================================================================
// 
//  @file:  simpleworker.h
// 
//  @brief: This class implements a worker for commands like Shutdown, Commit, show, etc. Commands that will
//  not be enqueue for long time and that are usually executed with maximum priority 
// 
//  @version:  1.0
//  @date:     07/22/2013 10:57:20 AM
//  Compiler:  g++
// 
//  @author:  Juan Pablo Crossley (Cross), cross@djondb.com
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
// =====================================================================================
#ifndef SIMPLEWORKER_INCLUDED_H
#define SIMPLEWORKER_INCLUDED_H 

#include "worker.h"
class InputStream;
class OutputStream;
class Command;

class SimpleWorker: public Worker {
	public:
		SimpleWorker(Command* command, InputStream* input, OutputStream* output);
		SimpleWorker(const SimpleWorker& orig);
		virtual ~SimpleWorker();

		/// @brief This method executes steps in the current taks
		/// the client should check the state to see if the task state
		virtual void resume();

		/// @brief This should return the results of the worker
		/// If the worker is in an invalid state (SLEEP, ABORT, etc) then this will have
		/// an unexpected behavior
		virtual void* result();

		/**
		 * @brief Implements the Chain of responsability, Simple Commands does not required special workers
		 * for their return and it will be handled directly by the command
		 *
		 * @return 
		 */
		virtual Worker* nextActionWorker();

	private:
		Command* _command;
		InputStream* _input;
		OutputStream* _output;
};
#endif /* SIMPLEWORKER_INCLUDED_H */