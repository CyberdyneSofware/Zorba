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
extern void move1();// Commands and Movement function
extern void roomplace();//Function decides what room you're in
extern void badtile();//Reverses the play from where the came if they, say, ran into a wall
//global variables
extern string movement;// Global Variable - Command letter

#endif // MOVE_H_INCLUDED
