/******************************************************************************
* Error Definition <ErrorDefinition.h>:
* This header is used for storing all types of errors and their relaitonships,
* this design allows for an easy lookup of all error codes and their
* descriptions
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#ifndef ERRORDEF_H
#define ERRORDEF_H

#define ERROR_1 "-> ERROR: Invalid resource identifier: "
#define ERROR_2 "-> ERROR: String cannot be converted to integer: "
#define ERROR_3 "-> ERROR: User Id does not comply with length requirements: "
#define ERROR_4 "-> ERROR: Input cannot be null"
#define ERROR_5 "-> ERROR: String command cannot be empty"
#define ERROR_6 "-> ERROR: String branchId cannot be empty"
#define ERROR_7 "-> ERROR: String library cannot be empty"
#define ERROR_8 "-> ERROR: Invalid user name"
#define ERROR_9 "-> ERROR: Invalid type in resource command"
#define ERROR_10 "-> ERROR: Integer cannot be less than 0"
#define ERROR_11 "-> ERROR: Integer month is not between 1 and 12"
#define ERROR_12 "-> ERROR: String title cannot be empty"
#define ERROR_13 "-> ERROR: Command has missing data title/author, title/genre"
#define ERROR_14 "-> ERROR: Object cannot be null"
#define ERROR_15 "-> ERROR: Library object already on libraries HashTable"
#define ERROR_16 "-> ERROR: String key cannot be empty"
#define ERROR_17 "-> ERROR: HashTable Object* value cannot be NULL"
#define ERROR_18 "-> ERROR: Value already exists in HashTable"
#define ERROR_19 "-> ERROR: HashTable is empty"
#define ERROR_20 "-> ERROR: Selected Library does not exist in hash table"
#define ERROR_21 "-> ERROR: This object has not been initialized"
#define ERROR_22 "-> ERROR: Parameter object has not been initialized"
#define ERROR_23 "-> ERROR: String userId cannot be null"
#define ERROR_24 "-> ERROR: Invalid user construction string"

// Fata Errors, errors that should not occur
#define FATAL_ERROR1 "-> FATAL ERROR: Duplicate key not caught by HashTable::Retrieve"
#define FATAL_ERROR2 "-> FATAL ERROR: End of trie is not null"

// Method ids
#define MID_1 "bool Library::parseResource(string command)"
#define MID_2 "bool Library::parseUser(string command)"
#define MID_3 "bool LibraryManager::parseResource(string library, ifstream &input)"
#define MID_4 "bool LibraryManager::parseResource(string library, string command)"
#define MID_5 "bool LibraryManager::parseUser(string library, ifstream &input)"
#define MID_6 "bool LibraryManager::parseUser(string library, string command)"
#define MID_7 "bool LibraryManager::parseCommand(string library, ifstream &input)"
#define MID_8 "bool LibraryManager::parseCommand(string library, string command)"
#define MID_9 "bool LibraryManager::AddBranch(string branchId)"
#define MID_10 "bool Library::parseResource(ifstream &input)"
#define MID_11 "bool Library::parseUser(ifstream &input)"
#define MID_12 "bool Library::operator==(const Object &obj) const"
#define MID_13 "bool Library::operator!=(const Object &obj) const"
#define MID_14 "bool Library::operator<(const Object &obj) const"
#define MID_15 "bool Library::operator<=(const Object &obj)const"
#define MID_16 "bool Library::operator>(const Object &obj) const"
#define MID_17 "bool Library::operator>=(const Object &obj) const"
#define MID_18 "Object* HashTable::operator[](string key) const"
#define MID_19 "Object* HashTable::retrieve(string key) const"
#define MID_20 "Object* HashTable::remove(string key)"
#define MID_21 "bool HashTable::add(std::string key, const Object* value)"
#define MID_22 "bool Patron::operator==(const Object &obj) const"
#define MID_23 "bool Patron::operator!=(const Object &obj) const"
#define MID_24 "bool Patron::operator<(const Object &obj) const"
#define MID_25 "bool Patron::operator<=(const Object &obj) const"
#define MID_26 "bool Patron::operator>(const Object &obj) const"
#define MID_27 "bool Patron::operator>=(const Object &obj) const"
#define MID_28 "bool Librarian::operator==(const Object &obj) const"
#define MID_29 "bool Librarian::operator!=(const Object &obj) const"
#define MID_30 "bool Librarian::operator<(const Object &obj) const"
#define MID_31 "bool Librarian::operator<=(const Object &obj) const"
#define MID_32 "bool Librarian::operator>(const Object &obj) const"
#define MID_33 "bool Librarian::operator>=(const Object &obj) const"
#define MID_34 "string UserCollection::userHash(string userId) const"
#define MID_35 "bool UserCollection::addUser(string cmd)"
#define MID_36 "bool HashTable::operator==(const Object &obj) const"
#define MID_37 "bool HashTable::operator!=(const Object &obj) const"
#define MID_38 "bool HashTable::operator<(const Object &obj) const"
#define MID_39 "bool HashTable::operator<=(const Object &obj) const"
#define MID_40 "bool HashTable::operator>(const Object &obj) const"
#define MID_41 "bool HashTable::operator>=(const Object &obj) const"

// Some notes
#define NOTE1 "+ 1 accounts for the space following the word"

#endif
