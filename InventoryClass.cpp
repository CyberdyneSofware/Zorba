#include <iostream>
#include <string.h>
#include <list>
#include<stdlib.h>

#include "InventoryClass.h"
#include "Item.h"

using namespace std;

/*GLOBAL VARIABLES FROM THE CLASS*/
char InventoryClass::addOrManage = 'A';
bool InventoryClass::inOrOutBattle = false;

float InventoryClass::cordx = 0;
float InventoryClass::cordy = 0;

int InventoryClass::equipped = 0;

int firstrun = 0; //makes sure that the items aren't equipped more than once

character player; //temporary object for the player TAKE OUT WHEN TAYLOR'S CODE HAS BEEN COMBINED


/**Inventory Command*/
void InventoryClass::InventoryCommand()
{

    //object for running the functions from the class
    InventoryClass run;

    //add the basic items to the player's inventory
    while(firstrun == 0)
    {
        //equip the items
        cout << "\n";
        cout << "\nYou look in your bag and there are a mysterious three items that you don't remember being there.";
        cout << "\n";
        cout << "\n";
        cout << stick.name << " has been equipped!";
        cout << "\n";
        cout << tatteredcloth.name << " has been equipped!";
        cout << "\n";
        cout << hppotion.name << " has been equipped!";

        listOfItems.push_front(stick);
        stick.inuse = true;
        listOfItems.push_back(tatteredcloth);
        tatteredcloth.inuse = true;
        listOfItems.push_back(hppotion);
        hppotion.inuse = true;

        cout << "\n\nIt seems like you can only equip three items at a time, so choose wisely what ones you pick to use once you get more.";

        //change character's equipped
        InventoryClass::equipped = 3;

        //change the character's stats


        //make sure that the user cannot go through this loop again
        firstrun++;

        cin.get();
        system("CLS"); //clear the screen
    }

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

/******
Managing Inventory
Out of Battle:
user can access menu whenever they need - they can delete items from the inventory and equip weapons and clothing
seeing what the items will do

In Battle:
-seeing what the items will do
-selecting items to use putting on armor and using potions
******/
void InventoryClass::ManageInventory()
{
    /* Out of battle */
    if (inOrOutBattle == false)
    {

    }

    /* In Battle */
    if (inOrOutBattle == true)
    {

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
void InventoryClass::AddItem()
{
    //chest is open - true  chest is closed - false
    bool chest00 = false;
    bool chest01 = false;
    bool chest02 = false;
    bool chest03 = false;
    bool chest04 = false;
    bool chest_11 = false;
    bool chest11 = false;

    /* Out of battle */
    if (inOrOutBattle == false)
    {

    /* Out of battle */

        //check each room for a chest - if they are the coordinates then they will open it - if they have opened it then set it's open or close variable true
        if(cordx == 0 && cordy == 0 && chest00 == false)
        {
            cout << "\n";
            cout << "\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << leatherarmor.name << "!";
            listOfItems.push_back(leatherarmor);
            cout << "\n";
            cout << "\n";
            cout << leatherarmor.message;
            cout << "\n";
            cout << "\n";
            cout << leatherarmor.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen
            //chest is now open
            chest00 = true;
        }

        //if they land on (0,1)
        else if(cordx == 0 && cordy == 1 && chest01 == false)
        {
            cout << "\n";
            cout << "\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << basicsword.name << "!";
            listOfItems.push_back(basicsword);
            cout << "\n";
            cout << "\n";
            cout << basicsword.message;
            cout << "\n";
            cout << "\n";
            cout << basicsword.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen
            //chest is now open
            chest01 = true;
        }

        //if they land on (0,2)
        else if(cordx == 0 && cordy == 2 && chest02 == false)
        {
            cout << "\n";
            cout << "\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << dragonslayer.name << "!";
            listOfItems.push_back(dragonslayer);
            cout << "\n";
            cout << "\n";
            cout << dragonslayer.message;
            cout << "\n";
            cout << "\n";
            cout << dragonslayer.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen
            //chest is now open
            chest02 = true;
        }

        //if they land on (0,3)
        else if(cordx == 0 && cordy == 3 && chest03 == false)
        {
            cout << "\n";
            cout << "\nThe end of the game draws near and the fateful battle will begin here are a few things to prepare you for this fight.";
            cout << "\n";

            cout << "\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << diamondarmor.name << "!";
            listOfItems.push_back(diamondarmor);
            cout << "\n";
            cout << "\n";
            cout << diamondarmor.message;
            cout << "\n";
            cout << "\n";
            cout << diamondarmor.name << " has been added to your inventory";

            cout << "\n\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << theswordgunknife.name << "!";
            listOfItems.push_back(theswordgunknife);
            cout << "\n";
            cout << "\n";
            cout << theswordgunknife.message;
            cout << "\n";
            cout << "\n";
            cout << theswordgunknife.name << " has been added to your inventory";

            cout << "\n\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << superpotion.name << "!";
            listOfItems.push_back(superpotion);
            cout << "\n";
            cout << "\n";
            cout << superpotion.message;
            cout << "\n";
            cout << "\n";
            cout << superpotion.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen
            //chest is now open
            chest03 = true;
        }

        //if they land on (-1,1)
        else if(cordx == -1 && cordy == 1 && chest_11 == false)
        {
            cout << "\n\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << dragonslayer.name << "!";
            listOfItems.push_back(dragonslayer);
            cout << "\n";
            cout << "\n";
            cout << dragonslayer.message;
            cout << "\n";
            cout << "\n";
            cout << dragonslayer.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen

            //chest is now open
            chest_11 = true;
        }

        //if they land on (1,1)
        else if(cordx == 1 && cordy == 1 && chest11 == false)
        {
            cout << "\n\nDA DA \nA CHEST HAS BEEN FOUND";
            cout << "\n";
            cout << "\nYou found: " << bootgun.name << "!";
            listOfItems.push_back(bootgun);
            cout << "\n";
            cout << "\n";
            cout << bootgun.message;
            cout << "\n";
            cout << "\n";
            cout << bootgun.name << " has been added to your inventory";

            cin.get();
            system("CLS"); //clear the screen

            //chest is now open
            chest11 = true;
        }

        //if they land on on a coordinate other than the ones listed
        else
        {
            cout << "\nSorry my dude, There are no chests to be opened in this room";
        }
    }

    /* In Battle */
    if (inOrOutBattle == true)
    {

    }

    //test print out list:

}
