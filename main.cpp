#include <iostream>
#include <string.h>
#include <list>
#include "InventoryClass.h"

using namespace std;

int x, y; //holds the x and y coordinates globally for the mean time
//global variables - add to the command file when you take out main
char addOrManage; //global variable for adding or managing to the item list 'a' for adding 'b' for managing

int main()
{
    //this is a temporary file which allows you to test the inventory code while it's being written
    //from here the program will go to the inventory command - when actually running this please remove this file

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
    cin >> x;
    cin.get();
    cout << "\nEnter the y coordinate here: ";
    cin >> y;
    cin.get();
    cout << "Enter the letter for what you are testing here a/adding an item, b/managing inventory: ";
    cin >> addOrManage;
    cin.get();



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


    return 0;
}
