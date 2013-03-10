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
    type      = USER_TYPE;
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

bool Patron::populate(string cmd) 
{
    // TODO: Implement this method
    return true;
}

// *** Custom method implementation *** //
