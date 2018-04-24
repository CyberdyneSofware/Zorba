#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
#include "rooms.h"
void menu();
void direction();
void moving();
void badtile();
void mon();
string movement;
struct cord
{
    int cordy = 0;
    int cordx = 0;
};
cord cord1;
void direction()
{
    //commands(&cordy,&cordx)
    if ((cord1.cordy == 0)&&(cord1.cordx == 0))
    {
        enterance();
    }
    else if((cord1.cordy == 1)&&(cord1.cordx == 0))
    {
        main_hall();
    }
    else if((cord1.cordy == 1)&&(cord1.cordx == -1))
    {
        puzzle1();
    }
    else if((cord1.cordy == 1)&&(cord.cordx == 1))
    {
        puzzle2();
    }
    else if((cord.cordy = 0)&&(cord.cordx = 3))
    {
        mboss();
    }
    else
    {
        badtile();
    }

}

void moving()
{
        cin >> movement;
        if(movement == "NORTH")//movement for north
        {
            cord.cordy = cord.cordy + 1;
        }

        else if(movement == "SOUTH")//move for south
        {
            cord.cordy = cord.cordy - 1;
        }

        else if(movement == "EAST")//move for east
        {
            cord.cordx = cord.cordx + 1;
        }

        else if(movement == "WEST")//move for west
        {
            cord.cordx = cord.cordx - 1;
        }
        else
        direction();
        mon();
}
void mon()
{
    int yon;//random whether you run into a monster or not
    yon = rand() % 2 + 1;
    if(yon == 1)
    {
        cout << "You ran into a mook!!! \n";
        system("pause");
        //something
    }
    if(yon == 2)
    {
        cout << "\n";
    }
}
void badtile()//reverses the player in whatever direction they came from
{
    cout << "You run into a wall, like a dingo. Blame Vivian, I guess.\n";
    if(movement == "NORTH")//reverse movement for north
    {
        cord.cordy = cord.cordy - 1;
    }

    else if(movement == "SOUTH")//reverse move for south
    {
        cord.cordy = cord.cordy + 1;
    }

    else if(movement == "EAST")//reverse move for east
    {
        cord.cordx = cord.cordx - 1;
    }

    else if(movement == "WEST")//reverse move for west
    {
        cord.cordx = cord.cordx + 1;
    }
}

#endif // MOVE_H_INCLUDED
