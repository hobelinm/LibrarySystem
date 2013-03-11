/******************************************************************************
* Library Manager <LibraryManager.cpp>:
* This class manages multiple libraries, and routes the appropriate commands to
* each library
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "LibraryManager.h"

using namespace std;

// *** Default Constructor *** //
LibraryManager::LibraryManager()
{
    isEmptyVar = true;
}

// *** Default Destructor *** //
LibraryManager::~LibraryManager()
{
    // TODO: Destroy hashTable<library>
    isEmptyVar = true;
}

// *** Check if the library is empty *** //
bool LibraryManager::isEmpty()
{
    return isEmptyVar;
}

// *** Add a new library to the collection *** //
bool LibraryManager::AddBranch(string branchId)
{
    if("" == branchId) { // Initial validation
        cout << ERROR_6 << endl;
        cout << "--> At " << MID_9 << endl;
        return false; }
    isEmptyVar = false;
    // add a new branch to the library hash
    if(libraries[branchId] != NULL) {
        cout << ERROR_15 << endl;
        cout << "--> At " << MID_9 << endl;
        return false; }
    return libraries.add(branchId, new Library(branchId));
}

// *** Parse an ifstream Resource *** //
bool LibraryManager::parseResource(string library, ifstream &input)
{
    if(input == NULL) { // Initial validation
        cout << ERROR_4 << endl;
        cout << "--> At " << MID_3 << endl;
        return false; } 
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_3 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *libraryLocation = static_cast<Library *>(libraries[library]);
    if(libraryLocation == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_3 << endl;
        return false; }
    
    return libraryLocation->parseResource(input);
}

// *** Parse a custom string Resource command *** //
bool LibraryManager::parseResource(string library, string command)
{
    if(command == "") { // Initial validation
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_4 << endl;
        return false; }
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_4 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *libraryLocation = static_cast<Library *>(libraries[library]);
    if(libraryLocation == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_4 << endl;
        return false; }
    return libraryLocation->parseResource(command);
}

// *** Parse an ifstream User *** // 
bool LibraryManager::parseUser(string library, ifstream &input)
{
    if(input == NULL) { // Initial validation
        cout << ERROR_4 << endl;
        cout << "--> At " << MID_5 << endl;
        return false; }
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_5 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *lib = static_cast<Library *>(libraries[library]);
    if(lib == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_5 << endl;
        return false; }

    // If library exists, call parseUser method
    return lib->parseUser(input);
}

// *** Parse a custom string User command *** //
bool LibraryManager::parseUser(string library, string command)
{
    if(command == "") { // Initial validation
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_6 << endl;
        return false; }
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_6 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *lib = static_cast<Library *>(libraries[library]);
    if(lib == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_6 << endl;
        return false; }

    // If library exists, call parseUser method
    return lib->parseUser(command);
}

// *** Parse an ifstream command *** //
bool LibraryManager::parseCommand(string library, ifstream &input)
{
    if(input == NULL) { // Initial validation
        cout << ERROR_4 << endl;
        cout << "--> At " << MID_7 << endl;
        return false; }
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_7 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *lib = static_cast<Library *>(libraries[library]);
    if(lib == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_7 << endl;
        return false; }
    
    // If library exists, call parseCommand method
    return lib->parseCommand(input);
}

// *** Parse a custom string command *** //
bool LibraryManager::parseCommand(string library, string command)
{
    if(command == "") { // Initial validation 
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_8 << endl;
        return false; }
    if("" == library) {
        cout << ERROR_7 << endl;
        cout << "--> At " << MID_8 << endl;
        return false; }
    
    // Retrieve 'library' from library hash
    Library *lib = static_cast<Library *>(libraries[library]);
    if(lib == NULL) {
        cout << ERROR_20 << endl;
        cout << "--> At string library <" << library << ">" << endl;
        cout << "---> At " << MID_8 << endl;
        return false; }
    
    // If library exists, call parseCommand method
    return lib->parseCommand(command);
}

