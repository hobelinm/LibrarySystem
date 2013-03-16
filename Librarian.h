/******************************************************************************
* Librarian Class <Librarian.h>:
* This class is used to represent library librarian's 
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include <iostream>
#include "ErrorDefinition.h"
#include "User.h"

#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#define LIBRARIAN_TYPE "LIBRARIAN"

class Librarian : public User 
{
public:
    Librarian();          // Default constructor
    virtual ~Librarian(); // Default destructor
    // Inherited methods
    virtual Object* create() const;
    virtual bool operator==(const Object&) const;
    virtual bool operator!=(const Object&) const;
    virtual bool operator<(const Object&) const;
    virtual bool operator<=(const Object&) const;
    virtual bool operator>(const Object&) const;
    virtual bool operator>=(const Object&) const;
    virtual std::string populate(std::string cmd);
    virtual std::string getType() const;
    virtual std::string getUserId() const;
    virtual std::string getFirstName() const;
    virtual std::string getLastName() const;
    virtual std::string getStreet() const;
    virtual std::string getCity() const;
    virtual std::string getPhone() const;
    virtual std::string getEmail() const;
private:
    // Private data members
    bool isInitialized;
};

#endif

