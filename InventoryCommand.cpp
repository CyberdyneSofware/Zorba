#include <iostream>
#include <string.h>
#include <list>
#include "InventoryClass.h"
#include "Item.h"

using namespace std;

void InventoryClass::InventoryCommand()
{
    InventoryClass run;

    //object for running the functions from the class

    //if they types in to add an item
    if(run.addOrManage == 'a' || run.addOrManage == 'A')
    {
        run.AddItem();
    }

    if(run.addOrManage == 'b' || run.addOrManage == 'B')
    {
        run.ManageInventory();
    }
}





