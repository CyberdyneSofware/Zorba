#ifndef ROOMS_H_INCLUDED
#define ROOMS_H_INCLUDED
#include "move.h"
int puzzle=0;

void enterance()//Entrance Tile
{
    int player = 0;
    cout << "You are in the entrance, there is a door to the north\n";
}
void main_hall()//main hall
{
    int player = 0;
    cout << "This is the main hall, there are broken tables and junk everywhere, it looks like its been abandoned for years\n";
    cout << "There is an entrance to the NORTH, EAST, SOUTH, and WEST\n";
}
void puzzle1()//puzzle room 1, contains what to say in the main hall
{
    cout <<"This looks like a storage room, there are lots of barrels and crates all around the room.\n";
    cout <<"There is writing on the wall, it says 'Say my name, Say my name, Say my name\n";
}
void puzzle2()//puzzle room 2, contains a statue with the name "Shakira" when the player types "Say my name"
{
    char name[10];
    cout << "This room is empty, other than a statue with a strange man with a weird mustache\n";
    if (name == "Shakira")
    {

        cout << "The statue begins to rumble and raise up, reveling letters carved into stone that say: To fight the boss you must type the magic word\n";
    }
}
void mboss()//This is the room where the mini-boss is
{
    char pass[10];
    cout << "A deep, sexy, powerful Russian voice speaks to you 'Whats the password?'\n";
    cin.get(pass,10,'\n');
    if (pass == "PLEASE")
    {
        cout << "'Very good' Says the hot, sexy voice answers and the large wooden doors open\n";
        cout << "Good load is Putin! The reaper of the Siberian plains! The door locks behind you and Putin is blocking the exit!\n";
    }
    if(pass!="PLEASE")
    {
        cout << "'Cyka Blyat, thats the wrong answer' The voice says as a wind pushes you back";

    }
}




#endif // ROOMS_H_INCLUDED
