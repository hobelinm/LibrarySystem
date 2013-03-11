/******************************************************************************
* Librarian Class <Librarian.cpp>:
* This class is used to represent library librarian's 
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Librarian.h"

using namespace std;

// *** Constructor *** // 
Librarian::Librarian()
{
    isInitialized = false;
    type        = LIBRARIAN_TYPE;
    firstName   = "";
    lastName    = "";
    userId      = "";
    street      = "";
    city        = "";
    phone       = "";
    email       = "";
}

// *** Destructor *** //
Librarian::~Librarian()
{
    // TODO: Implement destructor
}

// *** Inherited method implementation section *** //
Object* Librarian::create() const 
{
    return new Librarian;
}

bool Librarian::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_28 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_28 << endl;
        return false; }
    const Librarian &librarian = static_cast<const Librarian &>(obj);
    if(librarian.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_28 << endl;
        return false; }
    return (this->userId.compare(librarian.userId) == 0);
}

bool Librarian::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_29 << endl;
        return true; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_29 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Librarian::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_30 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_30 << endl;
        return false; }
    const Librarian &librarian = static_cast<const Librarian &>(obj);
    if(librarian.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_30 << endl;
        return false; }
    return (this->userId.compare(librarian.userId) < 0);
}

bool Librarian::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_31 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_31 << endl;
        return false; }
    const Librarian &librarian = static_cast<const Librarian &>(obj);
    if(librarian.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_31 << endl;
        return false; }
    return (this->userId.compare(librarian.userId) <= 0);
}

bool Librarian::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_32 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_32 << endl;
        return false; }
    const Librarian &librarian = static_cast<const Librarian&>(obj);
    if(librarian.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_32 << endl;
        return false; }
    return (this->userId.compare(librarian.userId) > 0);
}

bool Librarian::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_33 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_33 << endl;
        return false; }
    const Librarian &librarian = static_cast<const Librarian&>(obj);
    if(librarian.isInitialized == false) {
        cout << ERROR_22 <<endl;
        cout << "--> At " << MID_33 << endl;
        return false; }
    return (this->userId.compare(librarian.userId) >= 0);
}

string Librarian::populate(string cmd)
{
    userId = cmd.substr(0, cmd.find_first_of(CMD_SEPARATOR));
    string remaining = cmd.substr(cmd.find_first_of(CMD_SEPARATOR) + 1, 
        cmd.size() - cmd.find_first_of(CMD_SEPARATOR) - 1);
    lastName = remaining.substr(0, remaining.find_first_of(CMD_SEPARATOR));
    remaining  = remaining.substr(remaining.find_first_of(CMD_SEPARATOR) + 1,
        remaining.size() - remaining.find_first_of(CMD_SEPARATOR) - 1);
    if(remaining.size() > 0) { // Is first name included?
        firstName = remaining.substr(0, 
            remaining.find_first_of(CMD_SEPARATOR)); 
        remaining  = remaining.substr(
            remaining.find_first_of(CMD_SEPARATOR) + 1, remaining.size() -
            remaining.find_first_of(CMD_SEPARATOR) - 1); }
    if(remaining.size() > 0) { // Space for street?
        street = remaining.substr(0, remaining.find_first_of(ALT_SEPARATOR));
        remaining  = remaining.substr(
            remaining.find_first_of(ALT_SEPARATOR) + 1, remaining.size() -
            remaining.find_first_of(ALT_SEPARATOR) - 1); }
    if(remaining.size() > 0) { // Is city included as well?
        city = remaining.substr(0, remaining.find_first_of(ALT_SEPARATOR));
        remaining  = remaining.substr(
            remaining.find_first_of(ALT_SEPARATOR) + 1, remaining.size() -
            remaining.find_first_of(ALT_SEPARATOR) - 1); }
    if(remaining.size() > 0) { // Is telephone number included
        phone = remaining.substr(0, remaining.find_first_of(ALT_SEPARATOR));
        remaining  = remaining.substr(
            remaining.find_first_of(ALT_SEPARATOR) + 1, remaining.size() -
            remaining.find_first_of(ALT_SEPARATOR) - 1); }
    if(remaining.size() > 0) { // Is email included?
        email = remaining.substr(0, remaining.find_first_of(ALT_SEPARATOR));
        remaining  = remaining.substr(
            remaining.find_first_of(ALT_SEPARATOR) + 1, remaining.size() -
            remaining.find_first_of(ALT_SEPARATOR) - 1); }

    isInitialized = true;
    return userId;
}

// *** Getter section *** //
string Librarian::getType() const 
{
    return type;
}

string Librarian::getUserId() const 
{
    return userId;
}

string Librarian::getFirstName() const 
{
    return firstName;
}

string Librarian::getLastName() const 
{
    return lastName;
}

string Librarian::getStreet() const 
{
    return street;
}

string Librarian::getCity() const 
{
    return city;
}

string Librarian::getPhone() const 
{
    return phone;
}

string Librarian::getEmail() const 
{
    return email;
}

