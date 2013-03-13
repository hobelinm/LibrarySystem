/******************************************************************************
* Fiction class <Fiction.cpp>:
* This class implements Fiction books
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Fiction.h"

using namespace std;
Fiction::Fiction()
{
    isInitialized    = false;
    type             = FICTION_TYPE;
    author           = "";
    title            = "";
    year             = "";
    availableCopies  = FICTION_COPIES;
    for(int i = 0; i < FICTION_COPIES; i++) {
        resourceCopies[i] = ""; }
}

// *** Destructor *** //
Fiction::~Fiction()
{
    // TODO: Implement destructor
}

// *** Inherited method section *** //
Object* Fiction::create() const 
{
    return new Fiction;
}

bool Fiction::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_44 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_44 << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_44 << endl;
        return false; }
    // Compare by author, then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) == 0); }

    return (this->author.compare(fiction.author) == 0);
}

bool Fiction::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_45 << endl;
        return true; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_45 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Fiction::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_46 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_46 << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_46 << endl;
        return false; }
    return (this->author.compare(fiction.author) < 0);
}

bool Fiction::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_47 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_47 << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_47 << endl;
        return false; }
    // Compare by author and then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) <= 0); }
    return (this->author.compare(fiction.author) <= 0);
}

bool Fiction::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_48 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_48 << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_48 << endl;
        return false; }
    return (this->author.compare(fiction.author) > 0);
}

bool Fiction::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_49 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_49 << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    // Test by author then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) >= 0); }
    return (this->author.compare(fiction.author) >= 0);
}

string Fiction::populate(string cmd)
{
    type = FICTION_TYPE;
    if(cmd.substr(0, cmd.find_first_of(RESOURCE_SEPARATOR)) != FICTION_TYPE_ID)
    {
        cout << ERROR_24 << endl;
        cout << "--> At " << MID_50 << endl;
        return ""; }
    string remaining = cmd.substr(cmd.find_first_of(RESOURCE_SEPARATOR) + 1,
        cmd.size() - cmd.find_first_of(RESOURCE_SEPARATOR) - 1);
    author = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    remaining = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2)
        - 2);
    title = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    year = remaining.substr(remaining.find_last_of(RESOURCE_SEPARATOR2) + 2,
        remaining.size() - remaining.find_last_of(RESOURCE_SEPARATOR2) - 2);

    isInitialized = true;
    return getKey();
}

string Fiction::getType() const 
{
    return type;
}

string Fiction::getTitle() const 
{
    return title;
}

string Fiction::getYear() const 
{
    return year;
}

string Fiction::getMonth() const 
{
    return ""; // Not supported
}

string Fiction::getAuthor() const 
{
    return author;
}

string Fiction::getGenre() const 
{
    return ""; // Not supported
}

bool Fiction::returnResource(string userId)
{
    if(availableCopies == FICTION_COPIES) {
        cout << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_52 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << ERROR_26 << endl;
        cout << "--> User ID: " << userId << endl;
        cout << "---> Resource: " << getKey() << endl;
        cout << "----> At " << MID_52 << endl;
        return false; }
    resourceCopies[userIdx] = "";
    return true;
}

bool Fiction::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_53 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_53 << endl;
        return false; }
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            break; } }
    return true;
}

string Fiction::getKey() const 
{
    if(!isInitialized) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_51 << endl; 
        return ""; }
    // Sort by author then by title
     return author + "-" + title;
}

int Fiction::getAvailableCopies() const 
{
    return availableCopies;
}
