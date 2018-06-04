#include "move.h"
#include "Fight.h"

using namespace std;

string movement;

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
    if ((InventoryClass::cordx == 0)&&(InventoryClass::cordy == 0))//entrance cord: (0,0)
    {
        entrance();
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
