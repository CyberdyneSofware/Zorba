#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED

/********************************\
Mahmud Taylor 04/06/18           |
This is a basic fighting code for|
an RPG style text game along with|
a character creation thing       |
\********************************/

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

#include "InventoryClass.h"

struct character{//Structure for the character that the player will be

    char name[30] = "ZORBA"; //Name - name of character/Monster
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

struct enemy{ //Easiest enemy to fight
    char name[30];
    int HP; //Enemy's Health
    int maxHP;
    int strength; //Physical attack power
    int intelligence; //Magical Attack power
    int defense; //Defense against a physical attack
    int resistance; //Defense against magical attacks
    float EXP; //Experience gained from the enemy
};

extern void mon();
extern void close();
extern int fight1();
extern void menufight();
extern bool battle(enemy foe); //Function for the basic battle setup

extern int magicOne(enemy foe); //The Level 1 Magic Menu for the Battle
extern int magicTwo(enemy foe); //The Level 2 Magic Menu for the Battle
extern int magicThree(enemy foe); //The Level 3 Magic Menu for the Battle
extern int attack(int strength, int defense); //Mathematics for damaging the enemy
extern int eneattack(int strength, int defense); //Mathematics for being attacked
extern int cure(int magic); //Mathematics for healing oneself
extern void levelUp(); //Function to Level up the Player
extern void allotAP(); //Function to allow Player to allot Ability Points
extern void viewStat(); //Function allowing player to view stats
extern void doublestat(); //Function to raise the enemy stats by a multiple of 2
extern void healPage(); //Cure page for out of battle
extern void damageAnima(); //Animation for being damaged
extern void attackEneAnima(); //Animation for damaging the enemy
extern void healingAnima(); //Animation for healing oneself
extern void spookyMessage(); //Silly little spooky message if you try to run from Hitler.
extern void removeRun(); //Indicate visually running away isn't possible
extern void displayRun(); //Displays Run away or not depending on if special message has been moved

extern character player; //Create Player character

extern enemy mook; //Create easy enemy
extern enemy knight; //Create slightly harder enemy
extern enemy daemon; //Create difficult enemy
extern enemy hitler; //Create Boss enemy

extern char active; //Variable for player action during battle

extern char enetype; //Variable to allow different enemy attack patterns

extern int insult; //Variable for insults from Hitler

extern char runAway; //Variable to show "R: RUN AWAY" in the menu


#endif
