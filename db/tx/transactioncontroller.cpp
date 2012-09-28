/*
 * =====================================================================================
 *
 *       Filename:  transactioncontroller.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2012 08:26:29 PM
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
#include "transactioncontroller.h"

TransactionController(DBController* dbcontroller) {
	_dbcontroller = dbcontroller;
}

TransactionController(const TransactionController& orig) {
	this->_dbcontroller = orig._dbcontroller;
}

~TransactionController() {

}


BSONObj* insert(char* db, char* ns, BSONObj* bson) {

}

bool dropNamespace(char* db, char* ns) {

}

void update(char* db, char* ns, BSONObj* bson) {

}

void deleteRecord(char* db, char* ns, const std::string& documentId, const std::string& revision) {

}

std::vector<BSONObj*>* find(char* db, char* ns, const char* select, const char* filter) throw (ParseException) {

}

BSONObj* findFirst(char* db, char* ns, const char* select, const char* filter) throw (ParseException) {

}

BSONObj* readBSON(StreamType* stream) {

}

std::vector<std::string>* dbs() const {

}

std::vector<std::string>* namespaces(const char* db) const {

}
