/******************************************************************************
* Youth class <Youth.h>:
* This class implements Youth books
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/
#include <string>
#include "ErrorDefinition.h"
#include "Resource.h"

#ifndef YOUTH_H
#define YOUTH_H
#define YOUTH_TYPE "YOUTH"
#define YOUTH_TYPE_ID "Y"
#define YOUTH_COPIES 5
#define RESOURCE_SEPARATOR " "
#define RESOURCE_SEPARATOR2 ","
#define YOUTH_HEADER1 "AVAIL TITLE                                   AUTHOR                       YEAR"
#define YOUTH_HEADER2 "----- --------------------------------------- ---------------------------- ----"
#define YOUTH_SIZES {5, 40, 31, 4}

class Youth : public Resource
{
public:
    Youth();          // Defult constructor
    virtual ~Youth(); // Default destructor
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
    std::string resourceCopies[YOUTH_COPIES];
};

#endif

