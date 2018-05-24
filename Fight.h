#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

/** Mahmud Taylor 04/06/18
This is a basic fighting code for
an RPG style text game along with
a character creation thing **/

/** color indicators
to use: system("color ##")
first number is background
second number is text

0 = Black
8 = Gray
1 = Blue
9 = Light Blue
2 = Green
A = Light Green
3 = Aqua
B = Light Aqua
4 = Red
C = Light Red
5 = Purple
D = Light Purple
6 = Yellow
E = Light Yellow
7 = White
F = BringWhite

**/

struct character
{

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

struct enemy{ //Easiest enemy to fight
    char name[30];
    int HP;
    int maxHP;
    int strength; //Physical attack power
    int intelligence; //Magical Attack power
    int defense; //Defense against a physical attack
    int resistance; //Defense against magical attacks
    float EXP;
};
void fight1();
void battle(enemy foe);
int attack(int strength, int defense);
int magicOne(enemy foe);
int magicTwo(enemy foe);
int magicThree(enemy foe);
int cure(int magic);
void levelUp();
void allotAP();
void introSeq();
int eneattack(int strength, int defense);
void doublestat();
void damageAnima();
void attackEneAnima();

character player; //Create Player character

enemy goblin; //Create easy enemy

enemy knight; //Create slightly harder enemy

enemy daemon; //Create difficult enemy

char active = 'n';

void mon()
{
    int mon1 = 0;
    mon1 = rand() % 5;
    if(mon1 < 2)
    {
        cout << "You ran into a mook! Queue the Pokemon battle music\n";
        system("pause");
        fight1();
    }
    else if(mon1 > 3)
    {
        cout << "\n";
    }
    mon1 = 0;
}

void fight1()
{
    int xp;
    xp = rand() %50+20;

    goblin.name[0] = 'G'; //Make monster named "Goblin"
    goblin.name[1] = 'o';
    goblin.name[2] = 'b';
    goblin.name[3] = 'l';
    goblin.name[4] = 'i';
    goblin.name[5] = 'n';
    goblin.name[6] = '\0';
    goblin.maxHP = 30; //Set Goblin's health to 10
    goblin.HP = goblin.maxHP;
    goblin.strength = 2; //Set Goblin's Strength to 3
    goblin.intelligence = 1; //Set Goblin's intelligence to 2
    goblin.defense = 1; //Set Goblin's Defense to 1
    goblin.resistance = 1; //Set Goblin's Resistance to 0
    goblin.EXP = xp; //Set EXP gained from goblin to 25

    knight.name[0] = 'K'; //Make enemy named "Knight"
    knight.name[1] = 'n';
    knight.name[2] = 'i';
    knight.name[3] = 'g';
    knight.name[4] = 'h';
    knight.name[5] = 't';
    knight.name[6] = '\0';
    knight.maxHP = 15; //Set Knight's Health to 15
    knight.HP = knight.maxHP;
    knight.strength = 6; //Set Knight's Strength to 6
    knight.intelligence = 3; //Set Knight's Intelligence to 3
    knight.defense = 5; //Set Knight's Defense to 5
    knight.resistance = 3; //Set Knight's Resistance to 3
    knight.EXP = 80; //Set EXP gained from Knight to 80

    daemon.name[0] = 'D'; //Make enemy named "Daemon"
    daemon.name[1] = 'a';
    daemon.name[2] = 'e';
    daemon.name[3] = 'm';
    daemon.name[4] = 'o';
    daemon.name[5] = 'n';
    daemon.name[6] = '\0';
    daemon.maxHP = 20; //Set Daemon's Health to 20
    daemon.HP = daemon.maxHP;
    daemon.strength = 10; //Set Daemon's Strength to 10
    daemon.intelligence = 4; //Set Daemon's Intelligence to 4
    daemon.defense = 10; //Set Daemon's Defense to 10
    daemon.resistance = 5; //Set Daemon's Resistance to 5
    daemon.EXP = 200; //Set EXP gained from Daemon to 200

    battle(goblin);
}

/**************************************************** BATTLE CODE *********************************************************************/

void battle(enemy foe)
{

    system("CLS");


    char action = 'z';
    int attmod = 0; //Strength buffs
    int defmod = 1; //Defense buffs
    int damage = 0;
    int looped = 4;
    int pAct = 1;
    char message = 'n';

    cout << "You encountered a " << foe.name << "!" <<endl;
    cin.get();

    /****************    Default battle menu    **********************/

    while(player.HP > 0 && foe.HP > 0)
    {
        active = 'n';

        looped = 4;

        if(pAct == 0)
        {

            damageAnima();

            defmod = player.defense*defmod;

            damage = attack(foe.strength, defmod);

            defmod = 1;

            player.HP = player.HP - damage;

            cout << "The " <<foe.name << " dealt " << damage << " damage!" <<endl;
            cin.get();
            pAct++;
            message = 'n';
        }


        if(pAct >=1)
        {
            if (message == 'y')
            {
                cout << "The enemy is frozen." <<endl;
                cin.get();
            }

            system("CLS");

            cout << "What will you do?" <<endl;
            cout << "\n";
            cout << "\n";

            //system("color 0C"); //Create enemy in an "unfriendly color"
            cout << "   " << foe.name <<endl; //display enemy name
            cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
            cout << "\n" <<endl;

            //system("color 02"); //create player in a "friendly color"
            cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
            cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
            cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

            //system("color 07");//Reset text color
            cout << "\n";
            cout << "\n";
            cout << "\t A: ATTACK" <<endl;
            cout << "\t M: MAGIC" <<endl;
            cout << "\t D: DEFEND" <<endl;
            cout << "\t I: *Coming soon*" <<endl;
            cout << "\t R: *Coming soon*" <<endl;
            cout << "\n";
            cin >> action; //Have player choose what they want to do
            cin.get();

            if(action == 'A' || action == 'a')
            {

                damage = attack(player.strength, foe.defense);

                system("CLS");

                attackEneAnima();

                foe.HP = foe.HP - damage; //Deal damage to enemy

                cout << player.name << " dealt " <<damage<< " damage!" <<endl;
                cin.get();

                pAct--; //allow enemy to attack

            }

            else if(action == 'M' || action == 'm')
            {
                damage = magicOne(foe);
                cout << damage <<endl;
                cin.get();

                system("CLS");
                if(damage > 0)
                {
                    attackEneAnima();
                    foe.HP = foe.HP - damage;
                    cout << player.name <<" dealt " <<damage <<" damage!" <<endl;
                    cin.get();
                    int chance = (rand() % 100 + 1);

    /********************** RECOIL **************************/
                    if(active == 't')
                    {
                        srand(time(NULL));

                        if(chance >= 0 && chance < 31)
                        {
                            int power = player.intelligence * 3;
                            damage = attack(power, player.resistance);
                            damage = damage/2;
                            player.HP = player.HP - damage;
                            damageAnima();
                            cout << "You took " << damage << " points of recoil damage!" <<endl;
                            cin.get();
                        }

                    }
    /************************* RECOIL **************************/
    /**************************FREEZING *************************/
                    else if(active == 'i')
                    {
                        srand(time(NULL));

                        cin.get();

                        if(chance >= 0 && chance < 40)
                        {
                            cout << "You froze the " <<foe.name <<"!" <<endl;
                            cin.get();
                            pAct = 4;
                            message = 'y';
                        }
                    }


                    pAct--;
                }

     /************************* FREEZING ***********************/
     /************************** HEALING ***********************/

                else if(damage < 0)
                {

                    while(looped > 0) //Healing animation
                    {
                        system("COLOR 22");
                        Sleep(30);
                        system("COLOR AA");
                        Sleep(30);
                        system("COLOR 22");
                        Sleep(30);
                        system("COLOR 07");
                        Sleep(20);
                        looped--;
                    }

                    damage = -damage;
                    player.HP = player.HP + damage; //Restore HP
                    if(player.HP >= player.maxHP)
                    {
                        cout << player.name << " has been healed to full health!" <<endl;
                    }

                    else
                    {
                        cout << player.name << " has restored " <<damage << " HP!" <<endl;
                    }

                    cin.get();
                    looped = 4;
                    pAct--;
                }

                else if(damage = 0)
                {
                }
            }

        /******************* HEALING *******************/

            else if(action == 'D' || action == 'd')
            {
                defmod = 3;
                cout << player.name << " protected themself from oncoming attacks!" <<endl;
                cin.get();
                pAct--;
            }

            else if(action == 'I' || action == 'i' || action == 'R' || action == 'r')
            {
                cout << "This requires outside help to be completed so I'm " <<endl;
                cout << "now here telling you exactly that." <<endl;
                cin.get();
            }

            else
            {
                cout << "Not an option meh dude" <<endl;
                cin.get();
            }
        }

        system("CLS");


    }

    if(player.HP < 1)
    {
        cout << player.name << " has died..." <<endl;
    }

    else if(foe.HP < 1)
    {
        cout << player.name << " won the battle!" <<endl;
        cin.get();

        cout << player.name << " gained " <<foe.EXP << " Experience points!" <<endl;

        player.EXP = player.EXP + foe.EXP;

        if(player.EXP >= player.maxEXP)
        {
            levelUp();
        }
    }

        /****************    Default battle menu    **********************/
}


/*******************************  INTRO BATTLE ANIMATION ******************************/
void battIntroAnima()
{
    /***

    system("color C7");

    int loopy = 3300;
    while(loopy >= 0) //Keep coloring until screen is covered
    {
        Sleep(200);
        cout << " ";
        loopy = loopy -1;
    }


    system("color 07");

    loopy = 3300;
    while(loopy >= 0) //Clean up screen
    {
        Sleep(200);
        cout << " ";
        loopy = loopy -1;
    }

    **/

}

/************************    INTRO BATTLE ANIMATION  ***********************************/

/***********************   MAGIC MENU  **************************************/

/************************ LEVEL 1 SPELLS *************************/

int magicOne(enemy foe)
{
    char action; //choice player makes
    do
    {

        float damage = 0; //damage dealt or taken
        float power = 1;

        system("CLS");

        cout << "What spell will you choose?" <<endl;
        cout << "\n";
        cout << "\n";

        //system("color 0C"); //Create enemy in an "unfriendly color"
        cout << "   " << foe.name <<endl; //display enemy name
        cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
        cout << "\n" <<endl;

        //system("color 02"); //create player in a "friendly color"
        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

        /*********************** WHY DID I DO THIS TO MYSELF ********************/

        //system("color 07");//Make background text grayed out to reduce visual confusion
        cout << "\t               _______________________________________________" <<endl;
        cout << "\t              |                LEVEL 1 SPELLS                 |" <<endl;

        if(player.level < 5)
        {
            cout << "\t A: ATTACK    | <-- G: GO BACK                                |"<<endl;
        }

        else if(player.level >= 5)
        {
            cout << "\t A: ATTACK    | <-- G: GO BACK          L: LEVEL 2 SPELLS --> |"<<endl;
        }

        //system("color 08");

        //system("color 07");
        //system("color 08");
        cout << "\t M: MAGIC --->| 2MP/F: FIRE - Basic Damage                    |"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       |"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t I: *Coming so| 7MP/T: THUNDER - High damage, recoil possible |"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t R: *Coming so| 3MP/C: CURE - Restore health to self          |"<<endl;
        //system("color 07");
        cout << "\t              |_______________________________________________|" <<endl;

        /*********************** WHY DID I DO THIS TO MYSELF *********************/

        cout << "\n";
        cin >> action;
        cin.get();

        if(action == 'F' || action == 'f') //Fire code
        {
            if(player.MP >= 2)
            {
                power = player.intelligence*1.5;
                damage = attack(power, foe.resistance);
                player.MP = player.MP - 2;

                return damage;
            }

            else if(player.MP < 2)
            {
                cout << "You do not have enough MP to cast FIRE." <<endl;
                cin.get();
            }
        }

        else if(action == 'I' || action == 'i') //Ice code
        {
            if(player.MP >= 4)
            {
                power = player.intelligence*0.5;
                damage = attack(power, foe.resistance);
                player.MP = player.MP - 4;
                active = 'i';
                return damage;
            }

            else if(player.MP < 4)
            {
                cout << "You do not have enough MP to cast ICE." <<endl;
                cin.get();
            }

            /******************************************
                 INSERT CHANCE OF ENEMY FREEZING
            ******************************************/
        }

        else if(action == 'T' || action == 't') //Thunder code
        {
            if(player.MP >= 7)
            {
                power = player.intelligence*3;
                damage = attack(power, player.resistance);
                player.MP = player.MP - 7;
                active = 't';
                return damage;
            }

            else if(player.MP < 7)
            {
                cout << "You do not have enough MP to cast THUNDER." <<endl;
                cin.get();
            }

        }

        else if(action == 'C' || action == 'c') //Cure code
        {
            if(player.MP >= 3)
            {
                damage = cure(player.intelligence); //Determine amount of health restored
                player.MP = player.MP - 3;

                return damage;
            }

            else if(player.MP < 3)
            {
                cout << "You do not have enough MP to cast CURE." <<endl;
                cin.get();
            }
        }

        else if(((action == 'L') || (action == 'l')) && player.level > 4)
        {
            damage = magicTwo(foe);

            if(damage != 0)
            {
                return damage;
            }

        }

        else if(action == 'G' || action == 'g') //Remove the 'not an option' message
        {
            return 0;
        }

        else
        {
            cout << "Not an option." <<endl;
        }

    }while(action != 'g' || action != 'G'); //Send player back to normal menu


}
/****************************** LEVEL 1 SPELLS *************************************/

/****************************** LEVEL 2 SPELlS *************************************/
int magicTwo(enemy foe)
{
    char action; //choice player makes
    do
    {

        float damage = 0; //damage dealt or taken
        float power = 1;

        system("CLS");

        cout << "What spell will you choose?" <<endl;
        cout << "\n";
        cout << "\n";

        //system("color 0C"); //Create enemy in an "unfriendly color"
        cout << "   " << foe.name <<endl; //display enemy name
        cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
        cout << "\n" <<endl;

        //system("color 02"); //create player in a "friendly color"
        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

        /*********************** WHY DID I DO THIS TO MYSELF ********************/

        //system("color 07");//Make background text grayed out to reduce visual confusion
        cout << "\t               _______________________________________________" <<endl;
        cout << "\t              |                LEVEL 2 SPELLS                 |" <<endl;

        if(player.level < 10)
        {
            cout << "\t A: ATTACK    | <-- G: GO BACK                                |"<<endl;
        }

        else if(player.level >= 10)
        {
            cout << "\t A: ATTACK    | <-- G: LEVEL 1 SPELLS          L: LEVEL 3 SPELLS --> |"<<endl;
        }

        //system("color 08");

        //system("color 07");
        //system("color 08");
        cout << "\t M: MAGIC --->| 2MP/F: FIRE 2 - Basic Damage                   |"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t D: DEFEND    | 4MP/I: ICE 2- Chance to immobilize enemy      |"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t I: *Coming so| 7MP/T: THUNDER 2- High damage, recoil possible|"<<endl;
        //system("color 07");
        //system("color 08");
        cout << "\t R: *Coming so| 3MP/C: CURE 2- Restore health to self         |"<<endl;
        //system("color 07");
        cout << "\t              |_______________________________________________|" <<endl;

        /*********************** WHY DID I DO THIS TO MYSELF *********************/

        cout << "\n";
        cin >> action;
        cin.get();

        if(action == 'F' || action == 'f') //Fire code
        {
            if(player.MP >= 2)
            {
                power = player.intelligence*1.5;
                damage = attack(power, foe.resistance);
                player.MP = player.MP - 2;

                return damage;
            }

            else if(player.MP < 2)
            {
                cout << "You do not have enough MP to cast FIRE." <<endl;
                cin.get();
            }
        }

        else if(action == 'I' || action == 'i') //Ice code
        {
            if(player.MP >= 4)
            {
                power = player.intelligence*0.5;
                damage = attack(power, foe.resistance);
                player.MP = player.MP - 4;
                active = 'i';
                return damage;
            }

            else if(player.MP < 4)
            {
                cout << "You do not have enough MP to cast ICE." <<endl;
                cin.get();
            }

            /******************************************
                 INSERT CHANCE OF ENEMY FREEZING
            ******************************************/
        }

        else if(action == 'T' || action == 't') //Thunder code
        {
            if(player.MP >= 7)
            {
                power = player.intelligence*3;
                damage = attack(power, player.resistance);
                player.MP = player.MP - 7;
                active = 't';
                return damage;
            }

            else if(player.MP < 7)
            {
                cout << "You do not have enough MP to cast THUNDER." <<endl;
                cin.get();
            }

        }

        else if(action == 'C' || action == 'c') //Cure code
        {
            if(player.MP >= 3)
            {
                damage = cure(player.intelligence); //Determine amount of health restored
                player.MP = player.MP - 3;

                return damage;
            }

            else if(player.MP < 3)
            {
                cout << "You do not have enough MP to cast CURE." <<endl;
                cin.get();
            }
        }

        else if(action == 'G' || action == 'g') //Remove the 'not an option' message
        {
            return 0;
        }

        else
        {
            cout << "Not an option." <<endl;
        }

    }while(action != 'g' || action != 'G'); //Send player back to normal menu


}

/********************* LEVEL 2 SPELLS **************************/
/***********************   MAGIC MENU  **************************************/

/************************   ATTACK CALCULATIONS ***********************************/

int attack(int strength, int defense)
{
    int rand();
    if(strength > 0)
    {
        srand(time(NULL));
        strength = strength + (rand() % (strength*2)-(strength/2));
    }

    if(defense > 0)
    {
        srand(time(NULL));
        defense = (rand() % (defense*2)-(defense/2));
    }


    int damage = strength - defense/2;

    if(damage < 1)
    {
        damage = 1 + strength/2;
    }

    return damage;

}

int eneattack(int strength, int defense)
{
    int rand();
    if(strength > 0)
    {
        srand(time(NULL));
        strength = strength/2 + (rand() % (strength*2)-(strength/2));
    }

    if(defense > 0)
    {
        srand(time(NULL));
        defense = (rand() % (defense*2)-(defense/2));
    }


    int damage = strength - defense/2;

    if(damage < 1)
    {
        damage = 1 + strength/2;
    }

    return damage;

}
/************************  ATTACK CALCULATIONS **********************************/

/************************  HEALING CALCULATIONS  ********************************/

int cure(int intelligence)
{
    int rand();
    int heals; //amount of health restored, will be in negative for coding purposes

    if(intelligence > 0)
    {
        srand(time(NULL));
        heals = -(rand() % (intelligence));
    }

    if(heals < 1)
    {
        heals = -(1 + intelligence/2);
    }

    return heals;
}

/************************  HEALING CALCULATIONS  ********************************/

/**************************************************** BATTLE CODE *********************************************************************/



/************************ LEVEL UP SECTION ***********************************/

void levelUp()
{
    player.level++; //Increase Player Level
    player.EXP = player.EXP - player.maxEXP; //Reset Experience
    player.maxEXP = player.maxEXP*1.5; //Increase required Experience before next level up

    system("CLS");

    cout << player.name << " has leveled up to Level " <<player.level<< "!" <<endl;
    cout << "\n";
    cout << "\n";
    cin.get();

    //Display new HP
    cout << "HP         " << player.maxHP << " --> ";
    player.maxHP = player.maxHP + (2*(player.level/2 - 1)) + 1;
    Sleep(100);
    cout << player.maxHP <<endl;
    cout << "\n";
    Sleep(100);

    //Display new MP
    cout << "MP           " << player.maxMP << " --> ";
    player.maxMP = player.maxMP + (player.level - 1) + 1;
    Sleep(100);
    cout << player.maxMP <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Strength
    cout << "Strength     " << player.strength << " --> ";
    player.strength = player.strength + ((player.level - 1)/3) + 1;
    Sleep(100);
    cout << player.strength <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Defense
    cout << "Defense      " <<player.defense << " --> ";
    player.defense = player.defense + ((player.level - 1)/3) + 1;
    Sleep(100);
    cout << player.defense <<endl;
    cout << "\n";
    Sleep(100);

    //Display new intelligence
    cout << "Intelligence " <<player.intelligence << " --> ";
    player.intelligence = player.intelligence + ((player.level - 1)/3) + 1;
    Sleep(100);
    cout << player.intelligence <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Resistance
    cout << "Resistance   " <<player.resistance << " --> ";
    player.resistance = player.resistance + ((player.level - 1)/3) + 1;
    Sleep(100);
    cout << player.resistance <<endl;
    cout << "\n";
    Sleep(100);

    //Display new AP
    cout << "AP           " <<player.AP << " --> ";
    player.AP = player.AP +(2*(player.level - 1));
    Sleep(100);
    cout << player.AP <<endl;
    cout << "\n";
    Sleep(100);

    cin.get();
    system("PAUSE");

    allotAP();

}

/************************************* LEVEL UP SECTION ******************************************/

/************************************ AP ALLOTMENT SYSTEM ****************************************/

void allotAP()
{
    system("CLS");

    char answer;
    do
    {

        cout << "Input the corresponding letter of the stat you wish to increase.";

        if(player.level == 1)
        {
            cout << " If you wish to remove a" <<endl;
            cout << "point from one of your stats, input a - sign(ex. -: be brought to a menu to remove stats)" <<endl;
            cout << "You cannot remove stats past their base stat." <<endl;
        }

        cout << "\n";

        cout << "Remaining points: " << player.AP <<endl; //Display remaining AP that player can use
        cout << "\n";
        cout << "H/HP:           " << player.maxHP <<endl; //Display current maximum Health
        cout << "M/MP:           " << player.maxMP <<endl; //Display current maximum Mana
        cout << "S/Strength:     " << player.strength <<endl; //Display current Strength
        cout << "D/Defense:      " << player.defense <<endl; //Display current Defense
        cout << "I/Intelligence: " << player.intelligence <<endl; //Display current intelligence
        cout << "R/Resistance:   " << player.resistance <<endl; //Display current Resistance

        cin >> answer;
        cin.get();

        if(answer == 'h' || answer == 'H') //Increase Maximum HP and health by 2 if player inputs an 'h'
        {
            player.maxHP = player.maxHP + 2;
            player.HP = player.maxHP;
            player.AP = player.AP - 1;
        }

        else if(answer == 'm' || answer == 'M')
        {
            player.maxMP = player.maxMP + 1;
            player.MP = player.maxMP;
            player.AP = player.AP - 1;
        }

        else if(answer == 's' || answer == 'S') //Increase Strength by 1 point if player inputs an 's'
        {
            player.strength = player.strength + 1;
            player.AP = player.AP - 1;
        }

        else if(answer == 'd' || answer == 'D')//Increase Defense by 1 point if player inputs 'd'
        {
            player.defense = player.defense + 1;
            player.AP = player.AP - 1;
        }

        else if(answer == 'i' || answer == 'I') //Increase intelligence by 1 point if player inputs 'M'
        {
            player.intelligence = player.intelligence + 1;
            player.AP = player.AP - 1;
        }

        else if(answer == 'r' || answer == 'R') //Increase Resistance by 1 point if player 'R'
        {
            player.resistance = player.resistance + 1;
            player.AP = player.AP - 1;
        }

        /****************  REMOVE STATS  ********************/

        else if(answer == '-' && player.level == 1)
        {
            system("CLS");
            cout << "Input the corresponding letter of the stat you wish to decrease. If you " <<endl;
            cout << "wish to increase a point from one of your stats, input something random." <<endl;
            cout << "You cannot remove stats past their base stat. \n " <<endl;

            cout << "Remaining points: " << player.AP <<endl; //Display remaining AP that player can use
            cout << "\n";
            cout << "h/HP:           " << player.maxHP <<endl; //Display current maximum Health
            cout << "m/MP:           " << player.maxMP <<endl;
            cout << "s/Strength:     " << player.strength <<endl; //Display current Strength
            cout << "d/Defense:      " << player.defense <<endl; //Display current Defense
            cout << "I/Intelligence: " << player.intelligence <<endl; //Display current intelligence
            cout << "r/Resistance:   " << player.resistance <<endl; //Display current Resistance

            cin >> answer;
            cin.get();

            if(answer == 'h' || answer == 'H') //Decrease Maximum HP and health by 2 if player inputs an '-h'
            {
                if(player.maxHP > 10) //Check if HP is too low to decrease
                {
                    player.maxHP = player.maxHP - 2;
                    player.HP = player.maxHP;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease HP any further. "<<endl;
                    cin.get();
                }

            }

            else if(answer == 'm' || answer == 'M') //Decrease Maximum MP and MP by 1 if player inputs an '-m'
            {
                if(player.maxMP > 5) //Check if MP is too low to decrease
                {
                    player.maxMP = player.maxMP - 1;
                    player.MP = player.maxMP;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease MP any further. "<<endl;
                    cin.get();
                }

            }

            else if(answer == 's' || answer == 'S') //Decrease Strength by 1 point if player inputs an '-s'
            {

                if(player.strength > 1) //Check if Strength is too low to decrease
                {
                    player.strength = player.strength - 1;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease Strength any further." <<endl;
                    cin.get();
                }

            }

            else if(answer == 'd' || answer == 'D')//Decrease Defense by 1 point if player inputs '-d'
            {
                if(player.defense > 1) //Check if Defense  is too low to decrease
                {
                    player.defense = player.defense - 1;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease Defense any further. " <<endl;
                    cin.get();
                }

            }

            else if(answer == 'i' || answer == 'I') //Decrease intelligence by 1 point if player inputs '-i'
            {
                if(player.intelligence > 1) //Check if intelligence is too low to decrease
                {
                    player.intelligence = player.intelligence - 1;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease Intelligence any further." <<endl;
                    cin.get();
                }

            }

            else if(answer == 'r' || answer == 'R') //Decrease Resistance by 1 point if player '-r'
            {
                if(player.resistance > 1) //Check if Resistance is too low to decrease
                {
                    player.resistance = player.resistance - 1;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease Resistance any further. " <<endl;
                    cin.get();
                }


            }

            else
            {
                cout << "That is not an available option." <<endl;
            }

        }

        /****************  REMOVE STATS  ********************/

        else //If player inputted something that wasn't one of the options
        {
            cout << "That is not an available option." <<endl;
        }

        system("CLS");

    }while(player.AP > 0);

    player.HP = player.maxHP;
    player.MP = player.maxMP;

    if(player.level > 1)
    {
        cout << "These are your new character stats:" <<endl;
        cout << "\n";
        cout << "       " << player.name <<" \t Level: " << player.level <<endl;
        cout << "Exp:   " << player.EXP << "/" << player.maxEXP <<endl;
        cout << "\n";
        cout << "HP:           " << player.HP << "/" << player.maxHP <<endl;
        cout << "MP:           " << player.MP << "/" << player.maxMP <<endl;
        cout << "Strength:     " << player.strength <<endl;
        cout << "Defense:      " << player.defense <<endl;
        cout << "Intelligence: " << player.intelligence<<endl;
        cout << "Resistance:   " << player.resistance <<endl;
        cin.get();
    }

    else if(player.level == 1)
    {
        //Step 4: Show Complete Character
        cout << "Okay. You're Character is now complete." <<endl;
        cout << "This is your entire character stat knowledge. \n" <<endl;
        cout << "       " << player.name <<" \t Level: " << player.level <<endl;
        cout << "Exp:   " << player.EXP << "/" << player.maxEXP <<endl;
        cout << "\n";
        cout << "HP:           " << player.HP << "/" << player.maxHP <<endl;
        cout << "MP:           " << player.MP << "/" << player.maxMP <<endl;
        cout << "Strength:     " << player.strength <<endl;
        cout << "Defense:      " << player.defense <<endl;
        cout << "Intelligence: " << player.intelligence <<endl;
        cout << "Resistance:   " << player.resistance <<endl;
        cout << "\n";
        cin.get();

        system("CLS");
    }
}

/************************************ AP ALLOTMENT SYSTEM ****************************************/

/**************************** DOUBLE ENEMY STATS *********************/
void doublestat()
{
    goblin.maxHP = goblin.maxHP*2; //Double Goblin's health
    goblin.HP = goblin.maxHP;
    goblin.strength = goblin.strength*2; //Set Goblin's Strength to 3
    goblin.intelligence = goblin.intelligence*2; //Set Goblin's intelligence to 2
    goblin.defense = goblin.defense*2; //Set Goblin's Defense to 1
    goblin.resistance = goblin.resistance*2; //Set Goblin's Resistance to 0
    goblin.EXP = goblin.EXP*2; //Set EXP gained from goblin to 25

    knight.maxHP = knight.maxHP*2; //Set Knight's Health to 15
    knight.HP = knight.maxHP;
    knight.strength = knight.strength*2; //Set Knight's Strength to 6
    knight.intelligence = knight.intelligence*2; //Set Knight's Intelligence to 3
    knight.defense = knight.defense*2; //Set Knight's Defense to 5
    knight.resistance = knight.resistance*2; //Set Knight's Resistance to 3
    knight.EXP = knight.EXP*2; //Set EXP gained from Knight to 80

    daemon.maxHP = daemon.maxHP*2; //Set Daemon's Health to 20
    daemon.HP = daemon.maxHP;
    daemon.strength = daemon.strength*2; //Set Daemon's Strength to 10
    daemon.intelligence = daemon.intelligence*2; //Set Daemon's Intelligence to 4
    daemon.defense = daemon.defense*2; //Set Daemon's Defense to 10
    daemon.resistance = daemon.resistance*2; //Set Daemon's Resistance to 5
    daemon.EXP = daemon.EXP*2; //Set EXP gained from Daemon to 200
}

/************************ DOUBLE ENEMY STATS **************************/
/************************ GETTING ATTACKED ANIMATION ******************/

void damageAnima()
{
    int looped = 4;
    while(looped > 0) //Getting hit animation
    {
        system("COLOR C7");
        Sleep(25);
        system("COLOR 07");
        Sleep(25);
        looped--;
    }
}
/********************** GETTING ATTACKED ANIMATION *********************/

/********************* ATTACKING ENEMY ANIMATION ***********************/
void attackEneAnima()
{
    int looped = 4;
    while(looped > 0) //attacking animation
    {
        system("COLOR 88");
        Sleep(25);
        system("COLOR 07");
        Sleep(25);
        looped--;
    }
}
/***************** ATTACKING ENEMY ANIMATION ***********************/



