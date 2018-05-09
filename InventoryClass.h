#ifndef INVENTORYCLASS_H_INCLUDED
#define INVENTORYCLASS_H_INCLUDED

#include <iostream>
#include <string.h>
#include <list>
#include "InventoryClass.h"

using namespace std;

class InventoryClass
{
    public:
    //functions
    void InventoryCommand(); //commands the inventory functions and calls
    void AddItem(); //adds an item to the list based off of coordinates or winning a battle
    void ManageInventory(); //allows player to see the inventory and delete from the inventory, but also if the character is in battle they can select an item to use

    private:

};

/* All Items */
/****
char type = ---->
weapon = 'w' - modifies strength
clothing = 'c' - modifies defence
buffs: HP = 'h' - modifies HP
buffs: intelligence = 'i' - modifies intelligence
buffs: Resistance = 'r' - modifies resistance
****/

struct item
{
    string name; //stores the name
    char type; //stores the type of the item
    int modifyStat; //how much the item should modify
    bool inuse; //if the item is in use or not
    string message; //the message that plays when you equip it
};


//item - stick
item stick;
stick.name = "Stick";
stick.type = 'w';
stick.modifyStat = 1;
stick.inuse = false;
stick.message = "Can't wait to see you on the new watchmojo video; top ten worst anime weapons";

//item - basic sword
item basicsword;
basicsword.name = "Basic Sword";
basicsword.type = 'w';
basicsword.modifyStat = 3;
basicsword.inuse = false;
basicsword.message = "Wow maybe you'll actually make a dent in em.";

//item
item knife;
knife.name = "Knife";
knife.type = 'w';
knife.modifyStat = 2;
knife.inuse = false;
knife.message = "Not very useful from far way, but good luck.";

#endif // INVENTORYCLASS_H_INCLUDED
