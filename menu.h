//Triple Entente 201X || 2017-18
#ifndef MENU2_H_INCLUDED
#define MENU2_H_INCLUDED
#include <iostream>
#include <windows.h>
using namespace std;

void menu()
{
    int what;
    cout <<"          8888888888P  .d88888b.  8888888b.  888888b.        d8888\n";
    cout <<"               d88P  d88P   Y88b 888   Y88b 888   88b       d88888\n";
    cout <<"              d88P   888     888 888    888 888  .88P      d88P888\n";
    cout <<"             d88P    888     888 888   d88P 8888888K.     d88P 888\n";
    cout <<"            d88P     888     888 8888888P   888   Y88b   d88P  888\n";
    cout <<"           d88P      888     888 888 T88b   888    888  d88P   888\n";
    cout <<"          d88P       Y88b. .d88P 888  T88b  888   d88P d8888888888\n";
    cout <<"         d8888888888   Y88888P   888   T88b 8888888P  d88P     888\n\n";
    cout <<"                          1. New game\n";
    cout <<"                          2. Load game\n";
    cout << "                                      ";
    cin >> what;

    if(what == 1)
    {
    cout << "";
    cout << "REMBER: Type all commands in capital or you're a boob\n";
    system("pause");
    system("CLS");
    }
    if(what == 2)
    {
        cout << "Still working on lots of the game so you can't load anything yet\n";
        system("pause");
        system("CLS");
        menu();
    }
    /*else
    {
        cout << "\nDude, what the f*ck, the game's not working. Welp, I guess there's more sh*t to be done you just get to work fixing that, I'll just be jacking off in a corner";
    }*/

}


#endif // MENU2_H_INCLUDED
