/******************************************************************************
* Print History Transaction class <PrintHistory.h>:
* This class implements display operation for the resources
* descriptions
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "PrintHistory.h"

using namespace std;

PrintHistory::PrintHistory()
{
    // TODO: Add initialization methods here
}


PrintHistory::~PrintHistory()
{
    // TODO: Add wrap up methods here
}

void PrintHistory::Execute(string cmd, User *user, Resource *resource,
                           ResourceCollection *resourceCollection) const 
{
    if(user == NULL) {
        cout << endl << ERROR_36 << endl;
        cout << "--> In command <" << cmd << ">" << endl;
        cout << "---> At " << MID_115 << endl << endl;
        return; }
    user->printHistory();
}

Object* PrintHistory::create() const 
{
    return new PrintHistory;
}
