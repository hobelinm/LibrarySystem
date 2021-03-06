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
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_44 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_44 << endl << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_44 << endl << endl;
        return false; }
    // Compare by author, then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) == 0); }

    return (this->author.compare(fiction.author) == 0);
}

bool Fiction::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_45 << endl << endl;
        return true; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_45 << endl << endl;
        return true; }
    return !this->operator==(obj);
}

bool Fiction::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_46 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_46 << endl << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_46 << endl << endl;
        return false; }
    // Compare by author, then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) < 0); }
    return (this->author.compare(fiction.author) < 0);
}

bool Fiction::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_47 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_47 << endl << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_47 << endl << endl;
        return false; }
    // Compare by author and then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) <= 0); }
    return (this->author.compare(fiction.author) <= 0);
}

bool Fiction::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_48 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_48 << endl << endl;
        return false; }
    const Fiction &fiction = static_cast<const Fiction &>(obj);
    if(fiction.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_48 << endl << endl;
        return false; }
    // Compare by author then by title
    if(this->author.compare(fiction.author) == 0) {
        return (this->title.compare(fiction.title) > 0); }
    return (this->author.compare(fiction.author) > 0);
}

bool Fiction::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_49 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_49 << endl << endl;
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
        cout << endl << ERROR_24 << endl;
        cout << "--> At " << MID_50 << endl << endl;
        return ""; }
    string remaining = cmd.substr(cmd.find_first_of(RESOURCE_SEPARATOR) + 1,
        cmd.size() - cmd.find_first_of(RESOURCE_SEPARATOR) - 1);
    author = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    remaining = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2)
        - 2);

    isInitialized = true;
    if(remaining.size() <= 0 || (remaining.size() - 1 == author.size())) {
        return getKey(); }
    title = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    
    if(remaining.size() <= 0 || (remaining.size() - 1 == title.size())) {
        return getKey(); }
    year = remaining.substr(remaining.find_last_of(RESOURCE_SEPARATOR2) + 2,
        remaining.size() - remaining.find_last_of(RESOURCE_SEPARATOR2) - 2);

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
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_54 << endl << endl;
    return ""; // Not supported
}

string Fiction::getAuthor() const 
{
    return author;
}

string Fiction::getGenre() const 
{
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_55 << endl << endl;
    return ""; // Not supported
}

bool Fiction::returnResource(string userId)
{
    if(availableCopies == FICTION_COPIES) {
        cout << endl << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_52 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << endl << ERROR_26 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_52 << endl << endl;
        return false; }
    resourceCopies[userIdx] = "";
    availableCopies++;
    return true;
}

bool Fiction::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << endl << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_53 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << endl << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_53 << endl << endl;
        return false; }
    for(int i = 0; i < FICTION_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            availableCopies--;
            break; } }
    return true;
}

string Fiction::getKey() const 
{
    if(!isInitialized) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_51 << endl << endl; 
        return ""; }
    // Sort by author then by title
     return author + "-" + title;
}

int Fiction::getAvailableCopies() const 
{
    return availableCopies;
}

void Fiction::print() const 
{
    unsigned sizes[] = FICTION_SIZES;
    // Available copies
    cout << "  " << availableCopies << "   ";
    string output = "";
    
    // Title
    string t = title;
    if(t.size() > sizes[1]) {
        t = t.substr(0, sizes[1] - 3);
        t += "... "; }
    if(t.size() < sizes[1]) {
        for(unsigned i = t.size(); i <= sizes[1]; i++) {
            t += " "; } }
    output += t;
    
    // Author
    string a = author;
    if(a.size() > sizes[2]) {
        a = a.substr(0, sizes[2] - 3);
        a += "... "; }
    if(a.size() < sizes[2]) {
        for(unsigned i = a.size(); i <= sizes[2]; i++) {
            a += " "; } }
    output += a;

    // Year
    output += year;

    cout << output << endl;
}

void Fiction::printResource() const 
{
    unsigned sizes[] = FICTION_SIZES;
    string output = "";
    
    // Title
    string t = title;
    if(t.size() > sizes[1]) {
        t = t.substr(0, sizes[1] - 3);
        t += "... "; }
    if(t.size() < sizes[1]) {
        for(unsigned i = t.size(); i <= sizes[1]; i++) {
            t += " "; } }
    output += t;
    
    // Author
    string a = author;
    if(a.size() > sizes[2]) {
        a = a.substr(0, sizes[2] - 3);
        a += "... "; }
    if(a.size() < sizes[2]) {
        for(unsigned i = a.size(); i <= sizes[2]; i++) {
            a += " "; } }
    output += a;

    // Year
    output += year;

    cout << output << endl;
}

