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
    struct nothin //Room tiles titles
    {
        string entrance = "The entrance room";
        string mainhall = "The main hall";
        string puzzle1 = "The Storage room";
        string puzzle2 = "The Statue room";
        string miniboss = "Putian's Masterbatorium";
        string mazetile = "The Minotaurs Maze";
        string Hurtler = "Hurtler's Office";
    };
    nothin = roomtitles;
    do
    {
    roomplace();
    cout << cordx << ":X and " << cordy << ":Y\n You are in the: ";
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
    else if((cordy == 0)&&(cordx == 2))
    {
        test();
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
