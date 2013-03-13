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

#ifndef RESOURCECOLLECTION_H
#define RESOURCECOLLECTION_H

class ResourceCollection
{
public:
	ResourceCollection();  // Default constructor
	~ResourceCollection(); // Default Destructor
	bool addResource(std::string cmd); 
	Resource* getResource(std::string resource);
private:
    // Private Data Members //
    HashTable resourceFactory;
    HashTable resourceList;
};

#endif