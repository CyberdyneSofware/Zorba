//Phillip King - Cyberdyne Sofware - 5/22/20XX
//This is actually more of the commands file, but it mostly movement

#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "rooms.h"//Functions for all the rooms
#include "Fight.h"//Taylor's Fight code
#include <ctype.h>
#include <iostream>
#include <stdio.h>

using namespace std;

//function definitions
void move1();// Commands and Movement function
void roomplace();//Function decides what room you're in
void badtile();//Reverses the play from where the came if they, say, ran into a wall
//global variables
float cordy = 0;
float cordx = 0;
string movement;// Global Variable - Command letter

void move1()
{
    roomplace();
    cout << "You are in X: " << cordx <<" and Y: " << cordy << "\n";// Displays the Coordinates of where the player is
    cout << "Type a command: ";
    cin >> movement;

    if((movement == "NORTH")||(movement == "N"))//movement for north
    {
        cordy = cordy + 1;
    }

    else if((movement == "SOUTH")||(movement == "S"))//move for south
    {
        cordy = cordy - 1;
    }
    else if((movement == "EAST")||(movement == "E"))//move for east
    {
        cordx = cordx + 1;
    }

    else if((movement == "WEST")||(movement == "W"))//move for west
    {
        cordx = cordx - 1;
    }
    else if(movement == "I")
    {
        cout << "thicc";
        //makkie's Inventory set to b
    }
    else if(movement == "M")
    {
        maps();
    }
    else if(movement == "L")
    {
        roomplace();
    }
    else
    {
        cout << "Invalid command\n";
    }
    mon();
}

void roomplace()
{
    if ((cordx == 0)&&(cordy == 0))//enterance cord: (0,0)
    {
        enterance();
    }
    else if((cordx == 0)&&(cordy == 1))//main hall cord:(0,1)
    {
        main_hall();
    }
    else if((cordx == -1)&&(cordy == 1))//puzzle 1 cord:(-1,1)
    {
        puzzle1();
    }
    else if((cordx == 1)&&(cordy == 1))//puzzle 2 cord (1,1)
    {
        puzzle2();
    }
    else if((cordx == 0)&&(cordy == 2))//Mini Boss Putin cord: (0,2)
    {
        mboss();
    }
    else if((cordx == 0)&&(cordy == 3))//Third Puzzle cord: (0,3)
    {
        puzzle3();
    }
    else if((cordx == 0)&&(cordy == 3))//hitler's office cord:(0,4)
    {
        hitler();
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
        cordy = cordy - 1;
    }

    else if(movement == "S")//reverse move for south
    {
        cordy = cordy + 1;
    }

    else if(movement == "E")//reverse move for east
    {
        cordx = cordx - 1;
    }

    else if(movement == "W")//reverse move for west
    {
        cordx = cordx + 1;
    }

}
#endif // MOVE_H_INCLUDED
