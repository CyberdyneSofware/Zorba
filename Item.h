#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <list>
#include <string.h>

using namespace std;

/* All Items - EXTERNAL DECLARATIONS*/
/****
char type = ---->
weapon = 'w' - modifies strength
clothing = 'c' - modifies defence
buffs: HP = 'h' - modifies HP
buffs: intelligence = 'i' - modifies intelligence
buffs: Resistance = 'r' - modifies resistance
****/


//Temporary place for the character stats - TAKE OUT ONCE TAYLOR'S CODE HAS BEEN COMBINED

struct character{

    char name[30]; //Name - name of character/Monster
    int level = 1; //Level - The character's current level of power
    float EXP = 0; //Experience - The player's current experience points
    int maxEXP = 100; //Maximum Experience - Maximum possible Experience points before a character levels up
    int maxHP = 15; //Maximum hit points - The character's maximum possible Health
    int HP = 15; //Hit points - The character's current Health
    int maxMP = 5; //Maximum Mana Points - The character's maximum possible Mana
    int MP = 5; //Mana points - The Character's current Mana
    float strength = 2; //Strength - Physical attack power
    float defense = 2; //Defense - Defense against physical attacks
    float intelligence = 2; //intelligence - Magical Attack power
    float resistance = 2; //Resistance - Defense against magic attacks
    int AP = 10; //Ability points - points to distribute towards stats of player choice

};


//the struct for any item
struct item
{
    string name; //stores the name
    char type; //stores the type of the item
    int modifyStat; //how much the item should modify
    bool inuse; //if the item is in use or not
    string message; //the message that plays when you equip it
    int randomnum; //gives a unique number to each item which allows me to randomly generate a number
};

//item global definitions
/*WEAPONS*/

extern item stick;
extern item basicsword;
extern item knife;
extern item genericgun;
extern item dragonslayer;
extern item thestaff;
extern item bootgun;
extern item theswordgunknife;
extern item tatteredcloth;
extern item beret;
extern item blackandwhitejacket;
extern item bluehairdye;
extern item jeanjacket;
extern item leatherarmor;
extern item steelarmor;
extern item diamondarmor;
extern item hppotion;
extern item safetycake;
extern item superpotion;
extern item magicleaf;
extern item largebook;
extern item thinkingcap;
extern item woodenshield;
extern item antiintelligencepotion;

/* LINKED LIST */
extern list<item> listOfItems;
extern list<item> randItemPool;

#endif
