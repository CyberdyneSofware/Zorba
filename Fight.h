#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>


int fight1();
void mon();
using namespace std;

/********************************\
Mahmud Taylor 04/06/18           |
This is a basic fighting code for|
an RPG style text game along with|
a character creation thing       |
\********************************/


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
void menu();
bool battle(enemy foe); //Function for the basic battle setup

int magicOne(enemy foe); //The Level 1 Magic Menu for the Battle
int magicTwo(enemy foe); //The Level 2 Magic Menu for the Battle
int magicThree(enemy foe); //The Level 3 Magic Menu for the Battle
void healPage(); //Cure page for out of battle

void levelUp(); //Function to Level up the Player
void allotAP(); //Function to allow Player to allot Ability Points
void viewStat(); //Function allowing player to view stats

int attack(int strength, int defense); //Mathematics for damaging the enemy
int eneattack(int strength, int defense); //Mathematics for being attacked
int cure(int magic); //Mathematics for healing oneself

void doublestat(); //Function to raise the enemy stats by a multiple of 2

void damageAnima(); //Animation for being damaged
void attackEneAnima(); //Animation for damaging the enemy
void healingAnima(); //Animation for healing oneself

void spookyMessage(); //Silly little spooky message if you try to run from Hitler.
void removeRun(); //Indicate visually running away isn't possible
void displayRun(); //Displays Run away or not depending on if special message has been moved

character player; //Create Player character

enemy mook; //Create easy enemy
enemy knight; //Create slightly harder enemy
enemy daemon; //Create difficult enemy
enemy hitler; //Create Boss enemy

char active = 'n'; //Variable for player action during battle

char enetype = '0'; //Variable to allow different enemy attack patterns

int insult = 1; //Variable for insults from Hitler

char runAway = 'y'; //Variable to show "R: RUN AWAY" in the menu

void mon()
{
    int mons;
    mons = rand() % 5 + 1;
    if(mons > 3)
    {
        fight1();
    }
    if(mons < 2)
    {
        cout << "No monsters here...\n";
    }
}
void close()
{
    if(player.HP < 0)
    {
        cout << "nothing";
        exit(EXIT_SUCCESS);
    }
    else
    {
        cout << "\n";
    }
}

int fight1()
{
    mook.name[0] = 'M'; //Make monster named "mook"
    mook.name[1] = 'o';
    mook.name[2] = 'o';
    mook.name[3] = 'k';
    mook.name[4] = '\0';
    mook.maxHP = 10; //Set mook's health to 10
    mook.HP = mook.maxHP;
    mook.strength = 2; //Set mook's Strength to 3
    mook.intelligence = 1; //Set mook's intelligence to 2
    mook.defense = 1; //Set mook's Defense to 1
    mook.resistance = 1; //Set mook's Resistance to 0
    mook.EXP = 25; //Set EXP gained from mook to 25

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
    daemon.maxHP = 40; //Set Daemon's Health to 40
    daemon.HP = daemon.maxHP;
    daemon.strength = 15; //Set Daemon's Strength to 15
    daemon.intelligence = 4; //Set Daemon's Intelligence to 4
    daemon.defense = 15; //Set Daemon's Defense to 15
    daemon.resistance = 5; //Set Daemon's Resistance to 5
    daemon.EXP = 200; //Set EXP gained from Daemon to 200

    hitler.name[0] = 'H'; //Make boss name Hitler
    hitler.name[1] = 'i';
    hitler.name[2] = 't';
    hitler.name[3] = 'l';
    hitler.name[4] = 'e';
    hitler.name[5] = 'r';
    hitler.name[6] = '\0';
    hitler.maxHP = 5000; //Set Hitler's Health to 5000
    hitler.HP = hitler.maxHP;
    hitler.strength = 100; //Set Hitler's Strength to 100
    hitler.intelligence = 100; //Set Hitler's Intelligence to 100
    hitler.defense = 150; //Set Hitler's Defense to 150
    hitler.resistance = 150; //Set Hitler's Resistance to 150

    battle(knight);
    return 0;
}
void menu()
{
    char answer = 'n'; //Choice that the player makes
    bool victory = true; //bool variable for if player won or lost a battle

    while(player.HP > 0)
    {
        active = 'n';//Reset Player action
        enetype = '0'; //Reset Enemy Type
        //Display choices
        cout << "What would you to do?" <<endl;
        cout << "\n";
        cout << "M/Mook Battle" <<endl;
        cout << "K/Knight Battle" <<endl;
        cout << "D/Daemon Battle" <<endl;
        cout << "\n";
        cout << "I/Increase power of normal monsters by times 2" <<endl;
        cout << "\n";
        cout << "H/Hitler Boss Battle" <<endl;
        cout << "\n";
        cout << "C/Cure Self" <<endl;
        cout << "V/View stats" <<endl;
        cout << "\n";
        cin >> answer;
        cin.get();

        system("CLS");

        if(answer == 'm' || answer == 'M')// Player wishes to fight a Mook
        {
            cout << "Very well." <<endl;
            cin.get();
            victory = battle(mook);
        }

        else if(answer == 'k' || answer == 'K') //Player wishes to fight a Knight
        {
            cout << "Very well." <<endl;
            cin.get();
            victory = battle(knight);
        }

        else if(answer == 'd' || answer == 'D') //Player wishes to fight a daemon
        {
            cout << "Very well." <<endl;
            cin.get();
            victory = battle(daemon);
        }

        else if(answer == 'h' || answer == 'H')//Player wishes to challenge Hitler
        {
            //Ensure player wishes to do so
            cout << "This is Hitler we are talking about. Are you sure you want to do this??" <<endl;
            cout << "          _______________                  _______________" <<endl;
            cout << "         |               |                |               |" <<endl;
            cout << "         |     Y/YES     |                |     N/NO      |" <<endl;
            cout << "         |_______________|                |_______________|" <<endl;
            cout << "\n";
            cin >> answer;
            cin.get();
            system("CLS");
            if(answer == 'y' || answer == 'Y') //Initiate Hitler Battle
            {
                cout << "Very well then. Good luck " <<player.name <<"." <<endl;
                system("PAUSE");
                enetype = 'h';
                victory = battle(hitler);
            }

            else
            {
                cout << "That is the wise choice." <<endl;
                cin.get();
            }
        }

        else if(answer == 'i' || answer == 'I') //Player wishes to increase power of enemies
        {
            cout << "You may die because of this." <<endl;
            doublestat();
            system("PAUSE");
            system("CLS");
        }

        else if(answer == 'c' || answer == 'C') //Player wishes to heal themself
        {
            system("CLS");
            healPage();
            system("CLS");
        }

        else if(answer == 'v' || answer == 'V') //Player wishes to view current Stats
        {
            viewStat();
        }

        else
        {
            cout << "Not an option" <<endl;
            system("PAUSE");
            system("CLS");
        }
    }

    if(player.HP < 1) //If player has died, end game
    {
        cout<< "It looks like that's all for you." <<endl;
    }

}
/**************************************************** BATTLE CODE *********************************************************************/

