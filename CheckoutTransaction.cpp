/******************************************************************************
* Checkout Transaction class <CheckoutTransaction.cpp>:
* This class implements checkout operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "CheckoutTransaction.h"

using namespace std;

CheckoutTransaction::CheckoutTransaction()
{
    // Any implementation details here
}

CheckoutTransaction::~CheckoutTransaction()
{
    // Wrap Up procedures here
}

Object* CheckoutTransaction::create() const 
{
    return new CheckoutTransaction;
}

void CheckoutTransaction::Execute(string cmd, User *user, Resource *resource,
                                  ResourceCollection *res) const 
{
    if(user == NULL) {
        cout << endl << ERROR_39 << endl;
        cout << "--> In command <" << cmd << ">" << endl;
        cout << "--> At " << MID_116 << endl << endl;
        return; }
    if(resource == NULL) {
        cout << endl << ERROR_40 << endl;
        cout << "--> In command <" << cmd << ">" << endl;
        cout << "---> At " << MID_116 << endl << endl;
        return; }
    // Check out the resource
    if(resource->checkoutResource(user->getUserId())) {
        user->addHistory("Checkout ", resource); }
}


