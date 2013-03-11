/******************************************************************************
* HashTable <HashTable.h>:
* This class implements a hash table based on the base object
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <string>
#include "ErrorDefinition.h"
#include "Object.h"

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TREE_SIZE 255

class HashTable : public Object
{
public:
    HashTable();  // Default constructor
    virtual ~HashTable(); // Default destructor
    // Inherited comparison methods
    virtual bool operator==(const Object &obj) const;
    virtual bool operator!=(const Object &obj) const;
    virtual bool operator<(const Object &obj) const;
    virtual bool operator<=(const Object &obj) const;
    virtual bool operator>(const Object &obj) const;
    virtual bool operator>=(const Object &obj) const;
    /* Create a new instance of this object */
    virtual Object* create() const;
    bool add(std::string key, Object* value); // Add item into the hash
    Object* retrieve(std::string key) const; // Retrieve an item from the hash
    Object* operator[](std::string key) const; // Retrieve overload
    Object* remove(std::string key); // Remove item
    int size() const; // Return the number of items in the hash
    void removeAll(); // Remove all objects in the hash tables
private:
    struct Node {
        Node *children[TREE_SIZE];
        Object *data;
        bool hasChildren;
        string key;
        string remaining; 
        Node() {
            for(int i = 0; i < TREE_SIZE; i++) {
                children[i] = NULL; } }
        ~Node() { 
            for(int i = 0; i < TREE_SIZE && hasChildren; i++) {
                delete children[i]; }
        }
    };

    Node *root;
    int itemCount;

    // Remove helper
    void removeAllHelper(Node *cursor);
};

#endif
