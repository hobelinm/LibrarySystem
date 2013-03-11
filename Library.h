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
#include "ErrorDefinition.h"

#ifndef LIB_H
#define LIB_H
// *** Definition Section ***
// Supported types of commands
// Letters used for Action commands:
#define ACTION_CMD_S 1
// Number of comments
#define ACTION_CMD_N 8
#define ACTION_CMDS {"C", "D", "H", "R", "A", "Q", "U", "E"}
// TODO: Move this to resource collection class
// Number of letters used for resources
#define RESOURCETYPE_ID_SIZE 1 
// Supported types of resources
#define RESOURCE_TYPES_N 5
#define RESOURCE_TYPES {"F", "P", "Y", "V", "A"}

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
    // TODO: Add private data members
    std::string libraryName;
    UserCollection UserCollection;
};

#endif
