#include <iostream>
#include <string.h>
#include <list>
#include "InventoryClass.h"
#include "Item.h"

using namespace std;

void InventoryCommand()
{
    //object for running the functions from the class
    InventoryClass runFunction;

    //if they types in to add an item
    if(addOrManage == 'a' || addOrManage == 'A')
    {
        runFunction.AddItem();
    }

    if(addOrMange == 'b' || addOrMange == 'B')
    {
        runFunction.ManageInventory();
    }
}





