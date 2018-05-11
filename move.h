#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
#include "rooms.h"
#include "Fight.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>
using namespace std;
//definitions
void move1();
void roomplace();
void badtile();
//global
float cordy = 0;
float cordx = 0;
string movement;

void move1()
{
    int i=0;
    char c;
    cout << "Type a direction: ";
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
        else
        {
            cout << "Invalid Direction\n";
        }
        mon();
}

void roomplace()
{
    if ((cordy == 0)&&(cordx == 0))
    {
        enterance();
    }
    else if((cordy == 1)&&(cordx == 0))
    {
        main_hall();
    }
    else if((cordy == 1)&&(cordx == -1))
    {
        puzzle1();
    }
    else if((cordy == 1)&&(cordx == 1))
    {
        puzzle2();
    }
    else if((cordy == 2)&&(cordx == 0))
    {
        mboss();
    }
    else
    {
        badtile();
    }
}
void badtile()//reverses the player in whatever direction they came from
{
    cout << "You run into a wall, like a dingo. Blame Vivian, I guess.\n";
    if(movement == "NORTH")//reverse movement for north
    {
        cordy = cordy - 1;
    }

    else if(movement == "SOUTH")//reverse move for south
    {
        cordy = cordy + 1;
    }

    else if(movement == "EAST")//reverse move for east
    {
        cordx = cordx - 1;
    }

    else if(movement == "WEST")//reverse move for west
    {
        cordx = cordx + 1;
    }
}
#endif // MOVE_H_INCLUDED
