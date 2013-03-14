/******************************************************************************
* Video class <Video.h>:
* This class implements Videos for the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Resource.h"

#ifndef VIDEO_H
#define VIDEO_H
#define VIDEO_TYPE "VIDEO"
#define VIDEO_TYPE_ID "V"
#define VIDEO_COPIES 1
#define RESOURCE_SEPARATOR " "
#define RESOURCE_SEPARATOR2 ","

class Video : public Resource
{
public:
    Video();          // Defult constructor
    virtual ~Video(); // Default destructor
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
    std::string genre;
    std::string resourceCopies[VIDEO_COPIES];
};

#endif

