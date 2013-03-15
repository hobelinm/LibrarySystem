/******************************************************************************
* User Class <User.cpp>:
* This class represents a user on the library systems
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include "User.h"

using namespace std;

// *** Default Constructor *** //
User::User()
{
    // Constructor procedures
    root = NULL;
    tail = NULL;
}

// *** Destructor *** //
User::~User()
{
    // Destructor procedures
    if(root != NULL) {
        Node *cursor = root->next;
        while(root != NULL) {
            delete root;
            root = cursor;
            if(cursor != NULL) {
                cursor = cursor->next; } } }
}

// Since all other methods have been declared as pure virtual they will be 
// implemented by derived classes

bool User::addHistory(string item)
{
    if(root == NULL) {
        root = new Node;
        root->data = item;
        root->next = NULL;
        tail = root;
        return true; }

    tail->next = new Node;
    tail->next->data = item;
    tail->next->next = NULL;
    tail = tail->next;

    return true;
}

void User::printHistory() const 
{
    if(root == NULL) {
        cout << ERROR_35 << endl;
        cout << "--> At " << MID_108 << endl;
        return; }

    // Print header
    string header = "*** User ID = " + userId + " " + lastName + " " 
        + firstName;
    if(header.size() > PRINT_WIDTH) {
        header = header.substr(0, PRINT_WIDTH - 3);
        header += "..."; }
    cout << header << endl;

    Node *cursor = root;
    while(cursor != NULL) {
        cout << cursor->data << endl;
        cursor = cursor->next; }
}