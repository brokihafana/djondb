#ifndef FINDCOMMAND_H
#define FINDCOMMAND_H

#include "command.h"
#include "bson.h"
#include <vector>

class FindCommand : public Command
{
    public:
        /** Default constructor */
        FindCommand();
        /** Default destructor */
        virtual ~FindCommand();
        /** Copy constructor
         *  \param other Object to copy from
         */
        FindCommand(const FindCommand& other);

        virtual void execute();
        virtual void* result();

        virtual void writeResult(OutputStream* out) const;

        void setDB(const std::string& db);
        const std::string* DB() const;
        void setNameSpace(const std::string& ns);
        std::string* nameSpace() const;
        void setBSON(BSONObj bson);
        BSONObj* bson() const;
    protected:
    private:
    private:
        std::string* _namespace;
        std::string* _db;
        BSONObj* _bson;

		  std::vector<BSONObj*> _result;
};

#endif // FINDCOMMAND_H
