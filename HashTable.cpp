/******************************************************************************
* HashTable <HashTable.cpp>:
* This class implements a hash table based on the base object
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "HashTable.h"

// *** Default Constructor *** //
HashTable::HashTable()
{
    //root = new Node; // TODO: This is until adding a new object
    itemCount = 0;
    root = NULL;
    // TODO: Add any constructor instruction here
}

// *** Default Destructor *** //
HashTable::~HashTable()
{
    if(root != NULL) {
        // TODO: Implement destroy routine
        removeAll(); }
    // TODO: Destroy any data here
}

// *** Add an item to the hash table *** //
bool HashTable::add(std::string key, Object* value)
{
    if(key == "") {
        cout << ERROR_16 << endl;
        cout << "--> At " << MID_21 << endl; 
        return false; }
    if(value == NULL) {
        cout << ERROR_17 << endl;
        cout << "--> At " << MID_21 << endl;
        return false; }
    if(retrieve(key) != NULL) { // Item already exists in HashTable
        cout << ERROR_18 << endl;
        cout << "--> At " << MID_21 << endl;
        return false; }

    // Check if we have any item stored
    if(root == NULL) {
        root = new Node;
        root->data = value;
        root->hasChildren = false;
        root->key = key;
        root->remaining = "";
        return true; } 
    
    Node *cursor = root;
    string remaining = key;
    while(cursor->hasChildren &&
        (remaining.size() > 0)) { // Loop until finding the proper spot
            if(cursor->children[remaining[0]] != NULL)
            { // We have more children with this path
                cursor = cursor->children[remaining[0]];
                remaining = remaining.substr(1, remaining.size() - 1);
            } else {
                // We found a place to put our key,value pair
                // Test for existence of the same key here:
                if(cursor->key == key) {
                    cout << FATAL_ERROR1 << endl;
                    cout << "--> At Key <" << key << ">" << endl;
                    cout << "---> At " << MID_21 << endl;
                    return false; }
                cursor->children[remaining[0]] = new Node;
                cursor->children[remaining[0]]->data = value;
                cursor->children[remaining[0]]->hasChildren = false;
                cursor->children[remaining[0]]->key = key;
                cursor->children[remaining[0]]->remaining = 
                    remaining.substr(1, remaining.size() - 1);
                cursor->hasChildren = true;
                return true; } }
    // Two options here:
    // 1 - remaining.size() == 0, we reached the end of the key
    if(remaining.size() == 0) {
        // Check remaining to see if we can insert here
        if(cursor->remaining == "") {
            cout << FATAL_ERROR1 << endl;
            cout << "--> At Key <" << key << ">" << endl;
            cout << "---> At " << MID_21 << endl;
            return false; }
        // move currently stored data down one level
        cursor->children[cursor->remaining[0]] = new Node;
        cursor->children[cursor->remaining[0]]->data = cursor->data;
        cursor->children[cursor->remaining[0]]->hasChildren = false;
        cursor->children[cursor->remaining[0]]->key = cursor->key;
        cursor->children[cursor->remaining[0]]->remaining =
            cursor->remaining.substr(1, cursor->remaining.size() - 1);
        // Now insert our key, value in cursor's position
        cursor->data = value;
        cursor->hasChildren = true;
        cursor->key = key;
        cursor->remaining = remaining;
        return true; }
    
    // 2 - cursor->hasChildren == false, we reached the end of the trie
    if(cursor->children[remaining[0]] != NULL) {
        cout << FATAL_ERROR2 << endl;
        cout << "--> At key <" << key << ">" << endl;
        cout << "---> At " << MID_21 << endl;
        return false; }
    cursor->children[remaining[0]] = new Node;
    cursor->children[remaining[0]]->data = value;
    cursor->children[remaining[0]]->hasChildren = false;
    cursor->children[remaining[0]]->key = key;
    cursor->children[remaining[0]]->remaining = 
        remaining.substr(1, remaining.size() - 1);
    cursor->hasChildren = true;
    return true;
}

// *** Retrieve an object from the hash table *** //
Object* HashTable::retrieve(string key) const 
{
    if(key == "") { // No empty strings allowed
        cout << ERROR_16 << endl;
        cout << "--> At " << MID_19 << endl;
        return NULL; }
    if(root == NULL) {
    //    cout << ERROR_19 << endl;
    //    cout << "--> At " << MID_19 << endl;
        return NULL; }

    string remainder = key;
    Node *cursor = root;
    while(cursor != NULL
        && (cursor->key != key)
        && (remainder.size() > 0)) {
        cursor = cursor->children[remainder[0]];
        remainder = remainder.substr(1, remainder.size() - 1); }
    // Three options here:
    // 1 - cursor->key == key, we found the item we were looking for
    if((cursor != NULL) && (cursor->key == key)) {
        return cursor->data; }
    // 2 - remainder.size() == 0, or cursor == NULL, item is not in hash table
    return NULL;
}

// *** Overloaded method for retrieving items from hash table *** // 
Object* HashTable::operator[](string key) const 
{
    if(key == "") { // No empty strings allowed
        cout << ERROR_16 << endl;
        cout << "--> At " << MID_18 << endl;
        return NULL; }
    return retrieve(key);
}

// *** Remove an item from hash table *** //
Object* HashTable::remove(string key)
{
    if(key == "") {
        cout << ERROR_16 << endl;
        cout << "--> At " << MID_20 << endl;
        return NULL; }
    // TODO: Implement HashTable.Remove
    // 1 - Find the location of key
    //
    // If it has children
    return NULL;
}

// *** Get the number of items stored in HashTable *** //
int HashTable::size() const 
{
    return itemCount;
}

// *** Remove all objects in the hash table *** //
void HashTable::removeAll()
{
    // Perform a simple traverse to remove the elements
    if(root != NULL) {
        removeAllHelper(root); }
}

void HashTable::removeAllHelper(Node *cursor)
{
    // Delete cursor's data
    cursor->data->~Object();
    delete cursor->data;
    cursor->key = "";
    cursor->remaining = "";
    
    // Recurse over children
    for(int i = 0; i < TREE_SIZE && cursor->hasChildren; i++) {
        if(cursor->children[i] != NULL) {
            removeAllHelper(cursor->children[i]); } }
    // At this point we deleted all of its children, so
    cursor->hasChildren = false;
    delete cursor;
}