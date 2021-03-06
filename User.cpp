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

bool User::addHistory(string op, Resource *item)
{
    if(root == NULL) {
        root = new Node;
        root->op = op;
        root->data = item;
        root->next = NULL;
        tail = root;
        return true; }

    tail->next = new Node;
    tail->next->op = op;
    tail->next->data = item;
    tail->next->next = NULL;
    tail = tail->next;

    return true;
}

void User::printHistory() const 
{
    if(root == NULL) {
        cout << endl << ERROR_35 << endl;
        cout << "--> User <" << userId << " - " << lastName << " ";
        cout << firstName << ">" << endl;
        cout << "---> At " << MID_108 << endl << endl;
        return; }

    // Print header
    cout << endl;
    string header = "*** User ID = " + userId + " " + lastName + " " 
        + firstName;
    if(header.size() > PRINT_WIDTH) {
        header = header.substr(0, PRINT_WIDTH - 3);
        header += "..."; }
    cout << header << endl;
    
    Node *cursor = root;
    while(cursor != NULL) {
        cout << cursor->op;
        cursor->data->printResource();
        cursor = cursor->next; }
}

