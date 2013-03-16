/******************************************************************************
* Display Transaction class <DisplayTransaction.cpp>:
* This class implements display operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "DisplayTransaction.h"

using namespace std;

DisplayTransaction::DisplayTransaction() 
{
    // Any implementation method here
}

DisplayTransaction::~DisplayTransaction()
{
    // Wrap Up methods here
}

void DisplayTransaction::Execute(string cmd, User *user, Resource *resource,
                                 ResourceCollection *res) const
{
    if(res == NULL) {
        cout << endl << ERROR_41 << endl;
        cout << "--> At " << MID_119 << endl;
        return; }
    res->print(); // Call print method
}

Object* DisplayTransaction::create() const 
{
    return new DisplayTransaction;
}
