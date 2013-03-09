/******************************************************************************
* Main method:
* This file shows a proposed usage for the library system, the responsibility 
* of main as a user is either load the initialization files and give them to
* the libraries or to send custom strings as commands for all of the libraries
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vld.h>
#include "LibraryManager.h"

using namespace std;

int main ()
{
    // Library execution
    LibraryManager libraries;
    libraries.AddBranch("Bothell Library");
    
    // Load the resource initialization
    string resourceFile = "ResourceInitialization.txt";
    ifstream resources(resourceFile);
    if(!resources)
    {
        cout << "Resource file could not be opened: " << resourceFile << endl;
        return 1;
    }

    // Load user initialization
    string userFile     = "UserInitialization.txt";
    ifstream users(userFile);
    if(!users)
    {
        cout << "User file could not be opened: " << userFile << endl;
        return 1;
    }

    // Run library commands
    string commandFile  = "Commands.txt";
    ifstream commands(commandFile);
    if(!commands)
    {
        cout << "Command file could not be opened: " << commandFile << endl;
        return 1;
    }

    // At this point all files could be opened, start performing operations:
    libraries.parseResource("Bothell Library", resources);
    libraries.parseUser("Bothell Library", users);
    libraries.parseCommand("Bothell Library", commands);

    // Close files
    resources.close();
    users.close();
    commands.close();

    return 0;
}