bool battle(enemy foe)
{

    system("CLS");

    srand(time(NULL));
    char action = 'z';
    int attmod = 0; //Strength buffs
    int defmod = 1; //Defense buffs
    int damage = 0; //Damage that will be dealt
    int pAct = 1; //Actions Player has remaining
    char message = 'n'; //Freeze message indicator
    int chance; //Random number holder

    if(enetype == 'h')//Notify player that they have encountered Hitler
    {
        cout << player.name << " encountered Hitler!!!" <<endl;
    }

    else//Notify player that they have encountered a monster
    {
        cout << player.name << " encountered a " << foe.name << "!" <<endl;
    }

    cin.get();

    /*******************************    Default battle menu    ***************************************/

    while(player.HP > 0 && foe.HP > 0 && !(active == 'r' || active == 'R'))
    {
        active = 'n';

        if(pAct == 0) //When Player is unable to move
        {
            if(enetype == 'h')//IF PLAYER IS FIGHTING HITLER
            {

                chance = rand() % 100 + 1; //Get random number

                if(chance > 0  && chance <= 35) //PHYSICAL ATTACK
                {
                    cout << "Hitler swung at you!" <<endl;
                    cin.get();

                    defmod = (player.defense*defmod)/insult; //Determine Player's Defenses

                    damage = eneattack(foe.strength, defmod); //Determine Damage Taken

                    defmod = 1; //Reset Defense Multiplier

                    player.HP = player.HP - damage; //Take Damage

                    cout << "Hitler dealt " << damage << " damage!" <<endl;
                    cin.get();
                    pAct++; //Allow player to move
                    message = 'n';
                }

                else if(chance > 35 && chance < 70) //MAGICAL ATTACK
                {
                    cout << "Hitler used his Flamethrower!" <<endl;
                    cin.get();

                    defmod = (player.resistance*defmod)/insult; //Determine Player's resistance

                    damage = eneattack(foe.intelligence, defmod);//Determine damage taken

                    defmod = 1;//Reset Defense multiplier

                    player.HP = player.HP - damage; // Take Damage

                    cout << "Hitler dealt " << damage << " damage!" <<endl;
                    cin.get();
                    pAct++; //Allow Player to move
                    message = 'n';
                }

                else //GET INSULTED
                {
                    cout << "Hitler screams at your lack of pure being." <<endl; //Insult Player
                    cin.get();
                    cout << player.name << "'s defense and resistance feels to be half of what they once were..." <<endl;
                    cin.get();
                    pAct++; //Allow player to move
                    insult = 3; //Reduce player's defense and resistance
                    message = 'n';
                }
            }

            else
            {
                cout << "The " << foe.name << " swung at you!" <<endl;
                cin.get();
                defmod = player.defense*defmod; //Determine Player Defenses

                damage = eneattack(foe.strength, defmod); //Determine damage taken

                defmod = 1; //Reset Defensive Multiplier

                player.HP = player.HP - damage; //Take damage

                cout << "The " <<foe.name << " dealt " << damage << " damage!" <<endl;
                cin.get();
                pAct++; //Allow player to Move
                message = 'n';
            }
        }

        if(player.HP < 1)//The player has died
        {
            system("CLS");
            cout << player.name << " has died..." <<endl;
            cin.get();
            return false; //End Game
        }

        system("CLS");

        if(insult > 1) //If player is currently effected by an insult
        {
            insult--; //lower insult
            if(insult == 1) //If insult was lowered back to 1, recover defense and resistance
            {
                cout << player.name << " has recovered their defense and resistance!" <<endl;
                cin.get();
                insult = 1;
            }

        }

        system("CLS");


        if(pAct >=1)
        {
            if (message == 'y') //If the enemy is frozen
            {
                cout << "The enemy is frozen." <<endl;
                cin.get();
            }

            system("CLS");

            cout << "What will you do?" <<endl;
            cout << "\n";
            cout << "\n";

            cout << "   " << foe.name <<endl; //display enemy name
            cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
            cout << "\n" <<endl;

            cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
            cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
            cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

            cout << "\n";
            cout << "\n";
            cout << "\t A: ATTACK" <<endl;
            cout << "\t M: MAGIC" <<endl;
            cout << "\t D: DEFEND" <<endl;
            cout << "\t I: INVENTORY" <<endl;
            displayRun();
            cout << "\n";
            cin >> action; //Have player choose what they want to do
            cin.get();

            if(action == 'A' || action == 'a')
            {

                damage = attack(player.strength, foe.defense); //Calculate damage

                system("CLS");

                foe.HP = foe.HP - damage; //Deal damage to enemy

                cout << player.name << " dealt " <<damage<< " damage!" <<endl;
                cin.get();

                pAct--; //allow enemy to attack

            }

            else if(action == 'M' || action == 'm')
            {
                damage = magicOne(foe);// Make damage equal to what is brought back / Take player to Level 1 Spell Page

                system("CLS");
                if(damage > 0)
                {
                    foe.HP = foe.HP - damage; //Deal damage to the enemy
                    cout << player.name << " dealt " <<damage << " damage!" <<endl;
                    cin.get();
                    chance = (rand() % 100) + 1; //Get random number between 1 and 100

    /********************** RECOIL **************************/
                    if(active == 't') //If Casted Thunder, Implement chance of recoil
                    {


                        if(chance >= 0 && chance <= 30) //30% chance of recoil damage
                        {
                            int power = player.intelligence * 3; //Create damage increase
                            damage = attack(power, player.resistance); //Determine Recoil Damage
                            damage = damage/2; //Reduce damage dealt
                            player.HP = player.HP - damage; //Take the damage
                            damageAnima();
                            cout << player.name << "  took " << damage << " points of recoil damage!" <<endl;
                            cin.get();
                        }

                    }
    /************************* RECOIL **************************/
    /**************************FREEZING *************************/
                    else if(active == 'i')
                    {


                        cin.get();

                        if(chance >= 0 && chance <= 40) //40% chance to freeze enemy
                        {
                            cout << player.name << "  froze the " <<foe.name <<"!" <<endl;
                            cin.get();
                            pAct = 4; //Provide 3 free actions for the player
                            message = 'y'; //Activate frozen message
                        }
                    }


                    pAct--;//Remove variable for player taking a turn
                }

     /************************* FREEZING ***********************/
     /************************** HEALING ***********************/

                else if(damage < 0) //If returned damage is less than 0
                {
                    healingAnima();

                    damage = -damage;//Make damage positive so it heals
                    player.HP = player.HP + damage; //Restore HP
                    if(player.HP >= player.maxHP) //Different message if fully restored
                    {
                        cout << player.name << " has been healed to full health!" <<endl;
                        player.HP = player.maxHP; //Bring HP down to MaxHP
                    }

                    else
                    {
                        cout << player.name << " has restored " <<damage << " HP!" <<endl;
                    }

                    cin.get();
                    pAct--; //Remove variable allowing player action
                }

            }

        /******************* HEALING *******************/

            else if(action == 'D' || action == 'd') //Increase Defense
            {
                defmod = 3; //Multiply defense by 3 for 1 turn
                cout << player.name << " protected themself from oncoming attacks!" <<endl;
                cin.get();
                pAct--;
            }

            else if(action == 'I' || action == 'i') // Call the inventory
            {
                cout << "This is a placeholder until Philly Compiles code to have inventory as well." <<endl;
                cout << "For now, this action does nothing." <<endl;
                system("PAUSE");
            }

            else if((action == 'R' || action == 'r') && runAway == 'y')
            {
                if(enetype == 'h') //If it is Hitler, can't run away
                {
                    system("CLS");
                    cout << "There is no running away now." <<endl;
                    cin.get();
                    spookyMessage(); //Play spooky message
                }

                else //Allow player to run away
                {
                    active = action;
                }

            }

            else //If user inputted something that wasn't an option
            {
                cout << "Not an option meh dude" <<endl;
                cin.get();
            }
        }

        system("CLS");
    }


    if(player.HP < 1) //If the player dies
    {
        system("CLS");
        cout << player.name << " has died..." <<endl;
        cin.get();
        return false; //End game
    }

    else if(foe.HP < 1) //Allow Player to achieve victory if enemy dies
    {
        cout << player.name << " won the battle!" <<endl;
        cin.get();

        cout << player.name << " gained " <<foe.EXP << " Experience points!" <<endl;
        cin.get();

        system("CLS");

        player.EXP = player.EXP + foe.EXP; //Grant Player EXP

        if(player.EXP >= player.maxEXP)
        {
            levelUp(); //Grant player new stats if they gained enough EXP
        }

        return true;

    }


    else if(active == 'r' || active == 'R') //Take player out of battle
    {
        system("CLS");
        cout << player.name << " ran away!" <<endl;
        return true;
        cin.get();
    }

    /****************    Default battle menu    **********************/
}


