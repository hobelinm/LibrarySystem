/******************************************************************************
* Patron Class <Patron.h>:
* This class is used to represent library patron's 
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "User.h"

#ifndef PATRON_H
#define PATRON_H
#define USER_TYPE "PATRON"

class Patron : public User 
{
public:
    Patron();          // Default constructor
    virtual ~Patron(); // Default destructor
    // Inherited methods
    virtual Object* create() const;
    virtual bool operator==(const Object&) const;
    virtual bool operator!=(const Object&) const;
    virtual bool operator<(const Object&) const;
    virtual bool operator<=(const Object&) const;
    virtual bool operator>(const Object&) const;
    virtual bool operator>=(const Object&) const;
    virtual bool populate(std::string cmd);
    // TODO: Add getters and setters and implement them
protected:
    // Private data members:
    bool isInitialized;
};

#endif