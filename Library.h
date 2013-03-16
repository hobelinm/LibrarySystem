/******************************************************************************
* Library <Library.h>:
* This class performs basic validation over commands and call the proper object
* in order to perform the selected function
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Object.h"
#include "UserCollection.h"
#include "ResourceCollection.h"
#include "TransactionCollection.h"

#include "ErrorDefinition.h"

#ifndef LIB_H
#define LIB_H

class Library : public Object
{
public:
    Library();               // Default constructor
    Library(std::string id); // Additional constructor
    ~Library();              // Default destructor
    // Inherited comparison methods
    virtual bool operator==(const Object &obj) const;
    virtual bool operator!=(const Object &obj) const;
    virtual bool operator<(const Object &obj) const;
    virtual bool operator<=(const Object &obj) const;
    virtual bool operator>(const Object &obj) const;
    virtual bool operator>=(const Object &obj) const;
    /* Create a new instance of this object */
    virtual Object* create() const;
    /* Retrieve the id for this library */
    std::string getID() const;
    /* Parse Resources */
    bool parseResource(std::ifstream &input);
    bool parseResource(std::string command);
    /* Parse Users */
    bool parseUser(std::ifstream &input);
    bool parseUser(std::string command);
    /* Parse Commands */
    bool parseCommand(std::ifstream &input);
    bool parseCommand(std::string command);
    // TODO: Add resetLibrary
protected:
    // Utility methods
    std::string trimString(std::string value);
    bool testNumber(std::string number) const;
    std::string fixString(std::string resource) const;
    // Private data members
    std::string libraryName;
    UserCollection userCollection; // Stores the users
    ResourceCollection resourceCollection; // Stores the resources
    TransactionCollection transactionCollection; // Stores the transactions
};

#endif

