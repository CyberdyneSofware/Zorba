//Triple Entente 2018
#include <iostream>
#include "menu.h"
#include "Description.h"
#include <cstring>
#include <windows.h>
#include "items.h"
#include "move.h"
#include <math.h>
using namespace std;

void begining();
int main()
{
    menu();
    string command;
    //tile(int mookz)
    do{
        /*
          Commands are as Follows:
          GRAB(Adds Item to inventory)
          LOOK(Gives a description of the area)
          ATTK(rolls dice for damage)
          MOVE(Moves to a tile)
          USE(Uses an item)
        */
        cout <<"You are in x: " << cordx << " and in y: " << cordy << "\n";
        cout << "\nEnter a command: ";
        cin.get();
        cin >> command;


        if(command == "OPEN")//opening a chest
        {
            char choice = 'a';
            //inventorycommand();
        }
        else if(command == "LOOK")//describes the room that the player is in
        {
            direction();
        }
        else if(command == "USE")
        {

        }
        else if(command == "MOVE")
        {
            moving();
        }
        else if(command == "HELP")
        {
            cout << "Commands are:\n - GRAB [Item] - Grabs and item in the tile you're in\n - LOOK - Gives a description of the tile your in, and tells you what items are in the tile you're in\n - ATTK - Attacks an enemy in the tile you're in\n - MOVE [Direction] - Moves to a tile North, East, South, or West\n - EXIT - Exits the game, and returns you to MS-DOS\n";
        }
    }while(command != "EXIT");

    return 0;
}
