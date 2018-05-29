#include <iostream>
#include <string.h>
#include <list>
#include<stdlib.h>
#include <cstdlib>

#include "InventoryClass.h"

using namespace std;

/*GLOBAL VARIABLES FROM THE CLASS*/
char InventoryClass::addOrManage = 'A';
bool InventoryClass::inOrOutBattle = false;

float InventoryClass::cordx = 0;
float InventoryClass::cordy = 0;

int InventoryClass::equipped = 0;
item *InventoryClass::chosenItemPtr;
list<item>::iterator InventoryClass::itemsIterator;

int firstrun = 0; //makes sure that the items aren't equipped more than once
int index = 0; //lets me go through a list and find the element im looking for
bool error = false; //if the user made a mistake

character player; //temporary object for the player TAKE OUT WHEN TAYLOR'S CODE HAS BEEN COMBINED
InventoryClass run;//object for running the functions from the class

//random generation
#include <ctime>

/**Inventory Command*/
void InventoryClass::InventoryCommand()
{

    ///first run
    //add the basic items to the player's inventory
    while(firstrun == 0)
    {
        //equip the items
        cout << "On your back you feel a weight. You notice it's a backpack of some sort and you pull it off to look at it. \nIn your bag and there are a mysterious three items that you don't remember being there.";

        cin.get();
        system("CLS"); //clear the screen

        cout << stick.name << " has been equipped!";
        cout << "\n";
        cout << tatteredcloth.name << " has been equipped!";
        cout << "\n";
        cout << hppotion.name << " has been used!";

        stick.inuse = true;
        listOfItems.push_back(stick);
        tatteredcloth.inuse = true;
        listOfItems.push_back(tatteredcloth);
        //hp potion was used so no need for it to be in the list
        listOfItems.push_back(basicsword); //test item for non equipped items

        //change stats based on items equipped
        cout << "\n\n   STRENGTH: " << player.strength;
        player.strength = player.strength + stick.modifyStat;
        cout << "  -->  " << player.strength;

        cout << "\n\n   DEFENSE: " << player.defense;
        player.defense = player.defense + tatteredcloth.modifyStat;
        cout << "  -->  " << player.defense;

        if(player.maxHP - hppotion.modifyStat > player.HP)
        {
            cout << "\n\n   HP: " << player.HP;
            player.HP = player.HP + hppotion.modifyStat;
            cout << "  -->  " << player.HP;
        }
        else if(player.maxHP - hppotion.modifyStat <= player.HP)
        {
            cout << "\n\n   HP: " << player.HP;
            player.HP = player.maxHP;
            cout << "  -->  " << player.HP;
        }

        cout << "\n\nIt seems like you can only use three items at a time to change your stats, so when you get more items use wisely! \nNow lets go to your inventory and look at what you can do with these items.";

        cin.get();
        system("CLS"); //clear the screen

        //change character's equipped
        InventoryClass::equipped = 2;

        run.ManageInventory();
    }

    ///normal run
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
    char manageAction; //lets the user enter what they want to do to the item they choose
    srand(time(NULL)); //generates a more true random number

    ///out of battle
    if (InventoryClass::inOrOutBattle == false || firstrun == 0)
    {
        //tell them this is the inventory
        cout << "You take a look inside your bag, it seems a bit odd since most of these items shouldn't fit in here.\nBut you avoid questioning that for now.";
        cout << "\n\nHere are all the items you see: ";
        cout << "\n";

        //show the list
        for (InventoryClass::itemsIterator = listOfItems.begin(); InventoryClass::itemsIterator != listOfItems.end(); InventoryClass::itemsIterator++)
        {
            item currentItem;
            //read out the item by accessing the list then the item that is in the list then the name attached
            //cout the index number before each item to access it
            currentItem = *InventoryClass::itemsIterator;
            cout << index << ". " << currentItem.name << "\n";

            //add one to index
            index++;
        }

        cin.get();//next screen

        //tell them the items they have equipped
        cout << "\n\n";
        cout << InventoryClass::equipped << " /3 are equipped";
        cout << "\n";

        for(InventoryClass::itemsIterator = listOfItems.begin(); InventoryClass::itemsIterator != listOfItems.end(); InventoryClass::itemsIterator++)
        {
            item currentItem;
            //set the current item to
            currentItem = *InventoryClass::itemsIterator;

            //if the item is in use
            if(currentItem.inuse)
            {
                cout << currentItem.name;
                cout << "\n";
            }

        }

        cin.get();//next screen

        ///exit possibility
        //do they want to continue and manage the inventory
        cout << "\n\nDo you want to manage your inventory or EXIT the inventory?";
        cout << "\nType in 'e' if you wish to EXIT or any other key to CONTINUE: ";
        cin >> exit;
        cin.get();
        system("CLS"); //clear the screen

        while(exit != 'e' && exit != 'E')
        {
            do
            {
                cout << "Here are all the items in your inventory again: ";
                cout << "\n";
                index = 0;

                //show the list
                for (InventoryClass::itemsIterator = listOfItems.begin(); InventoryClass::itemsIterator != listOfItems.end(); InventoryClass::itemsIterator++)
                {
                    item currentItem;
                    //read out the item by accessing the list then the item that is in the list then the name attached
                    //cout the index number before each item to access it
                    currentItem = *InventoryClass::itemsIterator;
                    cout << index << ". " << currentItem.name << "\n";

                    //add one to index
                    index++;
                }

                error = false;
                //let them enter in the number they want to use
                cout << "\n\nEnter the number that is next to the item you want to edit or view: ";
                cin >> index;
                cin.get();

                InventoryClass::itemsIterator = listOfItems.begin();

                //if the number they entered is not valid give them an error message
                if (index > listOfItems.size())
                {
                    cout << "\nThe number you entered is invalid. Please enter again.";
                    error = true;
                }

            }while(error == true);

            //tell them what item they choose
            for(int loopcounter = 0; loopcounter <= index; ++loopcounter)
            {

                //if the item is the one the user wants
                if(loopcounter == index)
                {
                    InventoryClass::chosenItemPtr = &*InventoryClass::itemsIterator;
                    cout << "\n\nThe item you choose is: ";
                    cout << InventoryClass::chosenItemPtr->name;
                }
                itemsIterator++;

            }

            cin.get(); //next text block

            do
            {
                error = false;
                //ask them what they want to do - delete, read more, unequip or equip and let them enter it in
                ///letting them manage their inventory
                cout << "\nENTER the letter next to the action you want to do.";
                cout << "\nt/Throw out the item";
                cout << "\nr/read about the item";
                cout << "\nu/Un-equip the item";
                cout << "\ne/equip/use the item";
                cout << "\nEnter here: ";
                cin >> manageAction;
                cin.get();

                //if they type in the wrong letter
                if(manageAction != 't' && manageAction != 'r' && manageAction != 'u' && manageAction != 'e')
                {
                    cout << "\nThe letter you entered was invalid. Please enter again.";
                    cout << "\n";
                    error = true;
                }

            }while(error == true);

            ///deleting an item
            //if they want to delete the item - must delete one from index, clear screen, reread out the list after deleting is finished
            if (manageAction == 't')
            {
                system("CLS"); //clear the screen
                cout << "You throw out the item and your back feels a bit lighter here's what is left:\n";

                //if the item is equipped - unequip it and subtract from the equipped items
                if(InventoryClass::chosenItemPtr->inuse)
                {
                    InventoryClass::chosenItemPtr->inuse = false; //unequip the item
                    InventoryClass::equipped = InventoryClass::equipped - 1; //subtract from the equipped items

                    //if the stats to go with the deletion
                    //if it modifies strength
                    cout << "\nthe item you threw out was equipped. Here is how it effected your stats: ";
                    if (InventoryClass::chosenItemPtr->type == 'w')
                    {
                        cout << "\n\n   STRENGTH: " << player.strength;
                        player.strength = player.strength - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.strength;
                    }

                    //if it modifies defense
                    else if(InventoryClass::chosenItemPtr->type == 'c')
                    {
                        cout << "\n\n   DEFENSE: " << player.defense;
                        player.defense = player.defense - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.defense;
                    }

                    //if it modifies intelligence
                    else if(InventoryClass::chosenItemPtr->type == 'i')
                    {
                        cout << "\n\n   INTELLIGENCE: " << player.intelligence;
                        player.intelligence = player.intelligence - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.intelligence;
                    }

                    //if it  modifies resistance
                    else if (InventoryClass::chosenItemPtr->type == 'r')
                    {
                        cout << "\n\n   RESISTANCE: ";
                        player.resistance = player.resistance - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.resistance;
                    }

                }

                //set the iterator back
                InventoryClass::itemsIterator--;

                //delete the item
                listOfItems.erase(InventoryClass::itemsIterator);

                index = 0; //clear the index
                cout << "\n\n";

                //show them the new inventory
                for (InventoryClass::itemsIterator = listOfItems.begin(); InventoryClass::itemsIterator != listOfItems.end(); InventoryClass::itemsIterator++)
                {
                    item currentItem;

                    //read out the item by accessing the list then the item that is in the list then the name attached
                    //cout the index number before each item to access it
                    currentItem = *InventoryClass::itemsIterator;
                    cout << index << ". " << currentItem.name << "\n";

                    //add one to index
                    index++;
                }


            }

            ///reading more about an item
            //if they want to read more about an item
            else if (manageAction == 'r')
            {
                system("CLS");
                cout << "\n" << InventoryClass::chosenItemPtr->name;
                //read out how much of the stat if modifies
                cout << "\nAdds " << InventoryClass::chosenItemPtr->modifyStat << " -->  ";

                //read out what it modifies
                //if it modifies strength
                if (InventoryClass::chosenItemPtr->type == 'w')
                {
                    cout << " STRENGTH.";
                }

                //if it modifies defense
                else if(InventoryClass::chosenItemPtr->type == 'c')
                {
                    cout << " DEFENSE.";
                }

                //if it modifies hp
                else if(InventoryClass::chosenItemPtr->type == 'h')
                {
                    cout << " HP.";
                }

                //if it modifies intelligence
                else if(InventoryClass::chosenItemPtr->type == 'i')
                {
                    cout << " INTELLIGENCE.";
                }

                //if it  modifies resistance
                else if (InventoryClass::chosenItemPtr->type == 'r')
                {
                    cout << " RESISTANCE.";
                }

            }

            ///to unequip an item
            //if they want to unequip an item
            else if (manageAction == 'u')
            {

                if(InventoryClass::chosenItemPtr->inuse)
                {
                    //set in use to false
                    InventoryClass::chosenItemPtr->inuse = false;

                    //edit equipped items
                    InventoryClass::equipped--;

                    //change the stats accordingly
                    //if it modifies strength
                    if (InventoryClass::chosenItemPtr->type == 'w')
                    {
                        cout << "\n\n" <<InventoryClass::chosenItemPtr->name << " has been unequipped.";
                        cout << "\n\n   STRENGTH: " << player.strength;
                        player.strength = player.strength - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.strength;
                    }

                    //if it modifies defense
                    else if(InventoryClass::chosenItemPtr->type == 'c')
                    {
                        cout << "\n\n" <<InventoryClass::chosenItemPtr->name << " has been unequipped.";
                        cout << "\n\n   DEFENSE: " << player.defense;
                        player.defense = player.defense - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.defense;
                    }

                    //if it modifies intelligence
                    else if(InventoryClass::chosenItemPtr->type == 'i')
                    {
                        cout << "\n\n" <<InventoryClass::chosenItemPtr->name << " has been unequipped.";
                        cout << "\n\n   INTELLIGENCE: " << player.intelligence;
                        player.intelligence = player.intelligence - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.intelligence;
                    }

                    //if it  modifies resistance
                    else if (InventoryClass::chosenItemPtr->type == 'r')
                    {
                        cout << "\n\n" <<InventoryClass::chosenItemPtr->name << " has been unequipped.";
                        cout << "\n\n   RESISTANCE: " << player.resistance;
                        player.resistance = player.resistance - InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.resistance;
                    }
                }
                else
                {
                    cout << "\nThat Item is already unequipped";
                }
            }


            ///using for equipping an item
            //if they want to use an item
            else if (manageAction == 'e')
            {
                //if the item is already in use
                if(InventoryClass::chosenItemPtr->inuse)
                {
                    cout << "\nThat item is already equipped";
                }

                //check to see if they have room to equip
                else if(InventoryClass::equipped == 3)
                {
                    cout << "\nYou cannot equip or use any more items.";
                }

                //if the item can be equipped
                else
                {
                    //set use to true
                    InventoryClass::chosenItemPtr->inuse = true;
                    InventoryClass::equipped++;

                    //modify stats
                    if (InventoryClass::chosenItemPtr->type == 'w')
                    {
                        cout << "\n\n" << InventoryClass::chosenItemPtr->name << " has been equipped.";
                        //show how much the equip effected the stats
                        cout << "\n\n  STRENGTH: " << player.strength;
                        player.strength = player.strength + InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.strength;

                        //set inuse
                        InventoryClass::chosenItemPtr->inuse = true;
                    }

                    //if it modifies defense
                    else if(InventoryClass::chosenItemPtr->type == 'c')
                    {
                        cout << "\n\n" << InventoryClass::chosenItemPtr->name << " has been equipped.";
                        //show how much the equip effected the stats
                        cout << "\n\n   DEFENSE: " << player.defense;
                        player.defense = player.defense + InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.defense;

                        //set inuse
                        InventoryClass::chosenItemPtr->inuse = true;
                    }

                    //if it modifies hp
                    else if(InventoryClass::chosenItemPtr->type == 'h')
                    {
                        InventoryClass::equipped--; //subtract from equipped

                        //show how much the equip effected the stats
                        //use the hp potion
                        if(player.maxHP - InventoryClass::chosenItemPtr->modifyStat > player.HP)
                        {
                            cout << "\n\n   HP: " << player.HP;
                            player.HP = player.HP + InventoryClass::chosenItemPtr->modifyStat;
                            cout << "  -->  " << player.HP;
                        }
                        else if(player.maxHP - InventoryClass::chosenItemPtr->modifyStat <= player.HP)
                        {
                            cout << "\n\n   HP: " << player.HP;
                            player.HP = player.maxHP;
                            cout << "  -->  " << player.HP;
                        }

                        cout << "\nHP has been recovered.";
                        //delete the item from the inventory after
                        //set the iterator back
                        InventoryClass::itemsIterator--;

                        //delete the item
                        listOfItems.erase(InventoryClass::itemsIterator);

                        index = 0; //clear the index


                    }

                    //if it modifies intelligence
                    else if(InventoryClass::chosenItemPtr->type == 'i')
                    {
                        cout << "\n\n" << InventoryClass::chosenItemPtr->name << " has been equipped.";
                        //show how much the equip effected the stats
                        cout << "\n\n   INTELLIGENCE: " << player.intelligence;
                        player.intelligence = player.intelligence + InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.intelligence;

                        //set inuse
                        InventoryClass::chosenItemPtr->inuse = true;
                    }

                    //if it  modifies resistance
                    else if (InventoryClass::chosenItemPtr->type == 'r')
                    {
                        cout << "\n\n" << InventoryClass::chosenItemPtr->name << " has been equipped.";
                        //show how much the equip effected the stats
                        cout << "\n\n   RESISTANCE: " << player.resistance;
                        player.resistance = player.resistance + InventoryClass::chosenItemPtr->modifyStat;
                        cout << "  -->  " << player.resistance;

                        //set inuse
                        InventoryClass::chosenItemPtr->inuse = true;
                    }

                    //show the items that are equipped
                    cout << "\n\nHere are your equipped items: ";

                    //tell them the items they have equipped
                    cout << "\n\n";
                    cout << InventoryClass::equipped << " /3 items are equipped:";
                    cout << "\n";

                    for(InventoryClass::itemsIterator = listOfItems.begin(); InventoryClass::itemsIterator != listOfItems.end(); InventoryClass::itemsIterator++)
                    {
                        item currentItem;
                        //set the current item to
                        currentItem = *InventoryClass::itemsIterator;

                        //if the item is in use
                        if(currentItem.inuse)
                        {
                            cout << currentItem.name;
                            cout << "\n";
                        }

                    }
                }
            }

            //if they want to go through the loop again
            cout << "\n\nDo you still want to manage your inventory?";
            cout << "\nType in 'exit' if you wish to exit or any key to continue: ";
            cin >> exit;
            cin.get();
            system("CLS");

        }

    }

    ///if they are in battle
    else if (InventoryClass::inOrOutBattle == true )
    {

    }

    //if they want to exit
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

    //so it doesn't run twice
    InventoryClass::addOrManage = 'c';

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
    bool chestNegative11 = false;
    bool chest11 = false;

    /* Out of battle */
    if (InventoryClass::inOrOutBattle == false)
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
    else if (InventoryClass::inOrOutBattle == true)
    {
        ///in battle
        int generatedNum = 0; //holds the number generated
        int rareItemGenerator = 0; //holds the number that will determine if the item will rare or not

        //assign a number to each item that is not yet been assigned a chest or to the main character yet
        rareItemGenerator = (rand()%10) + 1;

        //60% chance of getting a normal item
        if(rareItemGenerator < 7)
        {
            generatedNum = (rand()%7)+1;
        }

        //40% chance of getting a rare item
        else if(rareItemGenerator >= 7)
        {
            generatedNum = (rand()%15)+8;
        }

        //debug cout << "The number generated was" << generatedNum;
        //get a random number from that pool and then use the item that corresponds with it


        //if this is their first time running the program
    }

    //so it doesn't run twice
    InventoryClass::addOrManage = 'c';

    //return back to the main game

}
