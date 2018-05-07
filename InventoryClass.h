#ifndef INVENTORYCLASS_H_INCLUDED
#define INVENTORYCLASS_H_INCLUDED

#include "InventoryCommand.h"
#include "AddItem.h"
#include "ManagingMenu.h"

#include <list>
#include <iostream>

using namespace std;

class InventoryClass
{
public:
    //functions
    char InventoryCommand(char choice/*when calling the inventorycommand(choice); function please set choice to either 'a' for adding an item or 'b' for anything else)*/);
    void AddItem(); //add an item to the list
    void ManageMenu(); //managing item
    //list
    //list<struct> inventory; //the list for the inventory

private:


};

#endif // INVENTORYCLASS_H_INCLUDED
