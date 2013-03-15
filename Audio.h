/******************************************************************************
* Audio class <Audio.h>:
* This class implements Audio assets for the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Resource.h"

#ifndef AUDIO_H
#define AUDIO_H
#define AUDIO_TYPE "AUDIO"
#define AUDIO_TYPE_ID "A"
#define AUDIO_COPIES 1
#define RESOURCE_SEPARATOR " "
#define RESOURCE_SEPARATOR2 ","
#define AUDIO_HEADER1 "AVAIL TITLE                                   GENRE                        YEAR"
#define AUDIO_HEADER2 "----- --------------------------------------- ---------------------------- ----"
#define AUDIO_SIZES {5, 40, 31, 4}

class Audio : public Resource
{
public:
    Audio();          // Defult constructor
    virtual ~Audio(); // Default destructor
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
    std::string genre;
    std::string resourceCopies[AUDIO_COPIES];
};

#endif

