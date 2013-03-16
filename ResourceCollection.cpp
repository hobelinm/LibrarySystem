/******************************************************************************
* Resource Collection class <ResourceCollection.cpp>:
* This class implements all resource handling for the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "ResourceCollection.h"

using namespace std;

// *** Default constructor *** //
ResourceCollection::ResourceCollection()
{
    // Add resource types
    // Construct factory table so we can construct resource items later
    resourceFactory.add("FICTION", new Fiction);
    resourceFactory.add("YOUTH", new Youth);
    resourceFactory.add("PERIODICAL", new Periodical);
    resourceFactory.add("AUDIO", new Audio);
    resourceFactory.add("VIDEO", new Video);
    // Construct resource types
    string resourceTypes[] = RESOURCES;
    // Create hash tables for each type of resource
    for(int i = 0; i < RESOURCECOL_TYPES; i++) {
        resourceList.add(resourceTypes[i], (new HashTable)); }
}

// *** Default destructor *** //
ResourceCollection::~ResourceCollection()
{
    // TODO: Implement any destruction action here
}

bool ResourceCollection::addResource(string resource)
{
    // Get the appropriate resource type
    Resource *resourceType = static_cast<Resource *>
        (resourceFactory[resourceHash(resource)]);
    Resource *nResource = static_cast<Resource *>(resourceType->create());
    string key = nResource->populate(resource);
    if(key == "") {
        delete nResource;
        cout << ERROR_31 << endl;
        cout << "--> At " << MID_104 << endl;
        return false; }
    // Get the proper list to insert
    HashTable *hashTable = static_cast<HashTable *>
        (resourceList[resourceHash(nResource->getType())]);
    if(hashTable == NULL) {
        delete nResource;
        cout << FATAL_ERROR3 << endl;
        cout << "--> At " << MID_104 << endl;
        return false; }
    // Add user into the list
    hashTable->add(key, nResource);
    return true;
}

// *** Resource Hash determine which type of element to create *** //
// This method assumes that resourceId has been already validated before
// Node: Edit this method for more types of resources
string ResourceCollection::resourceHash(string resourceId) const 
{
    if(resourceId.size() <= 0) {
        cout << ERROR_23 << endl;
        cout << "--> At " << MID_103 << endl;
        return ""; }

    string resourceTypes[] = RESOURCES;
    // This give us only the spots we need for our array of hashes :)
    int id = ((resourceId[0] - 'A') / 3) % 5;
    // A small fix in one of the calculations
    if(resourceId[0] == 'P') { id += 4; }

    if(id >= RESOURCECOL_TYPES || id < 0) {
        cout << ERROR_30 << endl;
        cout << "--> CODE <" << resourceId[0] << ">" << endl;
        cout << "--> At " << MID_103 << endl;
        return ""; }

    return resourceTypes[id];
}

Resource* ResourceCollection::getResource(string resource)
{
    if(resource.size() <= 0) {
        cout << ERROR_33 << endl;
        cout << "--> At " << MID_106 << endl;
        return NULL; }
    // Get the type of the user
    HashTable *hashTable = static_cast<HashTable *>
        (resourceList[resourceHash(resource)]);
    // Get a dummy resource so we can get the key
    Resource *resourceType = static_cast<Resource *>
        (resourceFactory[resourceHash(resource)]);
    Resource *nResource = static_cast<Resource *>(resourceType->create());
    // Ignore Hard copies, for now...
    unsigned found = resource.find(" H ");
    string res = resource;
    if(found != string::npos) {
        res = resource.substr(0, resource.find_first_of(" "));
        resource = resource.substr(resource.find_first_of(" ") + 1, 
            resource.size() - resource.find_first_of(" ") + 1);
        resource = resource.substr(resource.find_first_of(" ") + 1, 
            resource.size() - resource.find_first_of(" ") + 1);
        res = res + " " + resource; }
    string key = nResource->populate(res);
    delete nResource;
    return static_cast<Resource *>(hashTable->retrieve(key));
}

void ResourceCollection::print() const 
{
    // Retrieve each sub-hashTable and print their contents
    string types[] = SORTED_TYPES;
    string header1[] = HEADER1;
    string header2[] = HEADER2;
    HashTable *resourceType = NULL;
    for(int i = 0; i < RESOURCECOL_TYPES; i++) {
        resourceType = static_cast<HashTable *>(resourceList[types[i]]);
        if(resourceType == NULL) {
            cout << endl << FATAL_ERROR3 << endl;
            cout << "--> At " << MID_120 << endl << endl;
            continue; }

        cout << endl << " *** " << types[i] << ": ***" << endl;
        cout << header1[i] << endl << header2[i] << endl;
        resourceType->print();
        cout << header2[i] << endl;
    }

    // Print header in between
}

