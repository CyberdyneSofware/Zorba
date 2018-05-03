#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
#include "rooms.h"
#include <cstring>
#include <iostream>

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
    do
    {
        roomplace();
        cout << cordx << ":X\n" << cordy << ":Y\n";
    cout << "What direction are you going?:\n";
    cin >> movement;
        if(movement == "NORTH")//movement for north
        {
            cordy = cordy + 1;
        }

        else if(movement == "SOUTH")//move for south
        {
            cordy = cordy - 1;
        }

        else if(movement == "EAST")//move for east
        {
            cordx = cordx + 1;
        }

        else if(movement == "WEST")//move for west
        {
            cordx = cordx - 1;
        }
        else
        {
            cout << "Invalid Direction\n";
        }


    }while(movement != "EXIT");
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
    else if((cordy == 0)&&(cordx == 3))
    {
        mboss();
    }
    else
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
}
/*void badtile()//reverses the player in whatever direction they came from
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
}*/
#endif // MOVE_H_INCLUDED
