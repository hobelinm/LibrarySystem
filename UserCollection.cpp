/******************************************************************************
* User Collection Class <UserCollection.cpp>:
* This class manages all users and their inner operations
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "UserCollection.h"

using namespace std;

// *** User Collection Constructor *** //
UserCollection::UserCollection() 
{
    // Constructor method, add available user types to
    // user factory hash, so we can retrieve them later
    userFactory.add("PATRON", new Patron);
    userFactory.add("LIBRARIAN", new Librarian);
    // Construct user types
    string userTypes[] = USERS;
    // Create the slots in the user list
    for(int i = 0; i < USER_TYPES; i++) {
        userList.add(userTypes[i], (new HashTable)); }
}

// *** User Collection Destructor *** //
UserCollection::~UserCollection()
{
    // Destructor method
}

// *** Add a user to the collection *** //
bool UserCollection::addUser(string cmd)
{
    // Get the appropriate user type
    User *userType = static_cast<User *>(userFactory[userHash(cmd)]);
    // Get a new user
    User *nUser = static_cast<User *>(userType->create());
    string key = nUser->populate(cmd);
    if(key == "") {
        delete nUser;
        cout << ERROR_24 << endl;
        cout << "--> At " << MID_35 << endl;
        return false; }
    // Get the proper list to insert
    HashTable *hashTable = static_cast<HashTable *>
        (userList[userHash(key)]);
    if(hashTable == NULL) {
        delete nUser;
        cout << FATAL_ERROR3 << endl;
        cout << "--> At " << MID_42 << endl;
        return false; }
    // Add user into the user list
    hashTable->add(key, nUser);

    return true;
}

// *** User Hash determine which element to create *** //
// This method assumes that userId has been already validated
// Note: If more tpes of users were to be added, edit this method for
// adding the proper selection criteria
string UserCollection::userHash(string userId) const 
{
    if(userId.size() <= 0) {
        cout << ERROR_23 << endl;
        cout << "--> At " << MID_34 << endl;
        return ""; }

    string userTypes[] = USERS;
    int id = userId[0] - '0'; // Take the first letter
    if(id != 0) {
        id = 1; }
    
    return userTypes[id];
}

User* UserCollection::getUser(string userId) const
{
    if(userId.size() != RESOURCE_SIZE) {
        cout << ERROR_23 << endl;
        cout << "--> At " << MID_43 << endl;
        return NULL; }
    // Get the type of user:
    HashTable *hashTable = static_cast<HashTable *>
        (userList[userHash(userId)]);
    return static_cast<User *>(hashTable->retrieve(userId));
}

