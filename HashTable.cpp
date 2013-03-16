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
    itemCount = 0;
    root = NULL;
    // TODO: Add any constructor instruction here
}

// *** Default Destructor *** //
HashTable::~HashTable()
{
    if(root != NULL) {
        // destroy routine
        removeAll(); }
    // TODO: Destroy any data here
}

// *** Add an item to the hash table *** //
bool HashTable::add(std::string key, Object* value)
{
    if(key == "") {
        cout << endl << ERROR_16 << endl;
        cout << "--> At " << MID_21 << endl << endl; 
        return false; }
    if(value == NULL) {
        cout << endl << ERROR_17 << endl;
        cout << "--> At " << MID_21 << endl << endl;
        return false; }
    if(retrieve(key) != NULL) { // Item already exists in HashTable
        cout << endl << ERROR_18 << endl;
        cout << "--> Key <" << key << ">" << endl;
        cout << "---> At " << MID_21 << endl << endl;
        return false; }

    // Check if we have any item stored
    if(root == NULL) {
        root = new Node;
        root->hasChildren = true;
        root->key = "";
        root->remaining = "";
        root->data = NULL;
        root->children[key[0]] = new Node;
        root->children[key[0]]->data = value;
        root->children[key[0]]->hasChildren = false;
        root->children[key[0]]->key = key;
        root->children[key[0]]->remaining = key.substr(1, key.size() - 1);
        itemCount++;
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
                    cout << endl << FATAL_ERROR1 << endl;
                    cout << "--> At Key <" << key << ">" << endl;
                    cout << "---> At " << MID_21 << endl << endl;
                    return false; }
                cursor->children[remaining[0]] = new Node;
                cursor->children[remaining[0]]->data = value;
                cursor->children[remaining[0]]->hasChildren = false;
                cursor->children[remaining[0]]->key = key;
                cursor->children[remaining[0]]->remaining = 
                    remaining.substr(1, remaining.size() - 1);
                cursor->hasChildren = true;
                itemCount++;
                return true; } }
    // Two options here:
    // 1 - remaining.size() == 0, we reached the end of the key
    if(remaining.size() == 0) {
        // Check remaining to see if we can insert here
        if(cursor->remaining == "") {
            cout << endl << FATAL_ERROR1 << endl;
            cout << "--> At Key <" << key << ">" << endl;
            cout << "---> At " << MID_21 << endl << endl;
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
        itemCount++;
        return true; }
    
    // 2 - cursor->hasChildren == false, we reached the end of the trie
    if(cursor->children[remaining[0]] != NULL) {
        cout << endl << FATAL_ERROR2 << endl;
        cout << "--> At key <" << key << ">" << endl;
        cout << "---> At " << MID_21 << endl << endl;
        return false; }
    cursor->children[remaining[0]] = new Node;
    cursor->children[remaining[0]]->data = value;
    cursor->children[remaining[0]]->hasChildren = false;
    cursor->children[remaining[0]]->key = key;
    cursor->children[remaining[0]]->remaining = 
        remaining.substr(1, remaining.size() - 1);
    cursor->hasChildren = true;
    itemCount++;
    return true;
}

// *** Retrieve an object from the hash table *** //
Object* HashTable::retrieve(string key) const 
{
    if(key == "") { // No empty strings allowed
        cout << endl << ERROR_16 << endl;
        cout << "--> At " << MID_19 << endl << endl;
        return NULL; }
    if(root == NULL) {
    //    cout << ERROR_19 << endl;
    //    cout << "--> At " << MID_19 << endl;
        return NULL; }

    string remainder = key;
    Node *cursor = root;
    while(cursor != NULL
        && (cursor->key.compare(key) != 0)
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
        cout << endl << ERROR_16 << endl;
        cout << "--> At " << MID_18 << endl << endl;
        return NULL; }
    return retrieve(key);
}

