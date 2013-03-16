/******************************************************************************
* Print History Transaction class <PrintHistory.h>:
* This class implements user's history print transaction
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "Transaction.h"
#include "User.h"
#include "Resource.h"

#ifndef PRINT_HISTORY_H
#define PRINT_HISTORY_H

class PrintHistory : public Transaction
{
public:
    PrintHistory(); // Default constructor
    virtual ~PrintHistory(); // Default destructor
    virtual void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *resourceCollection) const;
    virtual Object* create() const;
};

#endif
