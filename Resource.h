/******************************************************************************
* Resource Class <Resource.h>:
* This class is an abstract representation for all resources in the library
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <string>
#include "ErrorDefinition.h"
#include "Object.h"

#ifndef RESOURCE_H
#define RESOURCE_H

// Number of letters used for resources
#define RESOURCETYPE_ID_SIZE 1 
// Supported types of resources
#define RESOURCE_TYPES_N 5
#define RESOURCE_TYPES {"F", "P", "Y", "V", "A"}

class Resource : public Object
{
public:
    Resource(); // Default constructor
    virtual ~Resource(); // Default destructor
    virtual Object* create() const = 0;
    // Inherited comparison methods
    virtual bool operator==(const Object &obj) const = 0;
    virtual bool operator!=(const Object &obj) const = 0;
    virtual bool operator<(const Object &obj) const = 0;
    virtual bool operator<=(const Object &obj) const = 0;
    virtual bool operator>(const Object &obj) const = 0;
    virtual bool operator>=(const Object &obj) const = 0;
    // Pure virtual method for forcing initialization
    virtual std::string populate(std::string cmd) = 0;
    // Setters and getters pure virtual
    virtual std::string getType() const = 0;
    virtual std::string getTitle() const = 0;
    virtual std::string getYear() const = 0;
    virtual std::string getMonth() const = 0;
    virtual std::string getAuthor() const = 0;
    virtual std::string getGenre() const = 0;
    virtual std::string getKey() const = 0;
    virtual int getAvailableCopies() const = 0;
    // Resource Functions
    virtual bool checkoutResource(std::string userId) = 0;
    virtual bool returnResource(std::string userId) = 0;
    virtual void print() const = 0;
    virtual void printResource() const = 0;
    
protected:
    // The only fields common to all types of resources
    std::string title;
    std::string year;
    std::string type;
    int availableCopies;
};

#endif

