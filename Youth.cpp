/******************************************************************************
* Youth class <Youth.cpp>:
* This class implements Fiction books
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Youth.h"

using namespace std;
Youth::Youth()
{
    isInitialized    = false;
    type             = YOUTH_TYPE;
    author           = "";
    title            = "";
    year             = "";
    availableCopies  = YOUTH_COPIES;
    for(int i = 0; i < YOUTH_COPIES; i++) {
        resourceCopies[i] = ""; }
}

// *** Destructor *** //
Youth::~Youth()
{
    // TODO: Implement destructor
}

// *** Inherited method section *** //
Object* Youth::create() const 
{
    return new Youth;
}

bool Youth::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_56 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_56 << endl;
        return false; }
    const Youth &youth = static_cast<const Youth &>(obj);
    if(youth.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_56 << endl;
        return false; }
    // Compare by title, then by author
    if(this->title.compare(youth.title) == 0) {
        return (this->author.compare(youth.author) == 0); }
return (this->title.compare(youth.title) == 0);
}

bool Youth::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_57 << endl;
        return true; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_57 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Youth::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_58 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_58 << endl;
        return false; }
    const Youth &youth = static_cast<const Youth &>(obj);
    if(youth.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_58 << endl;
        return false; }
    // Compare by title then by author
    if(this->title.compare(youth.title) == 0) {
        return (this->author.compare(youth.author) < 0); }
    return (this->title.compare(youth.title) < 0);
}

bool Youth::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_59 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_59 << endl;
        return false; }
    const Youth &youth = static_cast<const Youth &>(obj);
    if(youth.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_59 << endl;
        return false; }
    // Compare by title and then by author
    if(this->title.compare(youth.title) == 0) {
        return (this->author.compare(youth.author) <= 0); }
    return (this->title.compare(youth.title) <= 0);
}

bool Youth::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_60 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_60 << endl;
        return false; }
    const Youth &youth = static_cast<const Youth &>(obj);
    if(youth.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_60 << endl;
        return false; }
    // Compare by title, then by author
    if(this->title.compare(youth.title) == 0) {
        return (this->author.compare(youth.author) > 0); }
    return (this->title.compare(youth.title) > 0);
}

bool Youth::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_61 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_61 << endl;
        return false; }
    const Youth &youth = static_cast<const Youth &>(obj);
    // Test by author then by title
    if(this->title.compare(youth.title) == 0) {
        return (this->author.compare(youth.author) >= 0); }
    return (this->title.compare(youth.title) >= 0);
}

string Youth::populate(string cmd)
{
    type = YOUTH_TYPE;
    if(cmd.substr(0, cmd.find_first_of(RESOURCE_SEPARATOR)) != YOUTH_TYPE_ID) {
        cout << ERROR_24 << endl;
        cout << "--> At " << MID_62 << endl;
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

string Youth::getType() const 
{
    return type;
}

string Youth::getTitle() const 
{
    return title;
}

string Youth::getYear() const 
{
    return year;
}

string Youth::getMonth() const 
{
    cout << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_63 << endl;
    return ""; // Not supported
}

string Youth::getAuthor() const 
{
    return author;
}

string Youth::getGenre() const 
{
    cout << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_64 << endl;
    return ""; // Not supported
}

bool Youth::returnResource(string userId)
{
    if(availableCopies == YOUTH_COPIES) {
        cout << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_65 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < YOUTH_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << ERROR_26 << endl;
        cout << "--> User ID: " << userId << endl;
        cout << "---> Resource: " << getKey() << endl;
        cout << "----> At " << MID_65 << endl;
        return false; }
    resourceCopies[userIdx] = "";
    return true;
}

bool Youth::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_66 << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < YOUTH_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_66 << endl;
        return false; }
    for(int i = 0; i < YOUTH_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            break; } }
    return true;
}

string Youth::getKey() const 
{
    if(!isInitialized) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_67 << endl; 
        return ""; }
    // Sort by author then by title
     return title + "-" + author;
}

int Youth::getAvailableCopies() const 
{
    return availableCopies;
}
