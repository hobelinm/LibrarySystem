/******************************************************************************
* Periodical class <Periodical.cpp>:
* This class implements Youth books
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Periodical.h"

using namespace std;
Periodical::Periodical()
{
    isInitialized    = false;
    type             = PERIODICAL_TYPE;
    month            = "";
    title            = "";
    year             = "";
    availableCopies  = PERIODICAL_COPIES;
    for(int i = 0; i < PERIODICAL_COPIES; i++) {
        resourceCopies[i] = ""; }
}

// *** Destructor *** //
Periodical::~Periodical()
{
    // TODO: Implement destructor
}

// *** Inherited method section *** //
Object* Periodical::create() const 
{
    return new Periodical;
}

bool Periodical::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_68 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_68 << endl << endl;
        return false; }
    const Periodical &periodical = static_cast<const Periodical &>(obj);
    if(periodical.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_68 << endl << endl;
        return false; }
    // Compare by year, then by month, the by title
    if(this->year.compare(periodical.year) == 0) {
        if(this->month.compare(periodical.month) == 0) {
            return (this->title.compare(periodical.title) == 0); }
        return (this->month.compare(periodical.month) == 0); }

    return (this->year.compare(periodical.year) == 0);
}

bool Periodical::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_69 << endl << endl;
        return true; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_69 << endl << endl;
        return true; }
    return !this->operator==(obj);
}

bool Periodical::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_70 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_70 << endl << endl;
        return false; }
    const Periodical &periodical = static_cast<const Periodical &>(obj);
    if(periodical.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_70 << endl << endl;
        return false; }
    // Compare by year, then by month, then by title
    if(this->year.compare(periodical.year) == 0) {
        if(this->month.compare(periodical.month) == 0) {
            return (this->title.compare(periodical.title) < 0); }
        return (this->month.compare(periodical.month) < 0); }
    return (this->year.compare(periodical.year) < 0);
}

bool Periodical::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_71 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_71 << endl << endl;
        return false; }
    const Periodical &periodical = static_cast<const Periodical &>(obj);
    if(periodical.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_71 << endl << endl;
        return false; }
    // Compare by year, then by month, then by title
    if(this->year.compare(periodical.year) == 0) {
        if(this->month.compare(periodical.month) == 0) {
            return (this->title.compare(periodical.title) <= 0); }
        return (this->month.compare(periodical.month) <= 0); }
    return (this->year.compare(periodical.year) <= 0);
}

bool Periodical::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_72 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_72 << endl << endl;
        return false; }
    const Periodical &periodial = static_cast<const Periodical &>(obj);
    if(periodial.isInitialized == false) {
        cout << endl << ERROR_22 << endl;
        cout << "--> At " << MID_72 << endl << endl;
        return false; }
    // Compare by year, then by month, then by author
    if(this->year.compare(periodial.year) == 0) {
        if(this->month.compare(periodial.month) == 0) {
            return (this->title.compare(periodial.title) > 0); }
        return (this->month.compare(periodial.month) > 0); }
    return (this->year.compare(periodial.year) > 0); 
}

bool Periodical::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_73 << endl << endl;
        return false; }
    if(isInitialized == false) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_73 << endl << endl;
        return false; }
    const Periodical &periodical = static_cast<const Periodical &>(obj);
    // Test by year, then by month, then by title
    if(this->year.compare(periodical.year) == 0) {
        if(this->month.compare(periodical.month) == 0) {
            return (this->title.compare(periodical.title) >= 0); }
        return (this->month.compare(periodical.month) >= 0); }
    return (this->year.compare(periodical.year) >= 0);
}

string Periodical::populate(string cmd)
{
    type = PERIODICAL_TYPE;
    if(cmd.substr(0, cmd.find_first_of(RESOURCE_SEPARATOR)) 
        != PERIODICAL_TYPE_ID) {
        cout << ERROR_24 << endl;
        cout << "--> At " << MID_74 << endl;
        return ""; }
    string remaining = cmd.substr(cmd.find_first_of(RESOURCE_SEPARATOR) + 1,
        cmd.size() - cmd.find_first_of(RESOURCE_SEPARATOR) - 1);
    title = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR2));
    
    // Suppose month is already validated
    isInitialized = true;
    if(remaining.size() <= 0 || (remaining.size() - 1 == title.size())) {
        return getKey(); }
    remaining = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR2)
        + 2, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR2)
        - 2);
    month = remaining.substr(0, remaining.find_first_of(RESOURCE_SEPARATOR));
    if(month.size() == 1) {
        month += " "; }
    isInitialized = true;
    if(remaining.size() <= 0) {
        return getKey(); }
    year = remaining.substr(remaining.find_first_of(RESOURCE_SEPARATOR)
        + 1, remaining.size() - remaining.find_first_of(RESOURCE_SEPARATOR) - 1
        );

    return getKey();
}

string Periodical::getType() const 
{
    return type;
}

string Periodical::getTitle() const 
{
    return title;
}

string Periodical::getYear() const 
{
    return year;
}

string Periodical::getMonth() const 
{
    return month;
}

string Periodical::getAuthor() const 
{
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_75 << endl << endl;
    return ""; // Parameter is not supported
}

string Periodical::getGenre() const 
{
    cout << endl << ERROR_29 << endl;
    cout << "--> At " << getKey() << endl;
    cout << "---> At " << MID_76 << endl << endl;
    return ""; // Not supported
}

bool Periodical::returnResource(string userId)
{
    if(availableCopies == PERIODICAL_COPIES) {
        cout << endl << ERROR_27 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_77 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < PERIODICAL_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i;
            break; } }
    if(userIdx == -1) {
        cout << endl << ERROR_26 << endl;
        cout << "--> User ID: " << userId << endl;
        cout << "---> Resource: " << getKey() << endl;
        cout << "----> At " << MID_77 << endl << endl;
        return false; }
    resourceCopies[userIdx] = "";
    availableCopies++;
    return true;
}

bool Periodical::checkoutResource(string userId)
{
    if(availableCopies <= 0) {
        cout << endl << ERROR_25 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_78 << endl << endl;
        return false; }
    // [Simple] Search for this userId in our array
    int userIdx = -1;
    for(int i = 0; i < PERIODICAL_COPIES; i++) {
        if(resourceCopies[i] == userId) {
            userIdx = i; // User found
            break; } }
    if(userIdx != -1) {
        cout << ERROR_28 << endl;
        cout << "--> User ID <" << userId << ">" << endl;
        cout << "---> Resource <" << getKey() << ">" << endl;
        cout << "----> At " << MID_78 << endl;
        return false; }
    for(int i = 0; i < PERIODICAL_COPIES; i++) {
        if(resourceCopies[i] == "") {
            resourceCopies[i] = userId;
            availableCopies--;
            break; } }
    return true;
}

string Periodical::getKey() const 
{
    if(!isInitialized) {
        cout << endl << ERROR_21 << endl;
        cout << "--> At " << MID_79 << endl << endl; 
        return ""; }
    // Sort by year, then by month, then by title
     return year + "-" + month + "-" + title;
}

int Periodical::getAvailableCopies() const 
{
    return availableCopies;
}

void Periodical::print() const 
{
    unsigned sizes[] = PERIODICAL_SIZES;
    // Available copies
    cout << "  " << availableCopies << "   ";
    string output = "";
    
    // Year
    string y = year;
    if(y.size() > sizes[1]) {
        y = y.substr(0, sizes[1] - 3);
        y += "... "; }
    if(y.size() < sizes[1]) {
        for(unsigned i = y.size(); i <= sizes[1]; i++) {
            y += " "; } }
    output += y;
    output += " ";
    output += month;
    output += " ";
    
    // Title
    string t = title;
    if(t.size() > sizes[3]) {
        t = t.substr(0, sizes[3] - 3);
        t += "... "; }
    if(t.size() < sizes[3]) {
        for(unsigned i = t.size(); i <= sizes[3]; i++) {
            t += " "; } }
    output += t;
    cout << output << endl;
}

void Periodical::printResource() const 
{
    unsigned sizes[] = PERIODICAL_SIZES;
    // Available copies
    string output = "";
    
    // Year
    string y = year;
    if(y.size() > sizes[1]) {
        y = y.substr(0, sizes[1] - 3);
        y += "... "; }
    if(y.size() < sizes[1]) {
        for(unsigned i = y.size(); i <= sizes[1]; i++) {
            y += " "; } }
    output += y;
    output += " ";
    output += month;
    output += " ";
    
    // Title
    string t = title;
    if(t.size() > sizes[3]) {
        t = t.substr(0, sizes[3] - 3);
        t += "... "; }
    if(t.size() < sizes[3]) {
        for(unsigned i = t.size(); i <= sizes[3]; i++) {
            t += " "; } }
    output += t;
    cout << output << endl;
}

