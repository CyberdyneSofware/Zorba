#include <iostream>
#include <string.h>
#include <list>

#include "InventoryClass.h"

using namespace std;

char InventoryClass::addOrManage = 'A';

void InventoryClass::InventoryCommand()
{

    //object for running the functions from the class
    InventoryClass run;

    //if user is adding an item to the inventory
    if(addOrManage == 'a' || addOrManage == 'A')
    {
        run.AddItem();
    }

    //if user is managing inventory
    if(addOrManage == 'b' || addOrManage == 'B')
    {
        run.ManageInventory();
    }
}

/****
Adding an item
Out of battle:
-chests will be determined on certain coordinates
-when the user gets on a coordinate that has a chest then it will open that chest and add it to the inventory

In Battle:
-At the end of the battle the user will be prompted with a reward - this will be added to the inventory
*****/
void InventoryClass::ManageInventory()
{


}

/******
Managing Inventory
Out of Battle:
User can go to

******/
void InventoryClass::AddItem()
{

}
