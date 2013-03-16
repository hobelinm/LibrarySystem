/******************************************************************************
* Display Transaction class <DisplayTransaction.h>:
* This class implements display operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "Transaction.h"
#include "ResourceCollection.h"

#ifndef DISPLAYTRANSACTION_H
#define DISPLAYTRANSACTION_H

class DisplayTransaction : public Transaction
{
public:
    DisplayTransaction(); // Default constructor
    virtual ~DisplayTransaction(); // Default destructor
    virtual void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *res) const;
    virtual Object* create() const;
};

#endif

