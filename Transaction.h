/******************************************************************************
* Transaction Class <Transaction.h>:
* This class is an abstract representation for all transactions in the library
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Object.h"
#include "User.h"
#include "Resource.h"
#include "ResourceCollection.h"

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction : public Object
{
public:
    Transaction(); // Default constructor
    virtual ~Transaction(); // Default destructor
    // Inherited comparison methods
    virtual bool operator==(const Object &obj) const;
    virtual bool operator!=(const Object &obj) const;
    virtual bool operator<(const Object &obj) const;
    virtual bool operator<=(const Object &obj) const;
    virtual bool operator>(const Object &obj) const;
    virtual bool operator>=(const Object &obj) const;
    // Transaction methods
    virtual void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *res) const = 0;
protected:
    std::string cmdId;
};

#endif

