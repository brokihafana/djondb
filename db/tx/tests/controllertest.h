/*
 * =====================================================================================
 *
 *       Filename:  controllertest.h
 *
 *    Description:  This is the header file for the DummyController 
 *
 *        Version:  1.0
 *        Created:  12/02/2012 08:17:12 AM
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
#ifndef CONTROLLERTEST_INCLUDED_H
#define CONTROLLERTEST_INCLUDED_H 
#include <vector>
#include <string>
#include "controller.h"
#include "filterdefs.h"
#include "streammanager.h"

class BSONObj;
class BSONArrayObj;
using namespace std;

class DummyController: public Controller
{
	public:
		virtual const BSONObj* insert(const char* db, const char* ns, BSONObj* bson, const BSONObj* options = NULL) ;
		virtual bool dropNamespace(const char* db, const char* ns, const BSONObj* options = NULL) ;
		virtual void update(const char* db, const char* ns, BSONObj* bson, const BSONObj* options = NULL) ;
		virtual void remove(const char* db, const char* ns, const char* documentId, const char* revision, const BSONObj* options = NULL) ;
		virtual DBCursor* const find(const char* db, const char* ns, const char* select, const char* filter, const BSONObj* options = NULL) throw (ParseException) ;
		virtual DBCursor* const fetchCursor(const char* cursorId) ;
		virtual BSONObj* findFirst(const char* db, const char* ns, const char* select, const char* filter, const BSONObj* options = NULL) throw (ParseException) ;
		virtual std::vector<std::string>* dbs(const BSONObj* options = NULL) const ;
		virtual std::vector<std::string>* namespaces(const char* db, const BSONObj* options = NULL) const ;
		virtual void releaseCursor(const char* cursorId) ;
};
#endif /* CONTROLLERTEST_INCLUDED_H */
