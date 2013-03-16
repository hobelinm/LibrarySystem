/******************************************************************************
* Resource Collection class <ResourceCollection.h>:
* This class implements all resource handling for the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <string>
#include "ErrorDefinition.h"
#include "Object.h"
#include "HashTable.h"
#include "Resource.h"
#include "Audio.h"
#include "Fiction.h"
#include "Periodical.h"
#include "Video.h"
#include "Youth.h"

#ifndef RESOURCECOLLECTION_H
#define RESOURCECOLLECTION_H
#define RESOURCECOL_TYPES 5
#define RESOURCES {"AUDIO", "FICTION", "VIDEO", "YOUTH", "PERIODICAL"}
#define SORTED_TYPES {"AUDIO", "FICTION", "PERIODICAL", "VIDEO", "YOUTH"}

#define HEADER1 {"AVAIL TITLE                                     GENRE                 YEAR", "AVAIL AUTHOR                                   TITLE                  YEAR", "AVAIL YEAR MO TITLE", "AVAIL TITLE                                   GENRE               YEAR", "AVAIL TITLE                                   AUTHOR                  YEAR"}

#define HEADER2 {"----- ----------------------------------- --------------------------- ----", "----- --------------------------- ----------------------------------- ----", "----- ---- -- --------------------------------------------------------", "----- --------------------------------------- ------------------- ----", "----- ---------------------------------- ---------------------------- ----"}

class ResourceCollection
{
public:
    ResourceCollection();  // Default constructor
    ~ResourceCollection(); // Default Destructor
    bool addResource(std::string cmd); 
    Resource* getResource(std::string resource);
    void print() const;
private:
    // Private Data Members //
    HashTable resourceFactory;
    HashTable resourceList;
    std::string resourceHash(std::string resourceId) const;
};

#endif