/***********************   MAGIC MENU  **************************************/

/************************ LEVEL 1 SPELLS *************************/

int magicOne(enemy foe)
{
    char action; //choice player makes
    do{

        float damage = 0; //damage dealt or taken
        float power = 1; //Multiplicative power of Spells

        system("CLS");

        cout << "What spell will you choose?" <<endl;
        cout << "\n";
        cout << "\n";

        cout << "   " << foe.name <<endl; //display enemy name
        cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
        cout << "\n" <<endl;

        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

        /*********************** WHY DID I DO THIS TO MYSELF ********************/

        if(player.level < 5)
        {
            cout << "\t               _______________________________________________" <<endl;
            cout << "\t              |                LEVEL 1 SPELLS                 |" <<endl;

            cout << "\t A: ATTACK    | <-- G: GO BACK                                |"<<endl;

            cout << "\t M: MAGIC --->| 2MP/F: FIRE - Basic Damage                    |"<<endl;

            cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       |"<<endl;

            cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible |"<<endl;

            displayRun();
            cout <<                 "| 3MP/C: CURE - Restore health to self          |"<<endl;

            cout << "\t              |_______________________________________________|" <<endl;
        }

        else if(player.level >= 5 && player.level < 10) //If player level is 5 or higher, display Level 2 Spell Tab
        {
            cout << "\t               _______________________________________________ __________" <<endl;
            cout << "\t              |                LEVEL 1 SPELLS                 | LEVEL 2  |" <<endl;

            cout << "\t A: ATTACK    | <-- G: GO BACK          L: LEVEL 2 SPELLS --> |          |"<<endl;

            cout << "\t M: MAGIC --->| 2MP/F: FIRE - Basic Damage                    | FIRE 2   |"<<endl;

            if(player.level < 6)
            {
                cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       |          |"<<endl;

                cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible |          |"<<endl;

                displayRun();
                cout <<                 "| 3MP/C: CURE - Restore health to self          |          |"<<endl;

                cout << "\t              |_______________________________________________|__________|" <<endl;
            }

            else if(player.level >= 6) //If level is 6 or higher, display Ice 2
            {

                cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       | ICE 2    |"<<endl;

                if(player.level < 7)
                {


                    cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible |          |"<<endl;

                    displayRun();
                    cout <<                 "| 3MP/C: CURE - Restore health to self          |          |"<<endl;

                    cout << "\t              |_______________________________________________|__________|" <<endl;
                }

                else if(player.level >= 7) //If level is 7 higher, display Thunder 2
                {
                    cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible | THUNDER 2|"<<endl;

                    if(player.level < 8)
                    {
                        displayRun();
                        cout <<                 "| 3MP/C: CURE - Restore health to self          |          |"<<endl;

                        cout << "\t              |_______________________________________________|__________|" <<endl;
                    }

                    else if(player.level >= 8) //If level is 8 or higher, display Cure 2
                    {
                        displayRun();
                        cout <<                 "| 3MP/C: CURE - Restore health to self          | CURE 2   |"<<endl;

                        cout << "\t              |_______________________________________________|__________|" <<endl;
                    }
                }
            }
        }

        else if(player.level >= 10)//If player level is 10 or higher, then display Level 3 Spell Tab
        {
            cout << "\t               _______________________________________________ __________ __________" <<endl;
            cout << "\t              |                LEVEL 1 SPELLS                 | LEVEL 2  | LEVEL 3  |" <<endl;

            cout << "\t A: ATTACK    | <-- G: GO BACK          L: LEVEL 2 SPELLS --> |          |          |"<<endl;

            cout << "\t M: MAGIC --->| 2MP/F: FIRE - Basic Damage                    | FIRE 2   | FIRE 3   |"<<endl;

            if(player.level < 11)
            {
                cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       | ICE 2    |          |"<<endl;

                cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible | THUNDER 2|          |"<<endl;

                displayRun();
                cout <<                 "| 3MP/C: CURE - Restore health to self          | CURE 2   |          |"<<endl;

                cout << "\t              |_______________________________________________|__________|__________|" <<endl;
            }

            else if(player.level >= 11) //If player level is 11 or higher, display Ice 3
            {

                cout << "\t D: DEFEND    | 4MP/I: ICE - Chance to immobilize enemy       | ICE 2    | ICE 3    |"<<endl;

                if(player.level < 12)
                {


                    cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible | THUNDER 2|          |"<<endl;

                    displayRun();
                    cout <<                 "| 3MP/C: CURE - Restore health to self          | CURE 2   |          |"<<endl;

                    cout << "\t              |_______________________________________________|__________|__________|" <<endl;
                }

                else if(player.level >= 12) //If player level is 12 or higher, display Thunder 3
                {
                    cout << "\t I: INVENTORY | 7MP/T: THUNDER - High damage, recoil possible | THUNDER 2| THUNDER 3|"<<endl;

                    if(player.level < 13)
                    {
                        displayRun();
                        cout <<                 "| 3MP/C: CURE - Restore health to self          | CURE 2   |          |"<<endl;

                        cout << "\t              |_______________________________________________|__________|__________|" <<endl;
                    }

                    else if(player.level >= 13) //If player level is 13 or higher, display Cure 3
                    {
                        cout << "\t R: RUN AWAY  | 3MP/C: CURE - Restore health to self          | CURE 2   | CURE 3   |"<<endl;

                        cout << "\t              |_______________________________________________|__________|__________|" <<endl;
                    }
                }
            }
        }
        /*********************** WHY DID I DO THIS TO MYSELF *********************/

        cout << "\n";
        cin >> action;
        cin.get();

        if(action == 'F' || action == 'f') //Fire code
        {
            if(player.MP >= 2)
            {
                cout << player.name << " casted FIRE!" <<endl;
                cin.get();
                power = player.intelligence; //Make power directly equal to intelligence of player
                damage = attack(power, foe.resistance); //Determine damage dealt
                player.MP = player.MP - 2; //Remove 2 MP

                return damage; //return damage dealt
            }

            else if(player.MP < 2)
            {
                cout << player.name << " does not have enough MP to cast FIRE." <<endl;
                cin.get();
            }
        }

        else if(action == 'I' || action == 'i') //Ice code
        {
            if(player.MP >= 4)
            {
                cout << player.name << " casted ICE!" <<endl;
                cin.get();
                power = player.intelligence*0.5; //Reduce effectiveness of Spell by half
                damage = attack(power, foe.resistance); //Determine damage dealt
                player.MP = player.MP - 4; //Remove 4 MP
                active = 'i'; //Activate chance to freeze enemy
                return damage; //Return damage dealt
            }

            else if(player.MP < 4)
            {
                cout << player.name << " does not have enough MP to cast ICE." <<endl;
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
                cout << player.name << " casted THUNDER!" <<endl;
                cin.get();
                power = (player.intelligence*4)/2;//Increase effectiveness of thunder spell by 2
                damage = attack(power, foe.resistance); //Determine Damage Dealt
                player.MP = player.MP - 7; //Remove 7 MP
                active = 't'; //Activate chance of recoil
                return damage; //Return damage to be dealt
            }

            else if(player.MP < 7)
            {
                cout << player.name << " does not have enough MP to cast THUNDER." <<endl;
                cin.get();
            }

        }

        else if(action == 'C' || action == 'c') //Cure code
        {
            if(player.MP >= 3)
            {
                cout << player.name << " casted CURE!" <<endl;
                cin.get();
                damage = cure(player.intelligence); //Determine amount of health restored
                player.MP = player.MP - 3; //Remove 3 MP

                return damage; //return health to be restored
            }

            else if(player.MP < 3)
            {
                cout << player.name << " does not have enough MP to cast CURE." <<endl;
                cin.get();
            }
        }

        else if(((action == 'L') || (action == 'l')) && player.level > 4) //If player level is higher than 4
        {
            damage = magicTwo(foe); //Take the Player to the level 2 Spell Page

            if(damage != 0) //If Spell has been casted
            {
                return damage; //Return variable
            }

        }

        else if(action == 'G' || action == 'g') //Take the player back to the normal battle menu
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
        float power = 1; //Multiplier for spell damage

        system("CLS");

        cout << "What spell will you choose?" <<endl;
        cout << "\n";
        cout << "\n";

        cout << "   " << foe.name <<endl; //display enemy name
        cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
        cout << "\n" <<endl;

        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

        /*********************** WHY DID I DO THIS TO MYSELF ********************/


        if(player.level >= 10) //If player level is 10 or higher display Level 3 Spell Tab
        {
            cout << "\t               __________ _______________________________________________ __________" <<endl;
            cout << "\t              | LEVEL 1  |                LEVEL 2 SPELLS                 | LEVEL 3  |" <<endl;

            cout << "\t A: ATTACK    |          | <-- G: LEVEL 1 SPELLS   L: LEVEL 3 SPELLS --> |          |"<<endl;

            cout << "\t M: MAGIC --->| FIRE     |10MP/F: FIRE 2 - Basic Damage                  | FIRE 3   |"<<endl;

            if(player.level > 10) //If player level is higher than 10, then display Ice 3
            {
                cout << "\t D: DEFEND    | ICE      | 8MP/I: ICE 2- Chance to immobilize enemy      | ICE 3    |"<<endl;

                if(player.level > 11) //If player level is higher than 11, then display Thunder 3
                {
                    cout << "\t I: INVENTORY | THUNDER  |25MP/T: THUNDER 2- High damage, recoil possible| THUNDER 3|"<<endl;

                    if(player.level > 12) //If player level is higher than 12, then display Cure 3
                    {
                        displayRun();
                        cout <<                 "| CURE     |15MP/C: CURE 2- Restore health to self         | CURE 3   |" <<endl;

                        cout << "\t              |__________|_______________________________________________|__________|" <<endl;
                    }

                    else
                    {
                        displayRun();
                        cout <<                 "| CURE     |15MP/C: CURE 2- Restore health to self         |          |" <<endl;

                        cout << "\t              |__________|_______________________________________________|__________|" <<endl;
                    }
                }

                else
                {
                    cout << "\t I: INVENTORY | THUNDER  |25MP/T: THUNDER 2- High damage, recoil possible|          |" <<endl;
                    displayRun();
                    cout <<                 "| CURE     |15MP/C: CURE 2- Restore health to self         |          |" <<endl;

                    cout << "\t              |__________|_______________________________________________|__________|" <<endl;
                }
            }

            else
            {
                cout << "\t D: DEFEND    | ICE      | 8MP/I: ICE 2- Chance to immobilize enemy      |          |" <<endl;

                cout << "\t I: INVENTORY | THUNDER  |25MP/T: THUNDER 2- High damage, recoil possible|          |" <<endl;
                displayRun();
                cout <<                 "| CURE     |15MP/C: CURE 2- Restore health to self         |          |" <<endl;

                cout << "\t              |__________|_______________________________________________|__________|" <<endl;
            }
        }




        else if(player.level < 10)//If player level is lower than 10, do not display Level 3 Spell Tab
        {
            cout << "\t               __________ _______________________________________________" <<endl;
            cout << "\t              | LEVEL 1  |                LEVEL 2 SPELLS                 |" <<endl;

            cout << "\t A: ATTACK    |          | <-- G: GO BACK                                |"<<endl;

            cout << "\t M: MAGIC --->| FIRE     |10MP/F: FIRE 2 - Basic Damage                  |"<<endl;

            if(player.level > 5) //If player level is higher than 5, display Ice 2
            {
                cout << "\t D: DEFEND    | ICE      | 8MP/I: ICE 2- Chance to immobilize enemy      |"<<endl;

                if(player.level > 6) //If player level is higher than 6, display Thunder 2
                {
                    cout << "\t I: INVENTORY | THUNDER  |25MP/T: THUNDER 2- High damage, recoil possible|"<<endl;

                    if(player.level > 7) //If player level is higher than 7, display Cure 2
                    {
                        displayRun();
                        cout <<                 "| CURE     |15MP/C: CURE 2- Restore health to self         |" <<endl;

                        cout << "\t              |__________|_______________________________________________|" <<endl;
                    }

                    else
                    {
                        displayRun();
                        cout <<                 "| CURE     |                                               |" <<endl;

                        cout << "\t              |__________|_______________________________________________|" <<endl;
                    }
                }

                else
                {
                    cout << "\t I: INVENTORY | THUNDER  |                                               |" <<endl;
                    displayRun();
                    cout <<                 "| CURE     |                                               |" <<endl;

                    cout << "\t              |__________|_______________________________________________|" <<endl;
                }
            }

            else
            {
                cout << "\t D: DEFEND    | ICE      |                                               |" <<endl;

                cout << "\t I: INVENTORY | THUNDER  |                                               |" <<endl;
                displayRun();
                cout <<                 "| CURE     |                                               |" <<endl;

                cout << "\t              |__________|_______________________________________________|" <<endl;
            }
        }


        /*********************** WHY DID I DO THIS TO MYSELF *********************/

        cout << "\n";
        cin >> action;
        cin.get();

        if(action == 'F' || action == 'f') //Fire 2 code
        {
            if(player.MP >= 10)
            {
                cout << player.name << " casted FIRE 2" <<endl;
                cin.get();
                power = (player.intelligence*3)/2; //Make Fire Spell 3 times as effective
                damage = attack(power, foe.resistance); //Determine amount of damage dealt
                player.MP = player.MP - 10; //Remove 10 MP

                return damage;
            }

            else if(player.MP < 10)
            {
                cout << player.name << " does not have enough MP to cast FIRE 2." <<endl;
                cin.get();
            }
        }

        else if((action == 'I' || action == 'i') && player.level > 5) //Ice 2 code
        {
            if(player.MP >= 8)
            {
                cout << player.name << " casted ICE 2!" <<endl;
                cin.get();
                power = player.intelligence*0.75; //Reduce effectiveness of Spell by 3/4
                damage = attack(power, foe.resistance); //Determine amount of damage dealt
                player.MP = player.MP - 8; //Remove 8 MP
                active = 'i'; //Activate random chance to freeze enemy
                return damage;
            }

            else if(player.MP < 8)
            {
                cout << player.name << " does not have enough MP to cast ICE 2." <<endl;
                cin.get();
            }

            /******************************************
                 INSERT CHANCE OF ENEMY FREEZING
            ******************************************/
        }

        else if((action == 'T' || action == 't') && player.level > 6)//Thunder 2 code
        {
            if(player.MP >= 25)
            {
                cout << player.name << " casted THUNDER 2!" <<endl;
                cin.get();
                power = (player.intelligence*7)/2; //Make Thunder Spell 7 times as effective
                damage = attack(power, foe.resistance); // Determine amount of damage dealt
                player.MP = player.MP - 25; //Remove 25 MP
                active = 't'; //Activate random chance of recoil
                return damage;
            }

            else if(player.MP < 25)
            {
                cout << player.name << " does not have enough MP to cast THUNDER 2." <<endl;
                cin.get();
            }

        }

        else if((action == 'C' || action == 'c') && player.level > 7) //Cure 2 code
        {
            if(player.MP >= 15)
            {
                cout << player.name << " casted CURE 2!" <<endl;
                cin.get();
                power = player.intelligence*3; //Make Cure spell 3 times as effective
                damage = cure(power); //Determine amount of health restored
                player.MP = player.MP - 15;//Remove 15 MP

                return damage;
            }

            else if(player.MP < 15) //If player doesn't have sufficient MP
            {
                cout << player.name << " does not have enough MP to cast CURE 2." <<endl;
                cin.get();
            }
        }

        else if(action == 'G' || action == 'g') //Take the player back to Level 1 Spell Page
        {
            return 0;
        }

        else if(((action == 'L') || (action == 'l')) && player.level > 9) //If Level 3 Spell Page is unlocked
        {
            damage = magicThree(foe); //Take player to Level 3 Spell Page

            if(damage != 0) //If user casted a spell, return the damage dealt
            {
                return damage;
            }

        }

        else //If none of the above apply
        {
            cout << "Not an option." <<endl;
            cin.get();
        }

    }while(action != 'g' || action != 'G'); //Send player back to normal menu


}

