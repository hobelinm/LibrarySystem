/******************************************************************************
* User Collection Class <UserCollection.h>:
* This class manages all users and their inner operations
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "HashTable.h"
#include "User.h"

#ifndef USER_COLLECTION_H
#define USER_COLLECTION_H

#define USERID_MAX 9999
#define USERID_MIN 0
#define USERS {"PATRON", "LIBRARIAN"}

class UserCollection 
{
public:
    UserCollection();  // Default Constructor
    ~UserCollection(); // Default Destructor
    bool addUser(std::string cmd); // Add a new user to the system

private:
    HashTable userFactory;
};

#endif
