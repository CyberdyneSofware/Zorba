#include <iostream>
#include <string.h>
#include <list>
#include "InventoryClass.h"
#include "Item.h"

using namespace std;

int cordx, cordy; //holds the x and y coordinates globally for the mean time
//global variables - add to the command file when you take out main



int main()
{
    //this is a temporary file which allows you to test the inventory code while it's being written
    //from here the program will go to the inventory command - when actually running this please remove this file

    InventoryClass run; //runs the function from the class
    int battletest; // lets you enter in what you want to test for battle

    /**
    To go on to the program i will need.. the addOrManage variable to be set to either 'a' or 'b'
    the coordinates to be set
    the addOrManage variable to be set to either 'a' or 'b'
    'a' meaning adding an item
    'b' meaning managing inventory
    please pass addOrManage through the function InventoryCommand(addOrManage) with the right letter so that the inventory command will know where to go
    **/

    cout << "This is the test file for the inventory: please enter in the information which cannot be inferred at this time\ndue to this being a test file.";
    cout << "\nEnter the x coordinate here: ";
    cin >> cordx;
    cin.get();
    cout << "\nEnter the y coordinate here: ";
    cin >> cordy;
    cin.get();
    cout << "\nEnter the letter for what you are testing here a/adding an item, b/managing inventory: ";
    cin >> InventoryClass::addOrManage;
    cin.get();
    cout << "\nEnter 0 if you are testing out of battle options or 1 if you are testing in battle options: ";
    cin >> battletest;
    cin.get();
    if (battletest == 0)
    {
        InventoryClass::inOrOutBattle = false;
    }
    if(battletest == 1)
    {
        InventoryClass::inOrOutBattle = true;
    }



    //go to the main code - this is where it would go when you actually take out the main
    run.InventoryCommand();

    return 0;
}
