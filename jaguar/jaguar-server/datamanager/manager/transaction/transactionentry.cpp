#include "transactionentry.h"

TransactionEntry::TransactionEntry() {

}

TransactionEntry::TransactionEntry(const TransactionEntry& orig) {

}

TransactionEntry::~TransactionEntry() {

}

void TransactionEntry::setValue(void* _value) {
    this->_value = _value;
}

void* TransactionEntry::setValue() const {
    return _value;
}

void TransactionEntry::setIdAttribute(int _idAttribute) {
    this->_idAttribute = _idAttribute;
}

int TransactionEntry::setIdAttribute() const {
    return _idAttribute;
}

void TransactionEntry::setIdEntity(int _idEntity) {
    this->_idEntity = _idEntity;
}

int TransactionEntry::setIdEntity() const {
    return _idEntity;
}

void TransactionEntry::setId(int _id) {
    this->_id = _id;
}

int TransactionEntry::setId() const {
    return _id;
}

