/******************************************************************************
* User Collection Class <UserCollection.h>:
* This class manages all users and their inner operations
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "Object.h"
#include "ErrorDefinition.h"
#include "HashTable.h"
#include "User.h"
#include "Patron.h"
#include "Librarian.h"

#ifndef USER_COLLECTION_H
#define USER_COLLECTION_H

#define USERID_MAX 9999
#define USERID_MIN 0
#define USER_TYPES 2 // Number of types of users
#define USERS {"LIBRARIAN", "PATRON"}
#define SELECTOR_DIVISOR 1000

class UserCollection 
{
public:
    UserCollection();  // Default Constructor
    ~UserCollection(); // Default Destructor
    bool addUser(std::string cmd); // Add a new user to the system

private:
    // Private Data members //
    HashTable userFactory;
    HashTable userList;
    // Private function members //
    std::string userHash(string userId) const; // Determines type of user
};

#endif
