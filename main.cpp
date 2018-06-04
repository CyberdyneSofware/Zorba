//set in or out of battle to true or false then add or manage to a or b depending if you're adding or managing
#define _WIN32_WINNT 0x0501
//Triple Entente 2018
#include <iostream>
#include <cstring>
#include <windows.h>
#include <math.h>
#include <ctype.h>

#include "Fight.h"
#include "move.h"

using namespace std;

void menu();
int main();
void begining();

void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

void menu()
{
    MaximizeOutputWindow();
    cout << "                                                                                           .\n";
    cout << "                                                                                          /y.\n";
    cout << "                                                                                         .s/\n";
    cout << "                                                                           ----/---::---+oy/-::---::--:\n";
    cout << "                                                                          -oosyh+sshosssyoysshsssyhossh-\n";
    cout << "                                                                         `+syydysyhhsyyh+syyhdsyydysyho\n";
    cout << "                                                                         oossyyossysssy+/hsshsssyd+ysd.\n";
    cout << "                                                                        `oosshsssso//so./++shossdossy/\n";
    cout << "                                                              .........::/ossyysssys:..  .:oysosydossh:..\n";
    cout << "                                                           ////sssyhyyyyysssssso+///-     -////ossssssos+:--.\n";
    cout << "                                                                 `````/sssyyoyydo/:- -+::s+yyhyossy+\n";
    cout << "                                                                      `/yssdssshd+/y/.sysyossydssshs\n";
    cout << "                                                                     /sssyhoyydosys-shsydoyyhysyyy:\n";
    cout << "                                                                    `osssdosshyosy++ysshyssshsssy/\n";
    cout << "                                                                    `yyyyhsyyhoyyyoyyyyhssyyysyyo.\n";
    cout << "                                                                       ```````````+yh/````````````\n";
    cout << "                                                                                  `hy/`\n";
    cout << "                                                                                 -dh-\n";
    cout << "                                                                                 hm/\n";


    cout << "                                                  _____     _           ____                 _____     ___ _                     \n";
    cout << "                                                 |     |_ _| |_ ___ ___|    \\ _ _ ___ ___   |   __|___|  _| |_ _ _ _ ___ ___ ___ \n";
    cout << "                                                 |   --| | | . | -_|  _|  |  | | |   | -_|  |__   | . |  _|  _| | | | .'|  _| -_|\n";
    cout << "                                                 |_____|_  |___|___|_| |____/|_  |_|_|___|  |_____|___|_| |_| |_____|__,|_| |___|\n";
    cout << "                                                       |___|                 |___|                                               \n";

    Sleep(3000);
    cout << "                                                                                          Presents";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    system("CLS");



    int what;
    cout <<"                                                           8888888888P .d88888b.  88888888b. 8888888b.        d8888\n";
    cout <<"                                                                d88P  d88P   Y88b 888   Y88b 888   88b       d88888\n";
    cout <<"                                                               d88P   888     888 888    888 888  .88P      d88P888\n";
    cout <<"                                                              d88P    888     888 888   d88P 8888888K.     d88P 888\n";
    cout <<"                                                             d88P     888     888 8888888P   888   Y88b   d88P  888\n";
    cout <<"                                                            d88P      888     888 888 T88b   888    888  d88P   888\n";
    cout <<"                                                           d88P       Y88b. .d88P 888  T88b  888   d88P d8888888888\n";
    cout <<"                                                          d8888888888   Y88888P   888   T88b 8888888P  d88P     888\n\n";

    system("pause");
    cout << "REMEMBER: Type all commands in capital or you're a boob and type exit to quit the game\n";
    system("pause");
    system("CLS");
    allotAP();
}

InventoryClass runmain; //object for running the inventory

int main()
{

    menu();
    do{
        //inventory call
        //Inventory - chest
        InventoryClass::addOrManage = 'a';
        InventoryClass::inOrOutBattle = false;
        runmain.InventoryCommand();

        //moved to here so they can see the commands every time
        cout << "Commands:\n N - North\n E - East\n S - South\n W - West\n I - Open inventory\n L - A description of the room you're in\n M - Map of the Dungeon\n";
        move1();
    }while(movement != "EXIT");

    return 0;
}


