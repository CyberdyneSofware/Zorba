#ifndef INVENTORYCOMMAND_H_INCLUDED
#define INVENTORYCOMMAND_H_INCLUDED

#include "InventoryClass.h"

#include <iostream>

#include <list>

using namespace std;

/*
Inventory command:
1. function for adding items
2. function for deleting and selecting items/ managing inventory
*/

void InventoryCommand()
{
    //variables
    InventoryClass command;

    //function for adding items/grabbing items
    if(command.choice == 'a')
    {
        command.AddItem();
    }

    //function for item menu - managing inventory
    if(command.choice == 'b')
    {
        command.ManagingMenu();
    }

    return 0;
}

void AddItem()
{

}

void ManagingMenu()
{
    /* Viewing the menu */
    //goes through a loop through the whole linked list and shows them all - with a number

    /* selecting an item */
    //enter in a number and then it asks what you want to do

    /* Deleting an item */
    //if they choose to delete it then go into the linked list

    /* Using a item */
    // if they choose to activate a item

}

#endif // INVENTORYCOMMAND_H_INCLUDED
