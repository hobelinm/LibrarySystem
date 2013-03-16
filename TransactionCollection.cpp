/******************************************************************************
* TransactionCollection class <TransactionCollection.cpp>:
* This class handles every transaction in the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include "TransactionCollection.h"

using namespace std;

TransactionCollection::TransactionCollection()
{
    // Add constructor procedures - All transactions
    transactionFactory.add("C", new CheckoutTransaction);
    transactionFactory.add("D", new DisplayTransaction);
    transactionFactory.add("H", new PrintHistory);
    transactionFactory.add("R", new ReturnResource);
}

TransactionCollection::~TransactionCollection()
{
    // TODO: Add destructor procedures
}

void TransactionCollection::Execute(string cmd, User *user, Resource *resource,
                                    ResourceCollection *resourceCollection)
{
    // Get the appropriate method
    const Transaction *transaction = static_cast<const Transaction *>
        (transactionFactory[cmd.substr(0, cmd.find_first_of(" "))]);
    if(transaction == NULL) {
        cout << ERROR_38 << endl;
        cout << "--> From command <" << cmd << ">" << endl;
        cout << "---> At " << MID_118 << endl;
        return; }
    
    // Call its execute method
    transaction->Execute(cmd, user, resource, resourceCollection);
}

