/******************************************************************************
* Object Class (Object.h)
* This class is used as base class from which all other objects will inherit,
* this is used to handle our hash tables
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include "Object.h"
using namespace std;

Object::Object()
{
    // TODO: Construct any objects here
}

Object::~Object()
{
    // TODO: Destruct any objects here
}

void Object::print() const
{
    cout << "<NOT IMPLEMENTED>" << endl;
}