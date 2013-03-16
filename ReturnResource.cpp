/******************************************************************************
* Return Resource class <ReturnResource.cpp>:
* This class implements checkout operation for the resources
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "ReturnResource.h"

using namespace std;

ReturnResource::ReturnResource()
{
    // Any implementation details here
}

ReturnResource::~ReturnResource()
{
    // Wrap up procedures
}

Object* ReturnResource::create() const 
{
    return new ReturnResource;
}

void ReturnResource::Execute(string cmd, User *user, Resource *resource,
                             ResourceCollection *ResourceCollection) const
{
    if(user == NULL) {
        cout << endl << ERROR_39 << endl;
        cout << "--> In command <" << cmd << ">" << endl;
        cout << "---> At " << MID_117 << endl << endl;
        return; }
    if(resource == NULL) {
        cout << endl << ERROR_40 << endl;
        cout << "--> In command <" << cmd << ">" << endl;
        cout << "---> At " << MID_117 << endl << endl;
        return; }
    // Return resource
    if(resource->returnResource(user->getUserId())) {
        user->addHistory("Return   ", resource); }
}

