/******************************************************************************
* Library <Library.cpp>:
* This class performs basic validation over commands and call the proper object
* in order to perform the selected function
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <sstream>
#include "Library.h"

using namespace std;
// *** Default Constructor *** //
Library::Library() : Object()
{
    // For comparison purposes:
    libraryName = "";
}

// *** Additional Constructor *** //
Library::Library(string id) : Object() 
{
    libraryName = id;
}

// *** Default Destructor *** //
Library::~Library()
{
    // TODO: Complete this
}

// *** Inherited Operators Implementation *** //
Object* Library::create() const 
{
    return new Library;
}

bool Library::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_12 << endl; 
        return false; }
    const Library &libraryItem = static_cast<const Library&>(obj);
    return (this->libraryName.compare(libraryItem.libraryName) == 0);
}

bool Library::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_13 << endl;
        return true; } // Distinc by default since 'this' is initialized
    return !this->operator==(obj);
}

bool Library::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_14 << endl;
        return false; }
    const Library &libraryItem = static_cast<const Library&>(obj);
    return (this->libraryName.compare(libraryItem.libraryName) < 0);
}

bool Library::operator<=(const Object &obj)const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_15 << endl;
        return false; }
    const Library &libraryItem = static_cast<const Library&>(obj);
    return (this->libraryName.compare(libraryItem.libraryName) <= 0);
}

bool Library::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_16 << endl;
        return false; }
    const Library &libraryItem = static_cast<const Library&>(obj);
    return (this->libraryName.compare(libraryItem.libraryName) > 0);
}

bool Library::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_17 << endl;
        return false; }
    const Library &libraryItem = static_cast<const Library&>(obj);
    return (this->libraryName.compare(libraryItem.libraryName) >= 0);
}

// *** Retrieve the ID for this library *** //
string Library::getID() const
{
    return libraryName;
}

// *** Parse an ifstream Resource *** //
bool Library::parseResource(ifstream &input)
{
    if(input == NULL) { // Initial validation
        cout << ERROR_4 << endl;
        cout << "--> At " << MID_10 << endl;
        return false; } 
    bool result = true;
    string command;
    
    while(!input.eof()) {
        getline(input, command);
        result = parseResource(command) && result; }

    return result;
}

// *** Parse a custom string Resource command *** //
bool Library::parseResource(string command)
{
    if(command == "") { 
        cout << ERROR_5 << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    cout << command << endl; // TODO: DEBUG - Remove
    command = trimString(command); // Remove white spaces at the end if any
    // Parse Resource from string 
    string resourceType(command.substr(0, command.find_first_of(" ")));
    // Test for type size
    if((resourceType.size() > RESOURCETYPE_ID_SIZE) 
        || (resourceType.size() == 0)) {
        cout << ERROR_1 << endl;
        cout << "--> At resourceType <" << resourceType << ">" << endl;
        cout << "---> At string<" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    // Validate resourceType
    bool isValidType = false;
    string resourceTypeValues[RESOURCE_TYPES_N] = RESOURCE_TYPES;
    for(int typeIdx = 0; typeIdx < RESOURCE_TYPES_N; typeIdx++) {
        if(resourceTypeValues[typeIdx] == resourceType) {
            isValidType = true;
            break; } }

    if(!isValidType) {
        cout << ERROR_9 << endl;
        cout << "--> At resourceType <" << resourceType << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    // Validate Year
    string resource(command.substr(
        RESOURCETYPE_ID_SIZE + 1, // See NOTE1
        command.size() - RESOURCETYPE_ID_SIZE));
    string year(resource.substr(
        resource.find_last_of(" ") + 1, // See NOTE1
        resource.size() - resource.find_last_of(" ")));
    int iYear;
    char leftOver;
    istringstream yearStream(year);
    if(!(yearStream >> iYear) || (yearStream.get(leftOver))) {
        cout << ERROR_2 << endl;
        cout << "--> At year <" << year << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    // Validate year as number > 0
    if(iYear <= 0) {
        cout << ERROR_10 << endl;
        cout << "--> At year <" << year << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    // TODO: Parse rest of the resource format
    // Every resource has two commas, except for Publication 'P'
    if((resourceType == "P") || (resourceType == "p")) {
        string month = resource.substr(
            resource.find_last_of(",") + 2, // Comma plus space
            string::npos);
        month = month.substr(0, month.find_first_of(" "));
        // Turn month into int
        int iMonth;
        istringstream monthStream(month);
        if(!(monthStream >> iMonth) || monthStream.get(leftOver)) {
            cout << ERROR_2 << endl;
            cout << "--> At month <" << month << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_1 << endl; }
        
        // Validate the actual month
        if((iMonth <= 0) || (iMonth > 12)) {
            cout << ERROR_11 << endl;
            cout << "--> At month <" << month << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_1 << endl; }

        // Validate title not empty
        string title = trimString(resource.substr(0,
            resource.find_first_of(",")));
        if(title.size() <= 0) {
            cout << ERROR_12 << endl;
            cout << "--> At title <" << title << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_1 << endl; }
    } else { // Test for Empty Title, Author
        if((resource.find_first_of(",") == 0) ||
            (resource.find_first_of(",") == resource.find_last_of(","))) {
            cout << ERROR_13 << endl;
            cout << "--> At resource <" << resource << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_1 << endl; } }

    // Extensibility note: Add more custom validation commands here if desired
    
    // TODO: Call resourceCollection.Add(command);

    return true;
}

// *** Parse an ifstream User *** // 
bool Library::parseUser(ifstream &input)
{
    if(input == NULL) { 
        cout << ERROR_4 << endl;
        cout << "----> At " << MID_11 << endl;
        return false; }
    bool result = true;
    string command;

    while(!input.eof()) {
        getline(input, command);
        result = result && parseUser(command); }

    return true;
}

// *** Parse a custom string User command *** //
bool Library::parseUser(string command)
{
    cout << command << endl; // TODO: DEBUG - Remove
    if(command == "") { 
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_2 << endl;
        return false; }
    int iUserId;
    char leftOver;
    string sUserId(command.substr(0, command.find_first_of(" ")));

    // Parse user from string
    istringstream strUserId(sUserId);
    if(!(strUserId >> iUserId) || strUserId.get(leftOver)) {
        cout << ERROR_2 << endl;
        cout << "--> At sUserId <" << sUserId << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_2 << endl;
        return false; }

    // Check 0<=integer<9999 as final validation
    if((iUserId <= 0) || (iUserId > USERID_MAX)) {
        cout << ERROR_3 << endl;
        cout << "--> At User Id <" << iUserId << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_2 << endl;
        return false; }

    // The rest of the string can be considered to be OK for user name
    // Test for empty strings for first and last name
    if(0 == (command.size() - sUserId.size())) {
        cout << ERROR_8 << endl;
        cout << "--> At string <" << command << ">" << endl;
        cout << "---> At " << MID_2 << endl;
        return false; }

    // TODO: Call userCollection to implement the command
    return true;
}

// *** Parse an ifstream command *** //
bool Library::parseCommand(ifstream &input)
{
    bool result = true;
    string command;
    cout << "* COMMANDS *" << endl;

    while(!input.eof()) {
        getline(input, command);
        result = result && parseCommand(command); }

    return true;
}

// *** Parse a custom string command *** //
bool Library::parseCommand(string command)
{
    if(command == "") { return false; }
    cout << command << endl; // TODO: DEBUG - Remove
    // TODO: Validate action
    // TODO: Call the appropriate object

    return true;
}

// *** Trim spaces at the end if any *** //
string Library::trimString(string value)
{
    int endVal = value.find_last_not_of(" ") + 1;
    return value.substr(0, endVal);
}
