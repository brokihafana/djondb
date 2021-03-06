#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include "command.h"
#include "bson.h"

class InsertCommand: public Command {
    public:
        InsertCommand();

        virtual ~InsertCommand();
        InsertCommand(const InsertCommand& orig);


        virtual void execute();
        virtual void* result();
        virtual void writeCommand(OutputStream* out) const;
        virtual void writeResult(OutputStream* out) const;
        virtual void readResult(InputStream* is);

        void setDB(const std::string& db);
        const std::string* DB() const;
        void setNameSpace(const std::string ns);
        const std::string* nameSpace() const;

		  //! Sets the BSONObj to be inserted in the database
		  /*!
			The InsertCommand will get ownership of the parameter, the caller should not delete/free it
			\param bson bson to be inserted
			* */
        void setBSON(BSONObj* bson);
        const BSONObj* bson() const;
    private:
        std::string* _namespace;
        std::string* _db;
        BSONObj* _bson;

        const BSONObj* _bsonResult;
};

#endif // INSERTCOMMAND_H
