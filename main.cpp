#include <iostream>
#include "InventoryCommand.h"
#include "InventoryClass.h"

#include <list>

using namespace std;

int main()
{
    //this is a temporary file which allows you to test the inventory code while it's being written
    inventoryClass run; //variable for the class
    cout << "This is the test file for the inventory: you may choose to do three different things.";
    cout << "\na/Adding to inventory";
    cout << "\nb/Managing inventory (selecting/deleting)";
    cout << "Enter here: ";
    cin >> run.choice;
    cin.get();
    run.inventoryCommand(choice);

    return 0;
}
