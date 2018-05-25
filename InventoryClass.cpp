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
int index = 0; //lets me go through a list and find the element im looking for

character player; //temporary object for the player TAKE OUT WHEN TAYLOR'S CODE HAS BEEN COMBINED
InventoryClass run;//object for running the functions from the class

/**Inventory Command*/
void InventoryClass::InventoryCommand()
{

    //add the basic items to the player's inventory
    while(firstrun == 0)
    {
        //equip the items
        cout << "\n";
        cout << "\nOn your back you feel a weight. You notice it's a backpack of some sort and you pull it off to look at it. \nIn your bag and there are a mysterious three items that you don't remember being there.";

        cin.get();
        system("CLS"); //clear the screen

        cout << stick.name << " has been equipped!";
        cout << "\n";
        cout << tatteredcloth.name << " has been equipped!";
        cout << "\n";
        cout << hppotion.name << " has been equipped!";

        stick.inuse = true;
        listOfItems.push_back(stick);
        tatteredcloth.inuse = true;
        listOfItems.push_back(tatteredcloth);
        hppotion.inuse = true;
        listOfItems.push_back(hppotion);
        listOfItems.push_back(basicsword);

        //change stats based on items equipped
        player.strength = player.strength + stick.modifyStat;
        player.defense = player.defense + tatteredcloth.modifyStat;
        if(player.maxHP - hppotion.modifyStat > player.HP)
        {
            player.HP = player.HP + hppotion.modifyStat;
        }
        else if(player.maxHP - hppotion.modifyStat <= player.HP)
        {
            player.HP = player.maxHP;
        }

        cout << "\n\nIt seems like you can only equip three items at a time, so choose wisely what ones you pick to use once you get more. \nNow lets go to your inventory and look at what you can do with these items.";

        cin.get();
        system("CLS"); //clear the screen

        //change character's equipped
        InventoryClass::equipped = 3;

        run.ManageInventory();
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
    char exit; //lets the user exit the inventory

    /* Out of battle */
    if (inOrOutBattle == false)
    {
        //tell them this is the inventory
        cout << "\n\n";
        cout << "You take a look inside your bag, it seems a bit odd since most of these items shouldn't fit in here, but you avoid questioning that for now.";
        cout << "\nHere are all the items you see";
        cout << "\n\n";

        //show the list
        for (list<item>::iterator itemsIterator = listOfItems.begin(); itemsIterator != listOfItems.end(); itemsIterator++)
        {
            item currentItem;
            //read out the item by accessing the list then the item that is in the list then the name attached
            //cout the index number before each item to access it
            currentItem = *itemsIterator;
            cout << index << ". " << currentItem.name << "\n";

            //add one to index
            index++;
        }

        //tell them the items they have equipped
        cout << "\n\n";
        cout << InventoryClass::equipped << " out of the 3 items you can equip at once are equipped";
        cout << "\nThese items are: ";
        cout << "\n";

        for(list<item>::iterator itemsIterator = listOfItems.begin(); itemsIterator != listOfItems.end(); itemsIterator++)
        {
            item currentItem;
            //set the current item to
            currentItem = *itemsIterator;

            //if the item is in use
            if(currentItem.inuse)
            {
                cout << currentItem.name;
                cout << "\n";
            }

        }

        //do they want to continue and manage the inventory
        cout << "\n\nDo you wish to manage your inventory or EXIT the inventory?";
        cout << "\nType in 'e' if you wish to exit or any other key to continue: ";
        cin >> exit;
        cin.get();

        while(exit != 'e' && exit != 'E')
        {
            //let them enter in the number they want to use
            cout << "\n\nNext to each item there is a number.";
            cout << "\nIf you wish to: ";
            cout << "\nDelete an item, \nRead more about an item, \nUnequip an item, \nEquip an item";
            cout << "\n\nEnter in the corresponding number to the item here: ";
            cin >> index;
            cin.get();

            //tell them what item they choose

            //if the number they entered is not valid give them an error message

            //ask them what they want to do - delete, read more, unequip or equip and let them enter it in

            //if they want to delete the item - must delete one from index, clear screen, reread out the list after deleting is finished

            //if they want to read more about an item

            //if they want to unequip an item

            //if they want to use an item

            //if they want to go through the loop again
            cout << "\n\nDo you still want to manage your inventory?";
            cout << "\nType in 'exit' if you wish to exit or any key to continue: ";
            cin >> exit;
            cin.get();

        }

        if(exit == 'e' || exit == 'E')
        {
            cout << "\n\nYou close your bag and continue on your journey.";

            cin.get();
            system("CLS"); //clear the screen
        }

        //if this is their first time running the program
        if(firstrun == 0)
        {
            firstrun++;

            run.InventoryCommand();
        }
    }


    /* In Battle */
    if (inOrOutBattle == true)
    {
        //battle is finished
        //assign a number to each item that is not yet been assigned a chest or to the main character yet


        //get a random number from that pool and then use the item that corresponds with it


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
    bool chestNegative11 = false;
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
        else if(cordx == -1 && cordy == 1 && chestNegative11 == false)
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
            chestNegative11 = true;
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
    else if (inOrOutBattle == true)
    {

    }

    InventoryClass::addOrManage = 'c';
    //return back to the main game
    cout << "Thanks for running the test";
}