/****************************** LEVEL 2 SPELLS ************************************/

/****************************** LEVEL 3 SPELlS *************************************/
int magicThree(enemy foe)
{
    char action; //choice player makes
    do
    {

        float damage = 0; //damage dealt or taken
        float power = 1; //Multiplicative power of spells

        system("CLS");

        cout << "What spell will you choose?" <<endl;
        cout << "\n";
        cout << "\n";

        cout << "   " << foe.name <<endl; //display enemy name
        cout << "   " << foe.HP << "/" <<foe.maxHP <<endl; //display enemy health
        cout << "\n" <<endl;

        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana

        /*********************** WHY DID I DO THIS TO MYSELF ********************/

        cout << "\t               __________ __________ _______________________________________________" <<endl;
        cout << "\t              | LEVEL 1  | LEVEL 2  |                LEVEL 3 SPELLS                 |" <<endl;


        cout << "\t A: ATTACK    |          |          | <-- G: GO BACK                                |"<<endl;

        cout << "\t M: MAGIC --->| FIRE     | FIRE 2   |25MP/F: FIRE 3 - Basic Damage                  |"<<endl;

        if(player.level > 10) //If player is higher than level 10, display the Ice 3 Spell
        {
            cout << "\t D: DEFEND    | ICE      | ICE 2    |12MP/I: ICE 3- Chance to immobilize enemy      |"<<endl;

            if(player.level > 11) //If player is higher than level 11, display the Thunder 3 Spell
            {
                cout << "\t I: INVENTORY | THUNDER  | THUNDER 2|50MP/T: THUNDER 3- High damage, recoil possible|"<<endl;

                if(player.level > 12) //If player is higher than level 12, display the Cure 3 Spell
                {
                    displayRun();
                    cout <<                 "| CURE     | CURE 2   |30MP/C: CURE 3- Restore health to self         |" <<endl;

                    cout << "\t              |__________|__________|_______________________________________________|" <<endl;
                }

                else
                {
                    displayRun();
                    cout <<                 "| CURE     | CURE 2   |                                               |" <<endl;

                    cout << "\t              |__________|__________|_______________________________________________|" <<endl;
                }
            }

            else
            {
                cout << "\t I: INVENTORY | THUNDER  | THUNDER 2|                                               |" <<endl;
                displayRun();
                cout <<                 "| CURE     | CURE 2   |                                               |" <<endl;

                cout << "\t              |__________|__________|_______________________________________________|" <<endl;
            }
        }

        else
        {
            cout << "\t D: DEFEND    | ICE      | ICE 2    |                                               |" <<endl;

            cout << "\t I: INVENTORY | THUNDER  | THUNDER 2|                                               |" <<endl;
            displayRun();
            cout <<                 "| CURE     | CURE 2   |                                               |" <<endl;

            cout << "\t              |__________|__________|_______________________________________________|" <<endl;
        }


        /*********************** WHY DID I DO THIS TO MYSELF *********************/

        cout << "\n";
        cin >> action; //Allow character to choose an option
        cin.get();

        if(action == 'F' || action == 'f') //Fire 3 code
        {
            if(player.MP >= 25)
            {
                cout << player.name << " casted FIRE 3!" <<endl;
                cin.get();
                power = (player.intelligence*5)/2; //Make Fire Spell 5 times more effective
                damage = attack(power, foe.resistance); //Determine amount of damage dealt
                player.MP = player.MP - 25; //Subtract 25 MP

                return damage;
            }

            else if(player.MP < 25) //If player doesn't have enough MP
            {
                cout << player.name << " does not have enough MP to cast FIRE 3." <<endl;
                cin.get();
            }
        }

        else if((action == 'I' || action == 'i') && player.level > 10) //Ice 3 code
        {
            if(player.MP >= 12)
            {
                cout << player.name << " casted ICE 3!" <<endl;
                cin.get();
                power = player.intelligence*1.75; //Make the Ice Spell 1.75 times more effective
                damage = attack(power, foe.resistance); //Determine amount of damage dealt
                player.MP = player.MP - 12; //Subtract 12 MP
                active = 'i'; //Activate the freeze enemy chance
                return damage;
            }

            else if(player.MP < 12) //If player doesn't have enough MP
            {
                cout << player.name << " does not have enough MP to cast ICE 3." <<endl;
                cin.get();
            }

            /******************************************
                 INSERT CHANCE OF ENEMY FREEZING
            ******************************************/
        }

        else if((action == 'T' || action == 't') && player.level > 11) //Thunder 3 code
        {
            if(player.MP >= 50)
            {
                cout << player.name << " casted THUNDER 3!" <<endl;
                cin.get();
                power = (player.intelligence*14)/2; //Make the Thunder Spell 14 times more effective
                damage = attack(power, foe.resistance); //Determine amount of damage dealt
                player.MP = player.MP - 50; //Subtract 50 MP
                active = 't'; //Activate the recoil damage chance
                return damage;
            }

            else if(player.MP < 50)//If player doesn't have enough MP
            {
                cout << player.name << " does not have enough MP to cast THUNDER 3." <<endl;
                cin.get();
            }

        }

        else if((action == 'C' || action == 'c') && player.level > 12) //Cure 3 code
        {
            if(player.MP >= 30)
            {
                cout << player.name << " casted CURE 3!" <<endl;
                cin.get();
                power = player.intelligence * 5; //Make Cure spell 5 times more effective
                damage = cure(power); //Determine amount of health restored
                player.MP = player.MP - 30; //Subtract 30 MP

                return damage;
            }

            else if(player.MP < 30)//If player doesn't have enough MP
            {
                cout << player.name << " does not have enough MP to cast CURE 3." <<endl;
                cin.get();
            }
        }

        else if(action == 'G' || action == 'g') //Take Player back to Level 2 Spell Page
        {
            return 0;
        }

        else
        {
            cout << "Not an option." <<endl;
            cin.get();
        }

    }while(action != 'g' || action != 'G'); //Send player back to normal menu


}

