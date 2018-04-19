#ifndef INVENTORYCLASS_H_INCLUDED
#define INVENTORYCLASS_H_INCLUDED

#include "InventoryCommand.h"

#include <list>
#include <iostream>

using namespace std;

class InventoryClass
{
public:
    //functions
    void AddItem(); //add an item to the list
    void SelectItem(); //use an item
    void DeleteItem(); //delete an item

private:

    /* Items  */

    /****
    Type:
    weapon = 'w'
    clothing = 'c'
    buff = 'b'
    debuff = 'd'
    ****/

    string name; //stores the name
    char type; //stores the type of the item
    int modifyStat; //how much the item should modify
    bool inuse; //if the item is in use or not
    string message; //the message that plays when you equip it


    //weapons
    struct stick
    {
       //name stick.name holds the name
       name = "Stick";

       //type
       type = 'w';

       //how much it adds or subtracts to stat adds to stats when in use
       modifyStat = 1; //ADD TO DAMAGE

       //in use bool - if false it is not in use - if true it is in use
       inuse = false;

       //message
       message = "Can't wait to see you on the new watchmojo video; top ten worst anime weapons";

    };

    struct basicsword
    {
        //name
        name = "Basic Sword";

        //type
        type = 'w';

        //modify stats
        modifyStat = 3; //ADD TO DAMAGE

        //in use
        inuse = false;

        //message
        message = "Wow maybe you'll actually make a dent in em.";

    };

    struct knife
    {
        //name
        name = "Knife";

        //type
        type = 'w';

        //modify stat
        modifyStat = 2;

        //in use
        inuse = false;

        //message
        message = "Not very useful from far way, but good luck.";
    };

    struct genericgun
    {
        //name
        name = "Generic Gun";

        //type
        type = 'w';

        //modify stat
        modifyStat = 4;

        //in use
        inuse = false;

        //message
        message = "This is gun. Have fun. Pleb.";

    };

    struct dragonslayer
    {
        //name
        name = "Dragon Slayer";

        //type
        type = 'w';

        //modify stat
        modifyStat = 7;

        //in use
        inuse = false;

        //message
        message = "The sword has to be almost 8 feet long and the handle has a bandage wrapped around it, you wonder how anyone can pick this thing up. With a lot of effort you are able to lift it off the ground. On the bandage there is something written in scrambled letters: W arni ng  y ou  must hav e  a tragi c back  s tory to use thi s  weapon.";

    };

    struct thestaff
    {
        //name
        name = "THE Staff";

        //type
        type = 'w';

        //modify stat
        modifyStat = 5;

        //in use
        inuse = false;

        //message
        message = "Not staff as in a worker but staff as in the weapon. It's wooden except for the blade on the end which is steal.";

    };

    struct bootgun
    {
        //name
        name = "Boot Gun";

        //type
        type = 'w';

        //modify stat
        modifyStat = 6;

        //in use
        inuse = false;

        //message
        message = "The weapon is a weirdly shaped boot, you wonder if you can even put it on. attached to the front is what looks like the front of a gun. Written mysteriously on the side with a sharpie is the words: Kick to Shoot.";
    };

    //last weapon in the game helps you defeat the boss, op af, get it at the end of the game
    struct theswordgunknife
    {
        //name
        name = "The Sword Gun Knife";

        //type
        type = 'w';

        //modify stat
        modifyStat = 100;

        //in use
        inuse = false;

        //message
        message = "This is the most OP weapon in the game. It's a sword, a gun, and a knife all at once. Good luck with the last battle!";
    };



    //clothing - add one to defence
    struct tatteredcloth
    {
        //name
        name = "Tattered Cloth";

        //type
        type = 'c';

        //modify stat
        modifyStat = 1;

        //in use
        inuse = false;

        //message
        message = "It has a few questionable holes in it, but otherwise it will shield you from the cold of a cave. Eh, it'll work";
    };

    struct beret
    {
        //name
        name = "Beret";

        //type
        type = 'c';

        //modify stat
        modifyStat = 2;

        //in use
        inuse = false;

        //message
        message = "It looks a bit worn, but kind of neat. Some of the string sewing it together has unraveled and is barely holding a pin to the front. (Are you cosplaying as Phillip?)"
    };

    struct blackandwhitejacket
    {
        //name
        name = "Black and White Jacket";

        //type
        type = 'c';

        //modify stat
        modifyStat = 2;

        //in use
        inuse = false;

        //message
        message = "It is a thin jacket with a zipper in the front, you don't know who left this behind. (You can almost be as edgy as Alexi with this)";

    };

    struct bluehairdye
    {
        //name
        name = "Blue Hair Dye";

        //type
        type = 'c';

        //modify stat
        modifyStat = 1;

        //in use
        inuse = false;

        //message
        message = "It's a tin bottle with neon blue paint across the front, on the top there is a black cap keeping it closed "
    };

    //buffs


    //debuffs


};

#endif // INVENTORYCLASS_H_INCLUDED
