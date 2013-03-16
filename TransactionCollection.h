/******************************************************************************
* TransactionCollection class <TransactionCollection.h>:
* This class handles every transaction in the library system
* CSS502 - Assignment 3
* University of Washington - Winter 2013
* Hugo Belin Melgoza
******************************************************************************/

#include <iostream>
#include <string>
#include "ErrorDefinition.h"
#include "Object.h"
#include "HashTable.h"
#include "User.h"
#include "Resource.h"
#include "ResourceCollection.h"
#include "Transaction.h"
#include "DisplayTransaction.h"
#include "PrintHistory.h"
#include "CheckoutTransaction.h"
#include "ReturnResource.h"

#ifndef TRANSACTIONCOLLECTION_H
#define TRANSACTIONCOLLECTION_H
#define VALID_OPERATIONS_C 4
#define VALID_OPERATIONS {"D", "C", "R", "H"}
// Supported types of commands
// Letters used for Action commands:
#define ACTION_CMD_S 1
// Number of comments
#define ACTION_CMD_N 4
#define ACTION_CMDS {"C", "D", "H", "R"}

class TransactionCollection 
{
public:
    TransactionCollection();  // Default Constructor
    ~TransactionCollection(); // Default Destructor
    void Execute(std::string cmd, User *user, Resource *resource,
        ResourceCollection *resourceCollection);
private:
    HashTable transactionFactory;

};

#endif