// *** Remove an item from hash table *** //
Object* HashTable::remove(string key)
{
    if(root == NULL) {
        return NULL; }

    if(root->key == key) { // It's time to remove root
        Object *item  = root->data;
        root->data = NULL;
        root->key = "";
        root->remaining = "";
        if(root->hasChildren == false) {
            delete root; 
            root = NULL; }
        return item; }

    if(root->children[key[0]] == NULL) {
        return NULL; }
    string remainder = key;
    Node *cursor = root->children[remainder[0]];
    while(cursor->children[remainder[0]] != NULL
        && (cursor->children[remainder[0]]->key != key)
        && (remainder.size() > 0)) {
        cursor = cursor->children[remainder[0]];
        remainder = remainder.substr(1, remainder.size() - 1); }
    // Three options here:
    // 1 - cursor->key == key, we found the item we were looking for
    if((remainder.size() > 0) && (cursor->children[remainder[0]] != NULL) 
        && (cursor->key == key)) {
        Object *item = cursor->children[remainder[0]]->data;
        cursor->children[remainder[0]]->key = "";
        cursor->children[remainder[0]]->remaining = "";
        cursor->children[remainder[0]]->data = NULL;
        if(cursor->children[remainder[0]]->hasChildren == false) {
            delete cursor->children[remainder[0]];
            cursor->children[remainder[0]] = NULL; }
        return cursor->data; }
    // 2 - remainder.size() == 0, or cursor == NULL, item is not in hash table
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
    if(cursor->key != "") {
        cursor->data->~Object();
        delete cursor->data;
        cursor->key = "";
        cursor->remaining = ""; }
    
    // Recurse over children
    for(int i = 0; i < TREE_SIZE && cursor->hasChildren; i++) {
        if(cursor->children[i] != NULL) {
            removeAllHelper(cursor->children[i]); } }
    // At this point we deleted all of its children, so
    cursor->hasChildren = false;
    delete cursor;
}

// *** Implement inherited operations *** //
bool HashTable::operator==(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_36 << endl << endl;
        return false; }
    const HashTable &hashTable = static_cast<const HashTable &>(obj);
    return (this->itemCount == hashTable.itemCount);
}

bool HashTable::operator!=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_37 << endl << endl;
        return true; }
    return !this->operator==(obj);
}

bool HashTable::operator<(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_38 << endl << endl;
        return false; }
    const HashTable &hashTable = static_cast<const HashTable &>(obj);
    return (this->itemCount < hashTable.itemCount);
}

bool HashTable::operator<=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_39 << endl << endl;
        return false; }
    const HashTable &hashTable = static_cast<const HashTable &>(obj);
    return (this->itemCount <= hashTable.itemCount);
}

bool HashTable::operator>(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_40 << endl << endl;
        return false; }
    const HashTable &hashTable = static_cast<const HashTable &>(obj);
    return (this->itemCount > hashTable.itemCount);
}

bool HashTable::operator>=(const Object &obj) const 
{
    if(&obj == NULL) {
        cout << endl << ERROR_14 << endl;
        cout << "--> At " << MID_41 << endl << endl;
        return false; }
    const HashTable &hashTable = static_cast<const HashTable &>(obj);
    return (this->itemCount >= hashTable.itemCount);
}

Object* HashTable::create() const 
{
    return new HashTable;
}

void HashTable::print() const 
{
    if(root != NULL) {
        printHelper(root); }
}

void HashTable::printHelper(Node *cursor) const 
{
    if(cursor == NULL) { return; }
    bool isPrint = false;
    
    if(cursor->remaining == "" && cursor->data != NULL) {
        cursor->data->print(); 
        isPrint = true; }
    // Loop through all children
    for(int i = 0; i < TREE_SIZE && cursor->hasChildren; i++) {
        if(cursor->children[i] == NULL ) {continue; }
        if(!isPrint && cursor->remaining.size() > 1
            && i >= cursor->remaining[1] &&
            isS1Less(cursor->key, cursor->children[i]->key)) {
            cursor->data->print();
            isPrint = true; }
        printHelper(cursor->children[i]); }
    // Then print
    if(cursor->key != "" && !isPrint) {
        cursor->data->print(); }
    return;
}

bool HashTable::isS1Less(string s1, string s2) const 
{
    bool less = true;
    for(unsigned int i = 0; i < s1.size() && i < s2.size(); i++) {
        if(s2[i] > s1[i] && s2[i] != ' ') {
            less = false;
            break; } }
    return less;
}
