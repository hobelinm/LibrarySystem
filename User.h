/******************************************************************************
* User Class <User.h>:
* This class represents a user on the library systems
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "Object.h"
#include "ErrorDefinition.h"

#ifndef USER_H
#define USER_H
#define CMD_SEPARATOR " "
#define ALT_SEPARATOR ","

class User : public Object
{
public:
    User();   // Default constructor
    virtual ~User();  // Default destructor
    virtual Object* create() const = 0;
    // Inherited comparison methods
    virtual bool operator==(const Object &obj) const = 0;
    virtual bool operator!=(const Object &obj) const = 0;
    virtual bool operator<(const Object &obj) const = 0;
    virtual bool operator<=(const Object &obj) const = 0;
    virtual bool operator>(const Object &obj) const = 0;
    virtual bool operator>=(const Object &obj) const = 0;
    // Pure virtual method to force initialization of the object
    virtual bool populate(std::string) = 0;
    // TODO: Add setters and getters pure virtual to force implementation
protected:
    // Protected data members
    std::string type;
    std::string firstName;
    std::string lastName;
    std::string userId; // Comparison criteria
    std::string street;
    std::string city;
    std::string phone;
    std::string email;
};

#endif
