/******************************************************************************
* Periodicals class <Preiodical.h>:
* This class implements Periodicals
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Resource.h"

#ifndef PERIODICAL_H
#define PERIODICAL_H
#define PERIODICAL_TYPE "PERIODICAL"
#define PERIODICAL_TYPE_ID "P"
#define PERIODICAL_COPIES 1
#define RESOURCE_SEPARATOR " "
#define RESOURCE_SEPARATOR2 ","

class Periodical : public Resource
{
public:
    Periodical();          // Defult constructor
    virtual ~Periodical(); // Default destructor
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
    
private:
    bool isInitialized;
    std::string month;
    std::string resourceCopies[PERIODICAL_COPIES];
};

#endif