/********************* LEVEL 3 SPELLS **************************/

/*******************************   MAGIC MENU  **************************************/

/************************   ATTACK CALCULATIONS ***********************************/

int attack(int strength, int defense)
{
    system("CLS");
    int rand();
    if(strength > 0)
    {
        srand(time(NULL));
        strength = strength + (rand() % 4); //Have Strength stat increased by a random number between 0 and 4
    }

    if(defense > 0)
    {
        srand(time(NULL));
        defense = defense + (rand() % 4); //Have damage dealt directly be strength minus two-thirds of the defense stat
    }


    int damage = strength - defense/2; //Have damage dealt directly be strength minus half of the defense stat

    if(damage < 1)
    {
        damage = 1; //if damage is too low, make it equal to 1.
    }

    attackEneAnima(); //Call the attacking enemy animation
    return damage;

}

int eneattack(int strength, int defense)
{
    system("CLS");
    int rand();
    if(strength > 0)
    {
        srand(time(NULL));
        strength = strength + (rand() % 4); //Have Strength stat increased by a random number between 0 and 4
    }

    if(defense > 0)
    {
        srand(time(NULL));
        defense = defense + (rand() % 4); //Have Defense stat increased by a random number between 0 and 4
    }


    int damage = strength - defense/1.5; //Have damage dealt directly be strength minus two-thirds of the defense stat

    if(damage < 1)
    {
        damage = 1; //if damage is too low, make it equal to 1.
    }

    damageAnima(); //Call damaged animation

    return damage;

}
/************************  ATTACK CALCULATIONS **********************************/

