/******************************************************************************
* Checkout Transaction class <CheckoutTransaction.h>:
* This class implements checkout operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "Transaction.h"
#include "ResourceCollection.h"

#ifndef CHECKOUTTRANSACTION_H
#define CHECKOUTTRANSACTION_H

class CheckoutTransaction : public Transaction
{
public:
    CheckoutTransaction(); // Default constructor
    virtual ~CheckoutTransaction(); // Default destructor
    virtual void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *res) const;
    virtual Object* create() const;
};

#endif

