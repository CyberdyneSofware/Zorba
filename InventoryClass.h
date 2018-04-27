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
    char type = ---->
    weapon = 'w' - modifies strength
    clothing = 'c' - modifies defence
    buffs: HP = 'h' - modifies HP
    buffs: intelligence = 'i' - modifies intelligence
    buffs: Resistance = 'r' - modifies resistance
    ****/

    char choice; //when calling the inventorycommand(choice); function please set choice to either 'a' for adding an item or 'b' for anything else

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
        message = "The sword has to be almost 8 feet long and the handle has a bandage wrapped around it, \nyou wonder how anyone can pick this thing up.\n With a lot of effort you are able to lift it off the ground. \nOn the bandage there is something written in scrambled letters: W arni ng  y ou  must hav e  a tragi c back  s tory to use thi s  weapon.";

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
        message = "The weapon is a weirdly shaped boot, you wonder if you can even put it on. \nattached to the front is what looks like the front of a gun. \nWritten mysteriously on the side with a sharpie is the words: Kick to Shoot.";
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
        message = "It looks a bit worn, but kind of neat. Some of the string sewing it together has unraveled and is barely holding a pin to the front. \n(Are you cosplaying as Phillip?)"
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
        message = "It is a thin jacket with a zipper in the front, you don't know who left this behind. \n(You can almost be as edgy as Alexi with this)";

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

    struct jeanjacket
    {
        //name
        name = "Jean Jacket";

        //type
        type = 'c';

        //modify stat
        modifyStat = 2;

        //in use
        inuse = false;

        //message
        message = "The Jacket is a rough material, and is a sharp dark blue color. Maybe wearing it will make you look pretty cool.";

    }:

    struct leatherarmor
    {
        //name
        name = "Leather Armor";

        //type
        type = 'c';

        //modify stat
        modifyStat = 3;

        //in use
        inuse = false;

        //message
        message = "The armor is made of what looks like leather, \nbut when you put it under the light you can see that it is just a fuax leather. \nUpon closer inspection it's appears to just be a t-shirt that looks leather.";

    };

    struct steelarmor
    {
        //name
        name = "Steel Armor";

        //type
        type = 'c';

        //modify stat
        modifyStat = 5;

        //in use
        inuse = false;

        //message
        message = "The armor is relatively heavy, and cold at the touch. Surely it'll protect you in battle";

    };

    //last clothing in the game
    struct diamondarmor
    {
        //name
        name = "Diamond Armor";

        //type
        type = 'c';

        //modify stat
        modifyStat = 100;

        //in use
        inuse = false;

        //message
        message = "This armor shimmers brighter than even the most bright highlighter. \nThis will be the last armor you get in this game use it wisely.";

    };

    //buffs:HP
    struct hppotion
    {
        //name
        name = "HP Potion";

        //type
        type = 'h';

        //modify stat
        modifyStat = 15;

        //in use
        inuse = false;

        //message
        message = "The potion is in a small glass bottle, which has some soupy red liquid at the bottom of the bottle.";

    };

    struct safetycake
    {
        //name
        name = "Safety Cake";

        //type
        type = 'h';

        //modify stat
        modifyStat = 25;

        //in use
        inuse = false;

        //message
        message = "It's a obnoxiously large cake with brightly colored frosting. \nIt looks a bit odd in this environment and you wonder how it got here. \nOf course, it's a piece of cake to bake a pretty cake so someone probably had fun making it.";

    };

    struct superpotion
    {
        //name
        name = "Super Potion";

        //type
        type = 'h';

        //modify stat
        modifyStat = 27;

        //in use
        inuse = false;

        //message
        message = "It's a glass bottle with a liquid in it. \nWhen you pick it up you notice that it is glowing brightly and the space around it is tinted slightly red.";

    };

    //buffs: intelligence
    struct magicleaf
    {
        //name
        name = "Magic Leaf";

        //type
        type = 'i';

        //modify stat
        modifyStat = 1;

        //in use
        inuse = false;

        //message
        message = "It seems like just a leaf, \nbut upon closer inspection, \nit seems to be magical. Eating it may increase your intelligence somehow.";

    };

    struct largebook
    {
        //name
        name = "Large Book";

        //type
        type = 'i';

        //modify stat
        modifyStat = 4;

        //in use
        inuse = false;

        //message
        message = "The book is dusty so you can't see the cover, \nbut when you pick it up some of it brushes off and you can see the words on the front. \nIt says HERE LIES YOUR EDUMACATION. It will  ";

    };

    struct thinkingcap
    {
        //name
        name = "Thinking Cap";

        //type
        type = 'i';

        //modify stat
        modifyStat = 6;

        //in use
        inuse = false;

        //message
        message = "Its a hat made out of a silky fabric with paper stars taped on, very smart looking.";

    };

    //buffs: Resistance
    struct woodenshield
    {
        //name
        name = "Wooden Shield";

        //type
        type = 'r';

        //modify stat
        modifyStat = 1;

        //in use
        inuse = false;

        //message
        message = "The shield looks like it had just been carved out of a tree, not very sturdy, but it'll work.";

    };

    struct antiintelligencepotion
    {
        //name
        name = "Anti Intelligence Potion";

        //type
        type = 'r';

        //modify stat
        modifyStat = 5;

        //in use
        inuse = false;

        //message
        message = "It's a potion which makes intelligence attacks less effective and increases your resistance.";

    };



};

#endif // INVENTORYCLASS_H_INCLUDED
