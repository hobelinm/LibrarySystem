/******************************************************************************
* Library Manager <LibraryManager.h>:
* This class manages multiple libraries, and routes the appropriate commands to
* each library
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
#include "HashTable.h"
#include "ErrorDefinition.h"

#ifndef  LIBMAN_H
#define  LIBMAN_H
// TODO: Move this define to User Collection class:
#define USERID_MAX 9999

class LibraryManager 
{
public:
    LibraryManager();                     // Default constructor
    ~LibraryManager();                    // Defaul destructor
    bool AddBranch(std::string branchId); // Add a new library branch
    bool isEmpty();                       // Tells whether are or not libraries
    // *** Parse Resources *** //
    bool parseResource(std::string library, std::ifstream &input);
    bool parseResource(std::string library, std::string command);
    // *** Parse Users *** //
    bool parseUser(std::string library, std::ifstream &intput);
    bool parseUser(std::string library, std::string command);
    // *** Parse Commands *** //
    bool parseCommand(std::string library, std::ifstream &input);
    bool parseCommand(std::string library, std::string command);
    // TODO: Add LibraryManager destructor
    // TODO: Add reset libraries
private:
    bool isEmptyVar;
    //Library libraryObj; // TODO: DEBUG - Replace with hashTable<Library>
    HashTable libraries;
    // TODO: Instanciate further object classes
};

#endif
