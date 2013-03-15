/******************************************************************************
* Library <Library.cpp>:
* This class performs basic validation over commands and call the proper object
* in order to perform the selected function
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

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
    int iYear = 0;
    
    if(!testNumber(year)) {
        cout << ERROR_2 << endl;
        cout << "--> At year <" << year << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }
    iYear = atoi(year.c_str());

    // Validate year as number > 0
    if(iYear <= 0) {
        cout << ERROR_10 << endl;
        cout << "--> At year <" << year << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_1 << endl;
        return false; }

    // Parse rest of the resource format
    // Every resource has two commas, except for Publication 'P'
    if((resourceType == "P") || (resourceType == "p")) {
        string month = resource.substr(
            resource.find_last_of(",") + 2, // Comma plus space
            string::npos);
        month = month.substr(0, month.find_first_of(" "));
        // Turn month into int
        int iMonth = 0;
        if(!testNumber(month)) {
            cout << ERROR_2 << endl;
            cout << "--> At month <" << month << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_1 << endl; }
        iMonth = atoi(month.c_str());
        
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
    
    // Call resourceCollection.Add(command);
    resourceCollection.addResource(command);
    
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
        result = parseUser(command) && result; }

    return true;
}

// *** Parse a custom string User command *** //
bool Library::parseUser(string command)
{
    if(command == "") { 
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_2 << endl;
        return false; }
    int iUserId = 0;
    string sUserId(command.substr(0, command.find_first_of(CMD_SEPARATOR)));

    // Parse user from string
    if(!testNumber(sUserId)) {
        cout << ERROR_2 << endl;
        cout << "--> At sUserId <" << sUserId << ">" << endl;
        cout << "---> At string <" << command << ">" << endl;
        cout << "----> At " << MID_2 << endl;
        return false; }
    iUserId = atoi(sUserId.c_str());

    // Check 0<=integer<9999 as final validation
    if((iUserId <= USERID_MIN) || (iUserId > USERID_MAX)) {
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

    // Call userCollection to implement the command
    userCollection.addUser(command);
    return true;
}

// *** Parse an ifstream command *** //
bool Library::parseCommand(ifstream &input)
{
    bool result = true;
    string command;
    
    while(!input.eof()) {
        getline(input, command);
        result = parseCommand(command) && result; }

    return true;
}

// *** Parse a custom string command *** //
bool Library::parseCommand(string command)
{
    if(command == "") { 
        cout << ERROR_5 << endl;
        cout << "--> At " << MID_105 << endl;
        return false; }
    
    string cmd = command.substr(0, 1); // Get the command
    string validCmds[] = ACTION_CMDS;
    bool isValid = false;
    for(int i = 0; i < ACTION_CMD_N; i++) {
        if(cmd == validCmds[i]) {
            isValid = true;
            break; } }
    if(!isValid) {
        cout << ERROR_32 << endl;
        cout << "--> At Command Id <" << cmd << ">" << endl;
        cout << "---> At Command <" << command << ">" << endl;
        cout << "----> At " << MID_105 << endl;
        return false; }
    
    // Retrieve user
    User* user = NULL;
    Resource *resource = NULL;

    if(cmd != "D") {
        // Obtain userId
        string remaining = command.substr(command.find_first_of(" ") + 1,
            command.size() - command.find_first_of(" ") - 1);
        string userId = remaining.substr(0, remaining.find_first_of(" "));
        // Parse user from string
        if(!testNumber(userId)) {
            cout << ERROR_2 << endl;
            cout << "--> At userId <" << userId << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_105 << endl;
            return false; }
        int iUserId = atoi(userId.c_str());
        // Check 0<=integer<9999 as final validation
        if((iUserId <= USERID_MIN) || (iUserId > USERID_MAX)) {
            cout << ERROR_3 << endl;
            cout << "--> At User Id <" << iUserId << ">" << endl;
            cout << "---> At string <" << command << ">" << endl;
            cout << "----> At " << MID_105 << endl;
            return false; } 
        user = userCollection.getUser(userId);

        if(cmd != "H") {
            // Obtain resource
            remaining = remaining.substr(remaining.find_first_of(" ") + 1,
                remaining.size() - remaining.find_first_of(" ") - 1);
            resource = resourceCollection.getResource(fixString(remaining)); }
    }

    // Retrieve resource

    // TODO: Call the appropriate object

    return true;
}

// *** Trim spaces at the end if any *** //
string Library::trimString(string value)
{
    int endVal = value.find_last_not_of(" ") + 1;
    return value.substr(0, endVal);
}

// *** Test a string for valid number conversion *** //
bool Library::testNumber(string number) const
{
    for(unsigned int i = 0; i < number.size(); i++)  {
        if((number[i] < '0') || (number[i] > '9')) {
            return false; } } // Digit char is not within '0' - '9'
    return true; // All digits were verified now
}

// *** Fix strings that cannot be processed directly in given order *** //
string Library::fixString(string resource) const 
{
    if( resource.size() == 0) {
        return ""; }

    // Obtain the type
    string type = resource.substr(0, resource.find_first_of(" "));

    // Validate resourceType
    bool isValidType = false;
    string resourceTypeValues[RESOURCE_TYPES_N] = RESOURCE_TYPES;
    for(int typeIdx = 0; typeIdx < RESOURCE_TYPES_N; typeIdx++) {
        if(resourceTypeValues[typeIdx] == type) {
            isValidType = true;
            break; } }

    if(!isValidType) {
        cout << ERROR_9 << endl;
        cout << "--> At Type <" << type << ">" << endl;
        cout << "---> At string <" << resource << ">" << endl;
        cout << "----> At " << MID_107 << endl;
        return ""; }

    // Although not used, check for is existence
    unsigned found = resource.find(" H ");
    if(found == string::npos) {
        // There's no H for hard copy type, so an un supported value must be 
        // here
        cout << ERROR_34 << endl;
        cout << "--> At resource <" << resource << ">" << endl;
        cout << "---> At " << MID_107 << endl;
        return ""; }

    if(resource[0] == 'P') { // Fix for Periodical
        string remaining = resource.substr(resource.find_first_of(" ") + 1,
            resource.size() - resource.find_first_of(" ") - 1);
        // Ignore (for now) the hard copy
        remaining = remaining.substr(resource.find_first_of(" ") + 1,
            resource.size() - resource.find_first_of(" ") - 1);
        // Get the year
        string year = remaining.substr(0, remaining.find_first_of(" "));
        if(!testNumber(year)) {
            cout << ERROR_2 << endl;
            cout << "--> At year <" << year << ">" << endl;
            cout << "---> At resource <" << resource << ">" << endl;
            cout << "----> At " << MID_107 << endl;
            return ""; }
        remaining = remaining.substr(remaining.find_first_of(" ") + 1,
            remaining.size() - remaining.find_first_of(" ") - 1);
        // Get the month
        string month = remaining.substr(0, remaining.find_first_of(" "));
        if(!testNumber(month)) {
            cout << ERROR_2 << endl;
            cout << "--> At month <" << year << ">" << endl;
            cout << "---> At resource <" << resource << ">" << endl;
            cout << "----> At " << MID_107 << endl;
            return ""; }
        int iMonth = 0;
        iMonth = atoi(month.c_str());// Validate the actual month
        if((iMonth <= 0) || (iMonth > 12)) {
            cout << ERROR_11 << endl;
            cout << "--> At month <" << month << ">" << endl;
            cout << "---> At resource <" << resource << ">" << endl;
            cout << "----> At " << MID_107 << endl; 
            return ""; }
        remaining = remaining.substr(remaining.find_first_of(" ") + 1,
            remaining.size() - remaining.find_first_of(" ") - 1);
        string title = remaining.substr(0, remaining.find_first_of(","));
        return (type + " " + title + ", " + month + " " + year); }
    if(resource[0] == 'Y') { // Fix for Youth
        string remaining = resource.substr(resource.find_first_of(" ") + 1,
            resource.size() - resource.find_first_of(" ") - 1);
        // Ignore (for now) the hard copy
        remaining = remaining.substr(resource.find_first_of(" ") + 1,
            resource.size() - resource.find_first_of(" ") - 1);
        string title = remaining.substr(0, remaining.find_first_of(","));
        remaining = remaining.substr(remaining.find_first_of(",") + 2,
            remaining.size() - remaining.find_first_of(",") - 2);
        string author = remaining.substr(0, remaining.find_first_of(","));
        return (type + " " + author + ", " + title);
    }

    return resource;
}

