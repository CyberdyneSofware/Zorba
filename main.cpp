#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>

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

struct character{

    char name[30]; //Name - name of character/Monster
    int level = 1; //Level - The character's current level of power
    int EXP = 0; //Experience - The player's current experience points
    int maxEXP = 100; //Maximum Experience - Maximum possible Experience points before a character levels up
    int maxHP = 10; //Maximum hit points - The character's maximum possible Health
    int HP = 10; //Hit points - The character's current Health
    float strength = 1; //Strength - Physical attack power
    float defense = 1; //Defense - Defense against physical attacks
    float magic = 1; //Magic - Magical Attack power
    float resistance = 1; //Resistance - Defense against magic attacks
    int AP = 10; //Ability points - points to distribute towards stats of player choice

};

struct enemy{ //Easiest enemy to fight
    char name[30];
    int HP;
    int maxHP;
    int strength; //Physical attacks
    int magic;
    int defense; //Defense against a physical attack
    int resistance; //Defense against magical attacks
};

void battle(character player, enemy foe);
void battIntroAnima();
int attack(int strength, int defense);
int magic(character player, enemy foe);

int main()
{


    character player; //Create Player character
    enemy goblin; //Create easy enemy
    goblin.name[0] = 'G'; //Make monster named "Goblin"
    goblin.name[1] = 'o';
    goblin.name[2] = 'b';
    goblin.name[3] = 'l';
    goblin.name[4] = 'i';
    goblin.name[5] = 'n';
    goblin.name[6] = '\0';
    goblin.maxHP = 10; //Set Goblin's health to 10
    goblin.HP = goblin.maxHP;
    goblin.strength = 3; //Set Goblin's Strength to 3
    goblin.magic = 2; //Set Goblin's Magic to 2
    goblin.defense = 1; //Set Goblin's Defense to 1
    goblin.resistance = 0; //Set Goblin's Resistance to 0

    char answer = 'n'; //Ensure do while ahead operates

    cout << "Welcome to Fight Club. You fight now." << endl;

    //Step 1: Get name
    do
    {

        cout << "What's your name?" <<endl;
        cin.get(player.name, 30, '\n');
        cin.get();

        cout << "So you are " << player.name << ", correct? (y/yes n/no)" <<endl;
        cin >> answer;
        cin.get();

    }while(answer != 'y');

    system("CLS");

    //Step 2: Explain Stats
    cout << "All right. Now you have 5 stats. \n \n" <<endl;

    cout << "HP: Hit points, how much damage you can take before dying. \n" <<endl;
    cout << "Strength: The attack power of physical attacks. \n" <<endl;
    cout << "Defense: The ability to resist against physical attacks. \n" <<endl;
    cout << "Magic: The attack power of magical attacks. \n" <<endl;
    cout << "Resistance: The ability to resist against magical attacks. \n" <<endl;
    cout << "\n";

    cout << "You are provided with 15 points to distribute among your stats. Please input " <<endl;
    cout << "the stats you wish to increase. Choosing HP will increase the stat by two." <<endl;
    cin.get();
    system("CLS");

    //Step 3: Explain Stats
    do
    {

        cout << "Input the corresponding letter of the stat you wish to increase.If you wish to remove a" <<endl;
        cout << "point from one of your stats, input a - sign(ex. -: be brought to a menu to remove stats)" <<endl;
        cout << "You cannot remove stats past their base stat. \n " <<endl;

        cout << "\n";

        cout << "Remaining points: " << player.AP <<endl; //Display remaining AP that player can use
        cout << "\n";
        cout << "h/HP:         " << player.maxHP <<endl; //Display current maximum Health
        cout << "s/Strength:   " << player.strength <<endl; //Display current Strength
        cout << "d/Defense:    " << player.defense <<endl; //Display current Defense
        cout << "m/Magic:      " << player.magic <<endl; //Display current magic
        cout << "r/Resistance: " << player.resistance <<endl; //Display current Resistance

        cin >> answer;
        cin.get();

        if(answer == 'h' || answer == 'H') //Increase Maximum HP and health by 2 if player inputs an 'h'
        {
            player.maxHP = player.maxHP + 2;
            player.HP = player.maxHP;
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

        else if(answer == 'm' || answer == 'M') //Increase Magic by 1 point if player inputs 'M'
        {
            player.magic = player.magic + 1;
            player.AP = player.AP - 1;
        }

        else if(answer == 'r' || answer == 'R') //Increase Resistance by 1 point if player 'R'
        {
            player.resistance = player.resistance + 1;
            player.AP = player.AP - 1;
        }

        /****************  REMOVE STATS  ********************/

        else if(answer == '-')
        {
            system("CLS");
            cout << "Input the corresponding letter of the stat you wish to decrease. If you " <<endl;
            cout << "wish to increase a point from one of your stats, input something random." <<endl;
            cout << "You cannot remove stats past their base stat. \n " <<endl;

            cout << "Remaining points: " << player.AP <<endl; //Display remaining AP that player can use
            cout << "\n";
            cout << "h/HP:         " << player.maxHP <<endl; //Display current maximum Health
            cout << "s/Strength:   " << player.strength <<endl; //Display current Strength
            cout << "d/Defense:    " << player.defense <<endl; //Display current Defense
            cout << "m/Magic:      " << player.magic <<endl; //Display current magic
            cout << "r/Resistance: " << player.resistance <<endl; //Display current Resistance

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

            else if(answer == 'm' || answer == 'M') //Decrease Magic by 1 point if player inputs '-m'
            {
                if(player.magic > 1) //Check if Magic is too low to decrease
                {
                    player.magic = player.magic - 1;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << "You cannot decrease Magic any further." <<endl;
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

    //Step 4: Show Complete Character
    cout << "Okay. You're Character is now complete." <<endl;
    cout << "This is your entire character stat knowledge. \n" <<endl;
    cout << "Level: " << player.level <<" \t \t " << player.name <<endl;
    cout << "Exp:   " << player.EXP << "/" << player.maxEXP <<endl;
    cout << "\n";
    cout << "HP:         " << player.HP << "/" << player.maxHP <<endl;
    cout << "Strength:   " << player.strength <<endl;
    cout << "Defense:    " << player.defense <<endl;
    cout << "Magic:      " << player.magic <<endl;
    cout << "Resistance: " << player.resistance <<endl;
    cout << "\n";
    cin.get();
    system("CLS");

    cout << "Now, on to the fight." <<endl;

    system("CLS");

    //Step 5: Battle time

    battle(player, goblin);

    return 0;
}

/**************************************************** BATTLE CODE *********************************************************************/

void battle(character player, enemy foe)
{

    battIntroAnima(); //Start battle intro animation

    char action = 'z';
    int attmod = 0; //Strength with random modification
    int defmod = 0; //Defense with random modification
    int damage = 0;
    int looped = 4;
    int pAct = 1;

    cout << "You encountered a " << foe.name << "!" <<endl;
    cin.get();

    /****************    Default battle menu    **********************/

    while(player.HP > 0 && foe.HP > 0)
    {
        looped = 4;

        if(pAct == 0)
        {
            while(looped > 0) //Getting hit animation
            {
                system("COLOR C7");
                Sleep(20);
                system("COLOR 07");
                Sleep(20);
                looped--;
            }


            damage = attack(foe.strength, player.defense);

            player.HP = player.HP - damage;

            cout << "The " <<foe.name << " dealt " << damage << " damage!" <<endl;
            cin.get();
            pAct = 1;
        }

        while(pAct == 1)
        {
            system("CLS");

            cout << "What will you do?" <<endl;
            cout << "\n";
            cout << "\n";

            //system("color 0C"); //Create enemy in an "unfriendly color"
            cout << "   " << foe.name <<endl; //display enemy name
            cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
            cout << "\n" <<endl;

            //system("color 02"); //create player in a "friendly color"
            cout << "   " << player.name <<endl; //Display player's name
            cout << "   " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
            cout << "\n" <<endl;

            //system("color 07");//Reset text color
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

                foe.HP = foe.HP - damage; //Deal damage to enemy

                cout << "You dealt " <<damage<< " damage!" <<endl;
                cin.get();

                pAct = 0; //allow enemy to attack

            }

            else if(action == 'M' || action == 'm')
            {
                damage = magic(player, foe);

                system("CLS");
                if(damage > 0)
                {
                    foe.HP = foe.HP - damage;
                    cout << "You dealt " <<damage <<" damage!" <<endl;
                    cin.get();
                    pAct = 0;
                }
            }

            else if(action == 'D' || action == 'd')
            {        while(looped > 0) //Getting hit animation
        {
            system("COLOR C7");
            Sleep(20);
            system("COLOR 07");
            Sleep(20);
            looped--;
        }


                cout << "I'm still working on this soz bro" <<endl;
                cin.get();
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
        cout << "You have failed..." <<endl;
    }

    else if(foe.HP < 1)
    {
        cout << "You won the battle!" <<endl;
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

/************************   ATTACK CALCULATIONS ***********************************/

int attack(int strength, int defense)
{
    int rand();
    if(strength > 0)
    {
        srand(time(NULL));
        strength = (rand() % (strength*2)-(strength/2));
    }

    if(defense > 0)
    {
        srand(time(NULL));
        defense = (rand() % (defense*2)-(defense/2));
    }


    int damage = strength - defense/2;

    if(damage < 1)
    {
        damage = 1;
    }

    return damage;

}

/************************  ATTACK CALCULATIONS **********************************/

/***********************   MAGIC MENU  **************************************/


int magic(character player, enemy foe)
{
    char action; //choice player makes
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
    cout << "   " << player.name <<endl; //Display player's name
    cout << "   " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
    cout << "\n" <<endl;

    /*********************** WHY DID I DO THIS TO MYSELF ********************/

    //system("color 07");//Make background text grayed out to reduce visual confusion
    cout << "\t                   ____________________________________________" <<endl;
    //system("color 08");
    cout << "\t A: ATTACK        |                                            |"<<endl;
    //system("color 07");
    //system("color 08");
    cout << "\t M: MAGIC ------->|  F: FIRE - Basic Damage                    |"<<endl;
    //system("color 07");
    //system("color 08");
    cout << "\t D: DEFEND        |  I: ICE - Chance to immobilize enemy       |"<<endl;
    //system("color 07");
    //system("color 08");
    cout << "\t I: *Coming soon* |  T: THUNDER - High damage, recoil possible |"<<endl;
    //system("color 07");
    //system("color 08");
    cout << "\t R: *Coming soon* |  C: CURE - Restore health to self          |"<<endl;
    //system("color 07");
    cout << "\t                  |____________________________________________|" <<endl;

    /*********************** WHY DID I DO THIS TO MYSELF *********************/

    cout << "\n";
    cin >> action;
    cin.get();

    if(action == 'F' || action == 'f') //Fire code
    {
        power = player.magic*1.5;
        damage = attack(player.magic, foe.resistance);

        return damage;
    }

    else if(action == 'I' || action == 'i') //Ice code
    {
        power = player.magic*0.5;
        damage = attack(player.magic, foe.resistance);

        return damage;

        /******************************************
             INSERT CHANCE OF ENEMY FREEZING
        ******************************************/
    }

    else if(action == 'T' || action == 't') //Thunder code
    {
        power = player.magic*2;

        attack(player.magic, player.resistance);

        if(foe.resistance > 0)
        {
            damage = damage-(foe.resistance);
        }

        /******************************************
            INSERT VARIABLITY TO ATTACK POWER
            INSERT CHANCE OF RECIEVING RECOIL
        ******************************************/

    }

    else if(action == 'C' || action == 'c') //Cure code
    {
        damage = player.magic;

        player.HP = player.HP + damage;

        if(player.HP >= player.maxHP)
        {
            cout << "You maxed your health out. " <<endl;
            player.HP = player.maxHP; //make sure health doesn't go over maximum health
        }

        else
        {
            cout << "You recovered " <<damage<< " Hit Points." <<endl;
        }

        /*********************************************
            USE A DIFFERENT VARIABLE FOR HEALING
        *********************************************/

    }

    else
    {
        cout << "Not an option." <<endl;
    }


}


/**************************************************** BATTLE CODE *********************************************************************/


