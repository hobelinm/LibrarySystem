/******************************************************************************
* Fiction class <Fiction.h>:
* This class implements Fiction books
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Resource.h"

#ifndef FICTION_H
#define FICTION_H
#define FICTION_TYPE "FICTION"
#define FICTION_TYPE_ID "F"
#define FICTION_COPIES 5
#define RESOURCE_SEPARATOR " "
#define RESOURCE_SEPARATOR2 ","
#define FICTION_HEADER1 "AVAIL AUTHOR                                   TITLE                       YEAR"
#define FICTION_HEADER2 "----- --------------------------------------- ---------------------------- ----"
#define FICTION_SIZES {5, 31, 40, 4}

class Fiction : public Resource
{
public:
    Fiction();          // Defult constructor
    virtual ~Fiction(); // Default destructor
    // Inherited methods
    virtual Object* create() const;
    virtual bool operator==(const Object &obj) const;
    virtual bool operator!=(const Object &obj) const;
    virtual bool operator<(const Object &obj) const;
    virtual bool operator<=(const Object &obj) const;
    virtual bool operator>(const Object &obj) const;
    virtual bool operator>=(const Object &obj) const;
    virtual std::string populate(std::string cmd);
    // Setters and getters
    virtual std::string getType() const;
    virtual std::string getTitle() const;
    virtual std::string getYear() const;
    virtual std::string getMonth() const;
    virtual std::string getAuthor() const;
    virtual std::string getGenre() const;
    virtual std::string getKey() const;
    virtual int getAvailableCopies() const;
    // Resource functions
    virtual bool checkoutResource(std::string userId);
    virtual bool returnResource(std::string userId);
    // Print
    virtual void print() const;
private:
    bool isInitialized;
    std::string author;
    std::string resourceCopies[FICTION_COPIES];
};

#endif
