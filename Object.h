/******************************************************************************
* Object Class (Object.h)
* This class is used as base class from which all other objects will inherit,
* this is used to handle our hash tables
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#ifndef OBJECT_H
#define OBJECT_H

class Object 
{
public:
    Object();                             // Default Constructor
    virtual ~Object();                    // Default Destructor
    virtual Object* create() const = 0;   // Create a new object instance
    virtual bool operator==(const Object &) const = 0; // Operator ==
    virtual bool operator!=(const Object &) const = 0; // Operator !=
    virtual bool operator<(const Object &) const = 0;  // Operatpr <
    virtual bool operator<=(const Object &) const = 0; // Operator <=
    virtual bool operator>(const Object &) const = 0;  // Operator >
    virtual bool operator>=(const Object &) const = 0; // Operator >=
};

#endif
