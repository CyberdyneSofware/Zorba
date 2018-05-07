#ifndef INVENTORYCOMMAND_H_INCLUDED
#define INVENTORYCOMMAND_H_INCLUDED

#include "InventoryClass.h"
#include "AddItem.h"
#include "ManagingMenu.h"

#include <iostream>

#include <list>

using namespace std;

/*
Inventory command:
1. function for adding items
2. function for deleting and selecting items/ managing inventory
*/

InventoryClass item;

char InventoryClass::InventoryCommand(item.choice)
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
        command.ManageMenu();
    }

    return 0;
}


#endif // INVENTORYCOMMAND_H_INCLUDED
