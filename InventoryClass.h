#ifndef INVENTORYCLASS_H_INCLUDED
#define INVENTORYCLASS_H_INCLUDED

#include <iostream>
#include <string.h>
#include <list>

#include "Item.h"

using namespace std;

class InventoryClass
{
    public:
    //functions
    void InventoryCommand(); //commands the inventory functions and calls
    void AddItem(); //adds an item to the list based off of coordinates or winning a battle
    void ManageInventory(); //allows player to see the inventory and delete from the inventory, but also if the character is in battle they can select an item to use

    static char addOrManage; //please set in your program before calling InventoryCommand to either 'a' or 'b' based off of if your adding to the inventory or managing it
    static bool inOrOutBattle; //please set to either true; meaning you are in a battle or false; meaning you are outside of a battle

    static float cordx; //the coordinates for x
    static float cordy; //the coordinates for y

    static int equipped; //counts how many items the user has equipped

    static item *chosenItemPtr; //points to the item the user choses to manage

    static list<item>::iterator itemsIterator; //starts the items iterator at the beginning of the list

    private:

};

#endif // INVENTORYCLASS_H_INCLUDED
