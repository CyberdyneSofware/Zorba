#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

//Phillip King - Cyberdyne Sofware - 5/22/20XX
//This is actually more of the commands file, but it mostly movement

#include "rooms.h"//Functions for all the rooms

#include <ctype.h>
#include <iostream>
#include <stdio.h>


using namespace std;

//function definitions
void move1();// Commands and Movement function
void roomplace();//Function decides what room you're in
void badtile();//Reverses the play from where the came if they, say, ran into a wall
//global variables
string movement;// Global Variable - Command letter

void move1()
{
    int health;
    player.HP = health;
    do{
    roomplace();
    cout << "You are in X: " << InventoryClass::cordx <<" and Y: " << InventoryClass::cordy << "\n";// Displays the Coordinates of where the player is
    cout << "Type a command: ";
    cin >> movement;

    if((movement == "NORTH")||(movement == "N"))//movement for north
    {
        InventoryClass::cordy = InventoryClass::cordy + 1;
    }

    else if((movement == "SOUTH")||(movement == "S"))//move for south
    {
        InventoryClass::cordy = InventoryClass::cordy - 1;
    }
    else if((movement == "EAST")||(movement == "E"))//move for east
    {
        InventoryClass::cordx = InventoryClass::cordx + 1;
    }

    else if((movement == "WEST")||(movement == "W"))//move for west
    {
        InventoryClass::cordx = InventoryClass::cordx - 1;
    }
    else if(movement == "I")
    {
        cout << "thicc";
        //makkie's Inventory set to b
    }
    else if(movement == "M")//Shows the Map
    {
        maps();
    }
    else if(movement == "L")// Look command
    {
        roomplace();
    }
    else
    {
        cout << "Invalid command\n";
    }
    mon();
    close();
    }while(movement != "EXIT");
}

void roomplace()
{
    if ((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 0))//enterance cord: (0,0)
    {
        enterance();
    }
    else if((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 1))//main hall cord:(0,1)
    {
        main_hall();
    }
    else if((InventoryClass::cordx == -1)&&(InventoryClass::cordy == 1))//puzzle 1 cord:(-1,1)
    {
        puzzle1();
    }
    else if((InventoryClass::cordx == 1)&&(InventoryClass::cordy == 1))//puzzle 2 cord (1,1)
    {
        puzzle2();
    }
    else if((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 2))//Mini Boss Putin cord: (0,2)
    {
        mboss();
    }
    else if((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 3))//Third Puzzle cord: (0,3)
    {
        puzzle3();
    }
    else if((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 4))//hitler's office cord:(0,4)
    {
        hitler1();
    }
    else//anything that isn't a room
    {
        badtile();
    }

}
void badtile()//reverses the player in whatever direction they came from
{
    cout << "You run into a wall, like a dingo. Blame Vivian, I guess.\n";
    if(movement == "N")//reverse movement for north
    {
        InventoryClass::cordy = InventoryClass::cordy - 1;
    }

    else if(movement == "S")//reverse move for south
    {
        InventoryClass::cordy = InventoryClass::cordy + 1;
    }

    else if(movement == "E")//reverse move for east
    {
        InventoryClass::cordx = InventoryClass::cordx - 1;
    }

    else if(movement == "W")//reverse move for west
    {
        InventoryClass::cordx = InventoryClass::cordx + 1;
    }

}
#endif // MOVE_H_INCLUDED
