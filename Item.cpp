#include "Item.h"

using namespace std;

/* Linked list below under items */

/* All Items */
/****
char type = ---->
weapon = 'w' - modifies strength
clothing = 'c' - modifies defence
buffs: HP = 'h' - modifies HP
buffs: intelligence = 'i' - modifies intelligence
buffs: Resistance = 'r' - modifies resistance
****/

//item global definitions
/*WEAPONS*/

//beginner item
item stick = {
    .name = "Stick",
    .type = 'w',
    .modifyStat = 1,
    .inuse = false,
    .message = "Can't wait to see you on the new watchmojo video; top ten worst anime weapons"
};

//chest item
item basicsword = {
    .name = "Basic Sword",
    .type = 'w',
    .modifyStat = 3,
    .inuse = false,
    .message = "Wow maybe you'll actually make a dent in em."
};

//battle item
item knife = {
    .name = "Knife",
    .type = 'w',
    .modifyStat = 2,
    .inuse = false,
    .message = "Not very useful from far way, but good luck.",
    .randomnum = 1
};

//battle item
item genericgun = {
    .name = "Generic Gun",
    .type = 'w',
    .modifyStat = 4,
    .inuse = false,
    .message = "This is gun. Have fun. Pleb.",
    .randomnum = 2
};

//chest item
item dragonslayer = {
    .name = "Dragon Slayer",
    .type = 'w',
    .modifyStat = 7,
    .inuse = false,
    .message = "The sword has to be almost 8 feet long and the handle has a bandage wrapped around it, \nyou wonder how anyone can pick this thing up.\n With a lot of effort you are able to lift it off the ground."
};

//battle item
item thestaff = {
    .name = "THE Staff",
    .type = 'w',
    .modifyStat = 5,
    .inuse = false,
    .message = "Not staff as in a worker but staff as in the weapon. It's wooden except for the blade on the end which is steal.",
    .randomnum = 8
};

//chest item
item bootgun = {
    .name = "Boot Gun",
    .type = 'w',
    .modifyStat = 6,
    .inuse = false,
    .message = "The weapon is a weirdly shaped boot, you wonder if you can even put it on. \nattached to the front is what looks like the front of a gun. \nWritten mysteriously on the side with a sharpie is the words:\n Kick to Shoot."
};

//end of the battle item
item theswordgunknife = {
    .name = "The Sword Gun Knife",
    .type = 'w',
    .modifyStat = 50,
    .inuse = false,
    .message = "This is the most OP weapon in the game. It's a sword, a gun, and a knife all at once!",
};



/*CLOTHING*/
//begginer item
item tatteredcloth = {
    .name = "Tattered Cloth",
    .type = 'c',
    .modifyStat = 1,
    .inuse = false,
    .message = "It has a few questionable holes in it, but otherwise it will shield you from the cold. Eh, it'll work"
};

//battle item
item beret = {
    .name = "Beret",
    .type = 'c',
    .modifyStat = 2,
    .inuse = false,
    .message = "It looks a bit worn, but kind of neat. Some of the string sewing it together has unraveled and is barely holding a pin to the front. \n(Are you cosplaying as Phillip?)",
    .randomnum = 3
};

//battle item
item blackandwhitejacket = {
    .name = "Black and White Jacket",
    .type = 'c',
    .modifyStat = 2,
    .inuse = false,
    .message = "It is a thin jacket with a zipper in the front, you don't know who left this behind. \n(You can almost be as edgy as Alexi with this)",
    .randomnum = 4
};

//battle item
item bluehairdye = {
    .name = "Blue Hair Dye",
    .type = 'c',
    .modifyStat = 1,
    .inuse = false,
    .message = "It's a tin bottle with neon blue paint across the front, on the top there is a black cap keeping it closed ",
    .randomnum = 5
};

//battle item
item jeanjacket = {
    .name = "Jean Jacket",
    .type = 'c',
    .modifyStat = 2,
    .inuse = false,
    .message = "The Jacket is a rough material, and is a sharp dark blue color. Maybe wearing it will make you look pretty cool.",
    .randomnum = 6
};

//chest item
item leatherarmor = {
    .name = "Leather Armor",
    .type = 'c',
    .modifyStat = 3,
    .inuse = false,
    .message = "The armor is made of what looks like leather, \nbut upon closer inspection it's appears to just be a t-shirt that looks leather."
};

//battle item
item steelarmor = {
    .name = "Steel Armor",
    .type = 'c',
    .modifyStat = 5,
    .inuse = false,
    .message = "The armor is relatively heavy, and cold at the touch. Surely it'll protect you in battle",
    .randomnum = 9
};

//chest item - end game
item diamondarmor = {
    .name = "Diamond Armor",
    .type = 'c',
    .modifyStat = 50,
    .inuse = false,
    .message = "This armor shimmers brighter than even the most bright highlighter. \nThis will be the last armor you get in this game use it wisely."
};


//buffs:HP
//beginner item and battle item
item hppotion = {
    .name = "HP Potion",
    .type = 'h',
    .modifyStat = 15,
    .inuse = false,
    .message = "The potion is in a small glass bottle, which has some soupy red liquid at the bottom of the bottle.",
    .randomnum = 7
};

//battle item
item safetycake = {
    .name = "Safety Cake",
    .type = 'h',
    .modifyStat = 25,
    .inuse = false,
    .message = "It's a obnoxiously large cake with brightly colored pink frosting. \nIt looks a bit odd in this environment and you wonder how it got here. \nOf course, it's a piece of cake to bake a pretty cake so someone probably had fun making it.",
    .randomnum = 10
};

//chest item - end game
item superpotion = {
    .name = "Super Potion",
    .type = 'h',
    .modifyStat = 50,
    .inuse = false,
    .message = "It's a glass bottle with a liquid in it. \nWhen you pick it up you notice that it is glowing brightly and the space around it is tinted slightly red."
};


//buffs: intelligence
//battle item
item magicleaf = {
    .name = "Magic Leaf",
    .type = 'i',
    .modifyStat = 1,
    .inuse = false,
    .message = "It seems like just a leaf, \nbut upon closer inspection, \nit seems to be magical. Eating it may increase your intelligence somehow.",
    .randomnum = 11
};

//battle item
item largebook = {
    .name = "Large Book",
    .type = 'i',
    .modifyStat = 4,
    .inuse = false,
    .message = "The book is dusty so you can't see the cover, \nbut when you pick it up some of it brushes off and you can see the words on the front. \nIt says HERE LIES YOUR EDUMACATION. It will  ",
    .randomnum = 12
};

//battle item
item thinkingcap = {
    .name = "Thinking Cap",
    .type = 'i',
    .modifyStat = 6,
    .inuse = false,
    .message = "Its a hat made out of a silky fabric with paper stars taped on, very smart looking.",
    .randomnum = 13
};

//buffs: Resistance
//battle item
item woodenshield = {
    .name = "Wooden Shield",
    .type = 'r',
    .modifyStat = 4,
    .inuse = false,
    .message = "The shield looks like it had just been carved out of a tree, not very sturdy, but it'll work.",
    .randomnum = 14
};

//battle item
item antiintelligencepotion = {
    .name = "Anti Intelligence Potion",
    .type = 'r',
    .modifyStat = 6,
    .inuse = false,
    .message = "It's a potion which makes intelligence attacks less effective and increases your resistance.",
    .randomnum = 15
};

list<item> listOfItems; //list of items
