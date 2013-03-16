/******************************************************************************
* Transaction Class <Transaction.cpp>:
* This class is an abstract representation for all transactions in the library
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include "Transaction.h"

using namespace std;

// *** Default Constructor *** //
Transaction::Transaction()
{
    // TODO: Constructor methods
}

// *** Default Destructor *** //
Transaction::~Transaction()
{
    // TODO: Destructor Procedures
}

bool Transaction::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_109 << endl;
        return false; }

    const Transaction &transaction = static_cast<const Transaction &>(obj);
    return (this->cmdId.compare(transaction.cmdId) == 0);
}

bool Transaction::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_110 << endl;
        return true; }
    return !(this->operator==(obj));
}

bool Transaction::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_111 << endl;
        return false; }
    const Transaction &transaction = static_cast<const Transaction &>(obj);
    return (this->cmdId.compare(transaction.cmdId) < 0);
}

bool Transaction::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_112 << endl;
        return false; }
    const Transaction &transaction = static_cast<const Transaction &>(obj);
    return (this->cmdId.compare(transaction.cmdId) <= 0);
}

bool Transaction::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_113 << endl;
        return false; }
    const Transaction &transaction = static_cast<const Transaction &>(obj);
    return (this->cmdId.compare(transaction.cmdId) > 0);
}

bool Transaction::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_114 << endl;
        return false; }
    const Transaction &transaction = static_cast<const Transaction &>(obj);
    return (this->cmdId.compare(transaction.cmdId) >= 0);
}

