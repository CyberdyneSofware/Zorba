#include <iostream>
#include <string.h>
#include <list>
#include<stdlib.h>

#include "InventoryClass.h"

using namespace std;



int main()
{
    //this is a temporary file which allows you to test the inventory code while it's being written
    //from here the program will go to the inventory command - when actually running this please remove this file

    InventoryClass run; //runs the function from the class
    int battletest; // lets you enter in what you want to test for battle

    /**
    PLEASE IMPLEMENT THIS INTO YOUR CODE IF YOU ARE ADDING IT TO THE FIGHT CODE OR THE MAIN CODE
    please add....
    #include "InventoryClass.h"

    a object called InventoryClass run; you will use this to be calling the inventory command
    when you want to do anything with the inventory please call run.InventoryCommand

    the InventoryClass::inOrOutBattle variable should be set to either true or false
    true meaing that a battle is running a the current moment
    or false meaning there is no battle running at the current moment
    the variable will be automatically set to false.

    the InventoryClass::addOrManage variable to be set to either 'a' or 'b'
    'a' meaning adding an item
    'b' meaning managing inventory

    please add....
    #include "InventoryClass.h"

    a object called InventoryClass run; you will use this to be calling the inventory command
    when you want to do anything with the inventory please call run.InventoryCommand

    the InventoryClass::inOrOutBattle variable should be set to either true or false
    true meaing that a battle is running a the current moment
    or false meaning there is no battle running at the current moment
    the variable will be automatically set to false.

    the InventoryClass::addOrManage variable to be set to either 'a' or 'b'
    'a' meaning adding an item
    'b' meaning managing inventory

    **/

    cout << "This is the test file for the inventory: please enter in the information which cannot be inferred at this time\ndue to this being a test file.";
    cout << "\nEnter the x coordinate here: ";
    cin >> InventoryClass::cordx;
    cin.get();
    cout << "\nEnter the y coordinate here: ";
    cin >> InventoryClass::cordy;
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

    system("CLS"); //clear the screen

    //go to the main code - this is where it would go when you actually take out the main
    run.InventoryCommand();

    cout << "\n\nThanks for running the test";
    return 0;
}