/************************  HEALING CALCULATIONS  ********************************/

int cure(int intelligence)
{
    int rand(); //add random
    int heals; //amount of health restored, will be in negative for coding purposes

    if(intelligence > 0)
    {
        srand(time(NULL));
        heals = -(intelligence) - (rand() % 6); //Health restored is directly intelligence stat with a random number between 0 and 6.
    }

    if(heals < 1)
    {
        heals = -(1 + intelligence/2); //Make Healing negative so the code knows it as a restorative spell
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
    int statHold = player.maxHP; //Create stat holder variable for the purpose of not allowing decimal stats

    system("CLS");

    cout << player.name << " has leveled up to Level " <<player.level<< "!" <<endl; //Tell player he has leveled up
    cout << "\n";
    cout << "\n";
    cin.get();

    //Display new HP
    cout << "HP         " << player.maxHP << " --> ";

    player.maxHP = player.maxHP + (2*(player.level/5 - 1)) + (statHold/player.level) + 1; //Make new HP stat with extra growth if there is a focus
    Sleep(100);
    cout << player.maxHP <<endl;
    cout << "\n";
    Sleep(100);

    //Display new MP
    cout << "MP           " << player.maxMP << " --> ";
    statHold = player.maxMP;
    player.maxMP = player.maxMP + abs(player.level/5 - 1) + (statHold/player.level) + 1; //Make new MP stat with extra growth if there is a focus
    Sleep(100);
    cout << player.maxMP <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Strength
    cout << "Strength     " << player.strength << " --> ";
    statHold = player.strength;
    player.strength = player.strength + ((player.level - 1)/5) + ((statHold/2)/player.level) + 1; //Make new Strength Stat with extra growth if there is a focus
    Sleep(100);
    cout << player.strength <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Defense
    cout << "Defense      " <<player.defense << " --> ";
    statHold = player.defense;
    player.defense = player.defense + ((player.level - 1)/5) + ((statHold/2)/player.level) + 1; //Make new Defense Stat with extra growth if there is a focus
    Sleep(100);
    cout << player.defense <<endl;
    cout << "\n";
    Sleep(100);

    //Display new intelligence
    cout << "Intelligence " <<player.intelligence << " --> ";
    statHold = player.intelligence;
    player.intelligence = player.intelligence + ((player.level - 1)/5) + ((statHold/2)/player.level) + 1; //Make new Intelligence stat with extra growth if there is a focus
    Sleep(100);
    cout << player.intelligence <<endl;
    cout << "\n";
    Sleep(100);

    //Display new Resistance
    cout << "Resistance   " <<player.resistance << " --> ";
    statHold = player.resistance;
    player.resistance = player.resistance + ((player.level - 1)/5) + ((statHold/2)/player.level) + 1; //Make new Resistance stat with extra growth if there is a focus
    Sleep(100);
    cout << player.resistance <<endl;
    cout << "\n";
    Sleep(100);

    //Display new AP
    cout << "AP           " <<player.AP << " --> ";
    if(player.level <= 7)
    {
        player.AP = player.AP +(1.5*(player.level - 1)); //Add AP to player
    }

    else //Make sure the AP gained doesn't get out of control
    {
        player.AP = 10;
    }

    Sleep(100);
    cout << player.AP <<endl;
    cout << "\n";
    Sleep(100);

    cin.get();
    system("PAUSE");

    system("CLS");

    if(player.level == 5) //Have the player learn Fire 2
    {
        cout << player.name << " have unlocked the Level 2 Spells Page!" <<endl;
        cin.get();
        cout << "FIRE 2 has been learned!" <<endl;
        cin.get();
    }

    else if(player.level == 6) //Have the player learn Ice 2
    {
        cout << "ICE 2 has been learned!" <<endl;
        cin.get();
    }

    else if(player.level == 7) //Have the player learn Thunder 2
    {
        cout << "THUNDER 2 has been learned!" <<endl;
        cin.get();
    }

    else if (player.level == 8) //Have the player learn Cure 2
    {
        cout << "CURE 2 has been learned!" <<endl;
        cin.get();
        cout << "All Level 2 Spells have been learned!" <<endl;
        cin.get();
    }

    else if(player.level == 10) //Have the player learn Fire 3
    {
        cout << player.name << " have unlocked the Level 3 Spells Page!" <<endl;
        cin.get();
        cout << "FIRE 3 has been learned!" <<endl;
        cin.get();
    }

    else if(player.level == 11) //Have the player learn Ice 3
    {
        cout << "ICE 3 has been learned!" <<endl;
        cin.get();
    }

    else if(player.level == 12) //Have the player learn Thunder 3
    {
        cout << "THUNDER 3 has been learned!" <<endl;
        cin.get();
    }

    else if (player.level == 13) //Have the player learn Cure 3
    {
        cout << "CURE 3 has been learned!" <<endl;
        cin.get();
        cout << "All Level 3 Spells have been learned!" <<endl;
        cin.get();
    }

    allotAP();

}

/************************************* LEVEL UP SECTION ******************************************/

/************************************ AP ALLOTMENT SYSTEM ****************************************/

void allotAP()
{
    system("CLS");

    char answer; //What the player inputs
    do
    {

        cout << "Input the corresponding letter of the stat you wish to increase.";

        if(player.level == 1) //Special message for character Creation.
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

        else if(answer == 'm' || answer == 'M') //Increase maximum MP and MP by 1 if player inputs an 'm'
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
            //Code to remove stats to as low as 1
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

            if(answer == 'h' || answer == 'H') //Decrease Maximum HP and HP by 2 if player inputs an '-h'
            {
                if(player.maxHP > 10) //Check if HP is too low to decrease
                {
                    player.maxHP = player.maxHP - 2;
                    player.HP = player.maxHP;
                    player.AP = player.AP + 1;
                }

                else
                {
                    cout << player.name << " cannot decrease HP any further. "<<endl;
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
                    cout << player.name << " cannot decrease MP any further. "<<endl;
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
                    cout << player.name << " cannot decrease Strength any further." <<endl;
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
                    cout << player.name << " cannot decrease Defense any further. " <<endl;
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
                    cout << player.name << " cannot decrease Intelligence any further." <<endl;
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

                else //If Resistance has been attempted to be lowered below 1
                {
                    cout << player.name << " cannot decrease Resistance any further. " <<endl;
                    cin.get();
                }


            }

            else //Player inputted something that wasn't an option
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

    if(player.level > 1) // Show Character stats
    {
        cout << "These are your new character stats:" <<endl;
        cout << "\n";
        cout << player.name <<" \t Level: " << player.level <<endl;
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
        //Show Complete Character stats
        cout << "Okay. You're Character is now complete." <<endl;
        cout << "This is your entire character stat knowledge. \n" <<endl;
        cout << player.name <<" \t Level: " << player.level <<endl;
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
    }

    system("CLS");
}

/************************************ AP ALLOTMENT SYSTEM ****************************************/

/*********************************** VIEW STATS **********************/
void viewStat() //Display all of Player's Current Stats
{
    system("CLS");
    cout << "\n";
    cout <<  player.name <<" \t Level: " << player.level <<endl;
    cout << "Exp:   " << player.EXP << "/" << player.maxEXP <<endl;
    cout << "\n";
    cout << "HP:           " << player.HP << "/" << player.maxHP <<endl;
    cout << "MP:           " << player.MP << "/" << player.maxMP <<endl;
    cout << "Strength:     " << player.strength <<endl;
    cout << "Defense:      " << player.defense <<endl;
    cout << "Intelligence: " << player.intelligence<<endl;
    cout << "Resistance:   " << player.resistance <<endl;
    system("PAUSE");
    system("CLS");
}
/*********************************** VIEW STATS **********************/

/**************************** DOUBLE ENEMY STATS *********************/
void doublestat()
{
    mook.maxHP = mook.maxHP*2; //Double mook's health
    mook.HP = mook.maxHP;
    mook.strength = mook.strength*2; //Double mook's strength
    mook.intelligence = mook.intelligence*2; //Double mook's intelligence
    mook.defense = mook.defense*2; //Double mook's defense
    mook.resistance = mook.resistance*2; //Double mook's resistance
    mook.EXP = mook.EXP*2; //Double mook's EXP

    knight.maxHP = knight.maxHP*2; //Double Knight's Health
    knight.HP = knight.maxHP;
    knight.strength = knight.strength*2; //Double Knight's Strength
    knight.intelligence = knight.intelligence*2; //Double Knight's Intelligence
    knight.defense = knight.defense*2; //Double Knight's Defense
    knight.resistance = knight.resistance*2; //Double Knight's Resistance
    knight.EXP = knight.EXP*2; //Double Knight's EXP

    daemon.maxHP = daemon.maxHP*2; //Double Daemon's Health
    daemon.HP = daemon.maxHP;
    daemon.strength = daemon.strength*2; //Double Daemon's Strength
    daemon.intelligence = daemon.intelligence*2; //Double Daemon's Intelligence
    daemon.defense = daemon.defense*2; //Double Daemon's Defense
    daemon.resistance = daemon.resistance*2; //Double Daemon's Resistance
    daemon.EXP = daemon.EXP*2; //Double Daemon's EXP
}
/************************ DOUBLE ENEMY STATS **************************/

/******************** HEALING OUTSIDE BATTLE PAGE *********************/
void healPage()
{
    char action = 'n'; //Player's choice
    int power = 1; //variable to make spells more powerful
    int heal = 0; //variable of amount of health restored
    int looper = 1; //variable to allow the menu to stay until player wants to leave

    while(looper == 1)
    {
        system("CLS");
        cout << "   " << player.name << "  LV " << player.level <<endl; //Display player's name and level
        cout << "   HP: " << player.HP << "/" <<player.maxHP <<endl; //Display player's Health
        cout << "   MP: " << player.MP << "/" <<player.maxMP <<endl; //Display player's Mana
        cout << "\n";
        cout << "\n";
        cout << "1/CURE 1" <<endl;
        if(player.level >= 8) //Make Cure 2 only available to those level 8 and higher
        {
            cout << "2/CURE 2" <<endl;
        }

        if(player.level >= 13) //Make Cure 3 only available to those level 13 and higher
        {
            cout << "3/CURE 3" <<endl;
        }
        cout << "G/GO BACK" <<endl;

        cin >> action;
        cin.get();

        system("CLS");
        if(action == '1') //Cure code
        {
            if(player.MP >= 3)
            {
                cout << player.name << " casted CURE!" <<endl;
                cin.get();
                system("CLS");
                heal = cure(player.intelligence); //Determine amount of health restored
                player.MP = player.MP - 3; //Remove 3 MP
            }

            else if(player.MP < 3)
            {
                cout << player.name << " does not have enough MP to cast CURE." <<endl;
                cin.get();
                system("CLS");
            }
        }

        else if((action == '2') && player.level > 7) //Cure 2 code
        {
            if(player.MP >= 15)
            {
                cout << player.name << " casted CURE 2!" <<endl;
                cin.get();
                system("CLS");
                power = player.intelligence * 3; //Make Cure spell 3 times more effective
                heal = cure(power); //Determine amount of health restored
                player.MP = player.MP - 15; //Remove 15 MP
            }

            else if(player.MP < 15)
            {
                cout << player.name << " does not have enough MP to cast CURE 2." <<endl;
                cin.get();
                system("CLS");
            }
        }

        else if((action == '3') && player.level > 12) //Cure 3 code
        {
            if(player.MP >= 30)
            {
                cout << player.name << " casted CURE 3!" <<endl;
                cin.get();
                system("CLS");
                power = player.intelligence * 5; //Make Cure spell 5 times more effective
                heal = cure(power); //Determine amount of health restored
                player.MP = player.MP - 30; //Remove 30 MP

            }

            else if(player.MP < 30)//If player doesn't have enough MP
            {
                cout << player.name << " does not have enough MP to cast CURE 3." <<endl;
                cin.get();
                system("CLS");
            }
        }


        else if(action == 'g' || action == 'G') //This is to indicate that the Player wishes to go back the menu
        {
            looper = 0; //end the loop and return to menu
        }

        else
        {
            cout << "That is not an option." <<endl;
            cin.get();
            system("CLS");
        }

        if(heal < 0) //This is to indicate that the healing has been done
        {
            healingAnima();

            heal = -heal; //Reverse the heal so it restores Health
            player.HP = player.HP + heal; //Restore HP
            if(player.HP >= player.maxHP) //Different Messages for after status
            {
                cout << player.name << " has been healed to full health!" <<endl;
                player.HP = player.maxHP;
            }

            else
            {
                cout << player.name << " has restored " <<heal << " HP!" <<endl;
            }

            cin.get();

        }


    }



}
/******************** HEALING OUTSIDE BATTLE PAGE *********************/

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

/************************ GETTING ATTACKED ANIMATION ******************/

void damageAnima()
{
    int looped = 4;
    while(looped > 0) //Getting hit animation
    {
        system("COLOR 47"); //Make Screen Red
        Sleep(25);
        system("COLOR 07"); //Make Screen Black
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
        system("COLOR E7"); //Make screen Yellow
        Sleep(25);
        system("COLOR 07"); //Revert Screen Black
        Sleep(25);
        looped--;
    }
}
/***************** ATTACKING ENEMY ANIMATION ***********************/

/***************** HEALING ONESELF ANIMATION ***********************/
void healingAnima() //Animation for healing oneself
{
    int looped = 2;

    while(looped > 0) //Healing animation
    {
        system("COLOR 27"); //Make screen Green
        Sleep(50);
        system("COLOR A7"); //Make screen Light Green
        Sleep(50);
        system("COLOR 97"); //Make screen Aqua
        Sleep(50);
        system("COLOR 37"); //Make Screen Light Blue
        Sleep(50);
        system("COLOR 17"); //Make Screen Blue
        Sleep(50);
        system("COLOR 07"); //Make screen Black
        Sleep(20);
        looped--;
    }
}
/***************** HEALING ONESELF ANIMATION ***********************/

/*********************** SPOOKY MESSAGE ****************************/
void spookyMessage()
{
    //Display "This is life or Death" really slowly
    system("CLS");
    cout << "\n \n \n \n \n \n \n";
    cout << "\t \t \t \t \t \t";
    cout << "T";
    Sleep(300);
    cout << "h";
    Sleep(300);
    cout << "i";
    Sleep(300);
    cout << "s";
    Sleep(300);
    cout << " ";
    cout << "i";
    Sleep(300);
    cout << "s";
    Sleep(300);
    cout << " ";
    cout << "l";
    Sleep(300);
    cout << "i";
    Sleep(300);
    cout << "f";
    Sleep(300);
    cout << "e";
    Sleep(300);
    cout << " ";
    cout << "o";
    Sleep(300);
    cout << "r";
    Sleep(300);
    cout << " ";
    cout << "d";
    Sleep(300);
    cout << "e";
    Sleep(300);
    cout << "a";
    Sleep(300);
    cout << "t";
    Sleep(300);
    cout << "h";
    Sleep(300);
    cout << ".";
    cin.get();
    cout << "\n";
    cout << "\t \t \t \t \t \t R: RUN AWAY" <<endl;
    system("CLS");
    removeRun(); //Remove ability to run away
}

/*************************** REMOVE ABILITY TO RUN AWAY *************************************/
void removeRun()
{
    char run[50]; //Create Variable that would hold the array "R: RUN AWAY"
    run[0] = 'R';
    run[1] = ':';
    run[2] = ' ';
    run[3] = 'R';
    run[4] = 'U';
    run[5] = 'N';
    run[6] = ' ';
    run[7] = 'A';
    run[8] = 'W';
    run[9] = 'A';
    run[10]= 'Y';
    run[11]= '\0';


    for(int i = 10; i >= 0; i--) //Delete "R: RUN AWAY" option slowly
    {
        cout << "\n \n \n \n \n \n \n";
        cout << "\t \t \t \t \t \tThis is life or death." <<endl;
        cout << "\n";
        cout << "\t \t \t \t \t \t " << run <<endl;
        Sleep(300);
        run[i] = '\0';
        system("CLS");
    }
    cout << "\n \n \n \n \n \n \n";
    cout << "\t \t \t \t \t \tThis is life or death." <<endl;
    cin.get();
    runAway = 'n'; //Remove Run away visually
}
/****************************** REMOVE ABILITY TO RUN AWAY *****************************/

void displayRun()
{
    if(runAway == 'y') //If able to run away, display run away option
    {
        cout << "\t R: RUN AWAY  ";
    }

    else if(runAway == 'n')//If player has tried to run away in the middle of the Hitler Battle, display nothing
    {
        cout << "\t              ";
    }
}
