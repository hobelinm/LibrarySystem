/******************************************************************************
* Patron Class <Patron.h>:
* This class is used to represent library patron's 
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "Patron.h"

using namespace std;

// *** Constructor *** //
Patron::Patron()
{
    isInitialized = false;
    type      = PATRON_TYPE;
    firstName = "";
    lastName  = "";
    userId    = "";
    street    = "";
    city      = "";
    phone     = "";
    email     = "";
}

// *** Destructor *** //
Patron::~Patron()
{
    // TODO: Implement destructor
}

// *** Inherited method implementation section *** //
Object* Patron::create() const 
{
    return new Patron;
}

bool Patron::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_22 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_22 << endl;
        return false; }
    const Patron &patron = static_cast<const Patron &>(obj);
    if(patron.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_22 << endl;
        return false; }
    return (this->userId.compare(patron.userId) == 0);
}

bool Patron::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_23 << endl;
        return true; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_23 << endl;
        return true; }
    return !this->operator==(obj);
}

bool Patron::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_24 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_24 << endl;
        return false; }
    const Patron &patron = static_cast<const Patron &>(obj);
    if(patron.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_24 << endl;
        return false; }
    return (this->userId.compare(patron.userId) < 0);
}

bool Patron::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_25 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_25 << endl;
        return false; }
    const Patron &patron = static_cast<const Patron &>(obj);
    if(patron.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_25 << endl;
        return false; }
    return (this->userId.compare(patron.userId) <= 0);
}

bool Patron::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_26 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_26 << endl;
        return false; }
    const Patron &patron = static_cast<const Patron&>(obj);
    if(patron.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_26 << endl;
        return false; }
    return (this->userId.compare(patron.userId) > 0);
}

bool Patron::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << ERROR_14 << endl;
        cout << "--> At " << MID_27 << endl;
        return false; }
    if(isInitialized == false) {
        cout << ERROR_21 << endl;
        cout << "--> At " << MID_27 << endl;
        return false; }
    const Patron &patron = static_cast<const Patron&>(obj);
    if(patron.isInitialized == false) {
        cout << ERROR_22 << endl;
        cout << "--> At " << MID_27 << endl;
        return false; }
    return (this->userId.compare(patron.userId) >= 0);
}

string Patron::populate(string cmd) 
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
string Patron::getType() const 
{
    return type;
}

string Patron::getUserId() const 
{
    return userId;
}

string Patron::getFirstName() const 
{
    return firstName;
}

string Patron::getLastName() const 
{
    return lastName;
}

string Patron::getStreet() const 
{
    return street;
}

string Patron::getCity() const 
{
    return city;
}

string Patron::getPhone() const 
{
    return phone;
}

string Patron::getEmail() const 
{
    return email;
}


