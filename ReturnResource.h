/******************************************************************************
* Return Resource class <ReturnResource.h>:
* This class implements checkout operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "Resource.h"
#include "Transaction.h"
#include "ResourceCollection.h"

#ifndef RETURN_RESOURCE_H
#define RETURN_RESOURCE_H

class ReturnResource : public Transaction 
{
public:
    ReturnResource();  // Default constructor
    virtual ~ReturnResource(); // Default destructor
    virtual void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *resourceCollection) const;
    virtual Object* create() const;
};

#endif

