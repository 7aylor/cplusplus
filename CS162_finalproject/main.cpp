/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 6/8/2014
 *
 * Description: This program allows two users to create teams
 * of Creatures that fight against each other. The loser of the
 * current fight is killed and put in a dead stack; the winner
 * of the current fight is placed at the end of the queue. When
 * the winner gets placed at the end of the stack, they heal 3
 * health points. Once one of the teams runs out of Creatures
 * to fight with, they have lost the tournament since it is
 * survival of the fittest. The creatures who are the last to
 * die place in first second or third. I have decided that if a
 * team has more than one creature alive and they have the same
 * amount of wins, they will tie.
 *
 * Input: The user inputs an integer to determine which
 * creature they have chosen. They also enter in an integer for
 * the weapons they choose for each CreatureThey will also press
 * enter to continue after each attack. They will enter an integer
 * to determine if they want to fight again.
 *
 * Output: The program outputs the outcome of each attack
 * and battle both to the screen of the console and to a
 * text file that holds the battle logs. It also outputs which
 * Creatures placed in the top three spots and which team has
 * won the tournament.
***********************************************************/
#include <iostream>           //for cout, endl, cin
#include <cstdlib>            //for rand and srand
#include <time.h>             //for time
#include "Creature.h"         //imports Creature header
#include "Barbarian.h"        //imports Barbarian header
#include "PlaguedBarbarian.h" //imports PlaguedBarbarina header
#include "BlueMen.h"          //imports BlueMen header
#include "PlaguedBlueMen.h"   //imports PlaguedBlueMen
#include "Goblin.h"           //imports Goblin header
#include "PlaguedGoblin.h"    //imports PlaguedGoblin header
#include "ReptilePeople.h"    //imports ReptilePeople header
#include "PlaguedReptile.h"   //imports PlaguedReptile header
#include "Weapon.h"           //imports Weapon header
#include "BowAndArrow.h"      //imports BowAndArrow header
#include "Shield.h"           //imports Shield header
#include "Sword.h"            //imports Sword header
#include <string>             //for using strings
#include <fstream>            //to output to a file
#include <stack>              //to use stacks
#include <queue>              //to use queues
#include <sstream>            //to convert an int to string

//allow the user to pick their creature by inputting a number that
//determines which creature they would like to pick
void pickCreature(int &firstChoice, int number);

//checks to ensure the user has entered valid numbers and prints an
//error if they enter bad data
void checkChoice(int &choice, int upperBound, int lowerBound,
                std::string message);

//creatures the creature the user chose
Creature* createCreature(int &choice, int &creatureNum, int team);

//creates plagued creatures based off of a random number. There is a 20% chance
//a creature will become plagued.
void plaguedCreature(int &choice, Creature* &creature, std::string num,
                     int team);

//determines the start number of the creature so that both creatures
//have a change to attack first
int determineStart(Creature* &creature1, Creature* &creature2);

//determines which weapons each creature will use
Weapon* chooseWeapon(int &weapon, Creature* &creature);

//manages the flow of battle based on which creature gets to attack first
void combatRound(int &starter, Creature* &creature1, Creature* &creature2,
                 Weapon* &weapon1, Weapon* &weapon2, std::ofstream &battleLog);

//calculates the damage done to the creature after the attack has happened
void calculateDamage(int attack, int defense, Creature* &creature1,
                     Creature* &creature2, Weapon* &weapon1, Weapon* &weapon2,
                     std::ofstream &battleLog);

//determines if the offense specials for the Creature will be used.
//The specials are called based off of a random number
void enactOffenseSpecial(Creature* &creature1, Creature* &creature2,
                         Weapon* &enemyWeapon, int &attack, int &defense,
                         std::ofstream &battleLog);

//determines if the defense specials for the Creature will be used.
//The specials are called based off of a random number
void enactDefenseSpecial(Creature* &creature1, Creature* &creature2,
                         int &attack, int &defense, Weapon* &weapon,
                         std::ofstream &battleLog);

//determines if the user wants to run another battle
bool runAgain();

//pauses the screen and waits for the user to hit enter
void cont();

//fills the queue with Creatures
void fillQueue(std::queue<Creature*> &thisQueue, int queueSize, int whichTeam);

//fills the stack with Creatures
void fillStack(std::stack<Creature*> &theStack,
               std::queue<Creature*> &thisQueue);

//puts the winning creature at the end of the queue
void putBack(std::queue<Creature*> &thisQueue);

//prints he queue
void printQueue(std::queue<Creature*> &thisQueue, int queueSize,
                std::string team, std::ofstream &battleLog);

//prints the types of creatures and their stats
void printStats();

//determines which team wins
void determineWinner(std::queue<Creature*> &firstQueue,
                     std::queue<Creature*> &secondQueue,
                     std::ofstream &battleLog);

//prints the places of the Creatures in the stack
void printStack(std::stack<Creature*> &theStack, std::ofstream &battleLog);

//sets the team name of the Creature
void assignTeam(Creature* &thisCreature, int whichTeam);

//adds 1 to the number of battles they fought in after the fight
void addBattles(Creature* &teamOneCreature, Creature* &teamTwoCreature);

//adds 1 to the number of wins they have after they fight and win
void addWins(Creature* &winner, std::ofstream &battleLog);

//heals the creature by 3 after they have fought and won
void heal(Creature* current, std::ofstream &battleLog);

//deletes the Queues and Stacks
void freeMemory(std::queue<Creature*> &firstQueue,
                     std::queue<Creature*> &secondQueue,
                     std::stack<Creature*> &theStack);

int main()
{
    srand(time(NULL));          //generates a random seed
    int creatureNum;            //number of creatures on teams
    int weaponChoice1;          //used to choose first weapon
    int weaponChoice2;          //used to choose second weapon
    int round = 1;              //keeps track of number of rounds
    bool keepRunning = true;    //determines if the user wants to fight again

    //for outputting to a text file
    std::ofstream battleLog("battlelog.txt");

    std::cout << "This is Creature Fighter!" << std::endl;
    std::cout << std::endl;

    battleLog << "This is Creature Fighter!" << std::endl;


    //keep fighting if keepRunning is true
    while(keepRunning == true)
    {
        //get the number of creatures the teams will have
        std::cout << "Choose at least 3 and up to 12 Creatures to Fight. " <<
                        "How many creatures will be on each team? ";
        std::cin >> creatureNum;

        //check the if the number of creatures is in bounds
        checkChoice(creatureNum, 12, 3,
                    "Please enter an integer from 3 to 12: ");

        //creates the queue for team 1
        std::queue <Creature*> team1;

        //creatres the queue for team 2
        std::queue <Creature*> team2;

        //creates the stack for dead Creatures
        std::stack <Creature*> deadCreatures;

        //the first team chooses their creatures and their queue is filled,
        // then printed
        std::cout << "\nTeam 1, choose your Creatures:\n\n";
        printStats();
        fillQueue(team1, creatureNum, 1);
        printQueue(team1, creatureNum, "Team 1 Creatures:\n", battleLog);
        std::cin.ignore();
        cont();

        //the second team chooses their creatures and their queue is filled,
        // then printed
        std::cout << "\nTeam 2, choose your Creatures:\n\n";
        printStats();
        fillQueue(team2, creatureNum, 2);
        printQueue(team2, creatureNum, "Team 2 Creatures:\n", battleLog);
        std::cin.ignore();
        cont();

        //get the first creature in each queue
        Creature* teamOneCreature = team1.front();
        Creature* teamTwoCreature = team2.front();

        //while both team's queue are not empty
        while(team1.size() != 0 && team2.size() != 0)
        {
            //gets the Creatures that are in the front of each queue
            teamOneCreature = team1.front();
            teamTwoCreature = team2.front();

            //prints the battle number for the current round.
            battleLog << "\n\nBattle " << round << ":\n\n";

            //print who will fight
            std::cout << "The " << teamOneCreature->getCreatureName()
                    << " from Team 1 and the " <<
                    teamTwoCreature->getCreatureName()
                    << " from Team 2 will fight to the death!\n" << std::endl;

            //print who won the fight to the battle log
            battleLog << "The " << teamOneCreature->getCreatureName()
                    << " from Team 1 and the " <<
                    teamTwoCreature->getCreatureName()
                    << " from Team 2 will fight to the death!\n" << std::endl;

            //team 1 chooses the weapon for the current creature
            std::cout << "Team 1, ";
            Weapon* weapon1 = chooseWeapon(weaponChoice1, teamOneCreature);

            //team 2 chooses the weapon for the current creature
            std::cout << "Team 2, ";
            Weapon* weapon2 = chooseWeapon(weaponChoice2, teamTwoCreature);

            //gets another seed
            srand(time(NULL));

            //determine which creature gets to attack first
            int starter = determineStart(teamOneCreature, teamTwoCreature);

            //get the strengths of the creatures to use in the while loop
            int c1strength = teamOneCreature->getStrength();
            int c2strength = teamTwoCreature->getStrength();

            //pause the screen
            cont();

            //clears the stream so the user can hit enter once to continue
            std::cin.ignore();

            //keep fighting until one of the creatures strength is 0
            while(c1strength > 0 && c2strength > 0)
            {
                //fight!
                combatRound(starter, teamOneCreature, teamTwoCreature,
                            weapon1, weapon2, battleLog);

                //get the creatures current strength
                c1strength = teamOneCreature->getStrength();
                c2strength = teamTwoCreature->getStrength();

                //if the strength is greater that 0 for both creatures,
                //pause the screen
                if(c1strength > 0 && c2strength > 0)
                {
                    cont();
                }
            }

            //add the number of battles fought to the creatures
            addBattles(teamOneCreature, teamTwoCreature);

            //if team1 Creature is dead
            if(teamOneCreature->getStrength() <= 0)
            {
                //add the dead creature to the stack
                fillStack(deadCreatures, team1);

                //print who wins
                std::cout << std::endl << teamTwoCreature->getCreatureName()
                            << " won this round!\n";

                battleLog << teamTwoCreature->getCreatureName()
                            << " won this round!";

                //add a win for the winning Creature
                addWins(teamTwoCreature, battleLog);

                //put the winnger at the end of the queue
                putBack(team2);

                //heals the winner
                heal(teamTwoCreature, battleLog);

                //print the remaining Creatures of both teams
                printQueue(team1, team1.size(),
                           "\nRemaining Creatures in Team 1:", battleLog);
                printQueue(team2, team2.size(),
                           "\nRemaining Creatures in Team 2:", battleLog);
                cont();
            }
            //otherwise, Team2 Creature has died
            else
            {
                //add it to the stack
                fillStack(deadCreatures, team2);

                //print the winner
                std::cout << std::endl << teamOneCreature->getCreatureName()
                            << " won this round!\n";

                battleLog << teamOneCreature->getCreatureName()
                            << " won this round!\n";

                //add a win for the winning Creature
                addWins(teamOneCreature, battleLog);

                //put the winner at the end of the queue
                putBack(team1);

                //heals the winner
                heal(teamOneCreature, battleLog);

                //print remaining Creatures for both teams
                printQueue(team1, team1.size(),
                           "Remaining Creatures in Team 1", battleLog);
                printQueue(team2, team2.size(),
                           "Remaining Creatures in Team 2", battleLog);

                cont();
            }

            //increases for the next round
            round++;
        }//end of the current round

        //print which team wins
        determineWinner(team1, team2, battleLog);

        //if there are alive creatures after the fight from team 1, put them
        //in the stack in order
        while(team1.size() > 0)
        {
            fillStack(deadCreatures, team1);
        }
        //if there are alive creatures after the fight from team 2, put them
        //in the stack in order
        while(team2.size() > 0)
        {
            fillStack(deadCreatures, team2);
        }
        //prints the places of the creatures
        printStack(deadCreatures, battleLog);

        freeMemory(team1, team2, deadCreatures);

        //determine if the user wants to fight some more
        keepRunning = runAgain();
    }
    //close the log
    battleLog.close();

    //end the program
    return 0;
}

void pickCreature(int &firstChoice, int number)
{
    int upperBound = 4;         //highest number chosen
    int lowerBound = 1;         //lowest number chosen
    std::string badChoice = "Please enter a value between 1 and 4: ";

    std::cout << "Creature " << number << ": ";
    std::cin >> firstChoice;

    //check the choice to see if its valid
    checkChoice(firstChoice, upperBound, lowerBound, badChoice);

    switch (firstChoice)
    {
        case 1:
            std::cout << "You have chosen a Goblin.\n";
            break;
        case 2:
            std::cout << "You have chosen a Barbarian.\n";
            break;
        case 3:
            std::cout << "You have a chosen a Reptile Man.\n";
            break;
        case 4:
            std::cout << "You have chosen a Blue Man.\n";
            break;
    }
}

void checkChoice(int &choice, int upperBound, int lowerBound,
                 std::string message)
{
    //check the choice to make sure it is within bounds and if its not, make
    //the user try again
    while(std::cin.fail() || choice > upperBound || choice < lowerBound)
    {
        std::cin.clear();
        std::cin.ignore(999, '\n');
        std::cout << message;
        std::cin >> choice;
    }
}

Creature* createCreature(int &choice, std::string num, int team)
{
    Creature* creature;
    //if user picks a Goblin, create a Goblin object
    //return the object

    if(choice == 1)
    {
        creature = new Goblin;
        assignTeam(creature, team);
        std::string newName = creature->getTeam();
        newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
        creature->setCreatureName(newName);
        return creature;
    }
    //if user picks a Barbarian, create a Barbarian object
    //return the object
    else if(choice == 2)
    {
        creature = new Barbarian;
        assignTeam(creature, team);
        std::string newName = creature->getTeam();
        newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
        creature->setCreatureName(newName);
        return creature;
    }
    //if user picks ReptilePeople, create a ReptilePeople object
    //return the object
    else if(choice == 3)
    {
        creature = new ReptilePeople;
        assignTeam(creature, team);
        std::string newName = creature->getTeam();
        newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
        creature->setCreatureName(newName);
        return creature;
    }
    //if user picks BlueMen, create a BlueMen object
    //return the object
    else
    {
        creature = new BlueMen;
        assignTeam(creature, team);
        std::string newName = creature->getTeam();
        newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
        creature->setCreatureName(newName);
        return creature;
    }
}

void plaguedCreature(int &choice, Creature* &creature, std::string num,
                     int team)
{
    //gets the name of the creature
    std::string name = creature->getCreatureName();

    //generates a random number and if the number is less than 2,
    //create a new PlaguedCreature depending on what the Parent
    //Creature is.
    if((rand() % 10) < 2)
    {
        //if its a Barbarian, created a PlaguedBarbarian
        if(choice == 2)
        {
            creature = new PlaguedBarbarian;
            assignTeam(creature, team);
            std::string newName = creature->getTeam();
            newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
            creature->setCreatureName(newName);

            std::cout <<"The Barbarian has become infected with the Plague!\n";
            //ensures the name doesn't get changed in double pick
            choice = 6;
        }
        //if its a Goblin, created a PlaguedGoblin
        else if(choice == 1)
        {
            creature = new PlaguedGoblin;
            assignTeam(creature, team);
            std::string newName = creature->getTeam();
            newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
            creature->setCreatureName(newName);

            std::cout << "The Goblin has become infected with the Plague!\n";
            //ensures the name doesn't get changed in double pick
            choice = 6;
        }
        //if its a BlueMan, created a PlaguedBlueMan
        else if(choice == 3)
        {
            creature = new PlaguedBlueMen;
            assignTeam(creature, team);
            std::string newName = creature->getTeam();
            newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
            creature->setCreatureName(newName);

            std::cout << "The Blue Man has become infected with the Plague!\n";
            //ensures the name doesn't get changed in double pick
            choice = 7;
        }
        //if its a ReptileMan, created a PlaguedReptile
        else if(choice == 4)
        {
            creature = new PlaguedReptile;
            assignTeam(creature, team);
            std::string newName = creature->getTeam();
            newName = newName + ", " + "Creature " + num + ", "
                    + creature->getCreatureName();
            creature->setCreatureName(newName);

            std::cout <<
                "The Reptile Man has become infected with the Plague!\n";
            //ensures the name doesn't get changed in double pick
            choice = 8;
        }
    }
}

int determineStart(Creature* &creature1, Creature* &creature2)
{
    creature1->setStartNum();             //sets the start number for creature1
    int start1 = creature1->getStartNum();//assigns the number to start1
    int start2 = 50;                     //creates a constant start number

    //if start1 is bigger, creature 1 gets to go first
    if(start1 > start2)
    {
        std::cout << "The " << creature1->getCreatureName() <<
                    " gets to attack first.\n" << std::endl;
        return 1;
    }
    //if start2 is bigger, creature 2 gets to go first
    else if(start1 < start2)
    {
        std::cout << "The " << creature2->getCreatureName() <<
                    " gets to attack first.\n" << std::endl;
        return 2;
    }
    //otherwise the start values are the same and return 0
    else
    {
        return 0;
    }
}

Weapon* chooseWeapon(int &weapon, Creature* &creature)
{
    std::cout << "Choose a weapon for the " << creature->getCreatureName()
                << ": \n\n";
    std::cout << "1) Bow and Arrow - Attack +6\n";
    std::cout << "2) Shield \t - Defense +6\n";
    std::cout << "3) Sword \t - Attack +3, Defense +3\n\n";
    std::cout << "Select the weapon by entering the corresponding number: ";
    std::cin >> weapon;

    //checks the user's input
    checkChoice(weapon, 3, 1, "Please enter a number between 1 and 3: ");

    //points to the weapon they chose
    Weapon* weaponChoice;

    //if they chose a Bow and Arrow, create one and assign it to weaponChoice
    if(weapon == 1)
    {
        weaponChoice = new BowAndArrow;
        std::cout << "The " << creature->getCreatureName() << " will  "
                   "now wield a " << weaponChoice->getWeaponName() << "!\n\n";
        return weaponChoice;
    }
    //if they chose a Shield, create one and assign it to weaponChoice
    else if(weapon == 2)
    {
        weaponChoice = new Shield;
        std::cout << "The " << creature->getCreatureName() << " will  "
                   "now wield a " << weaponChoice->getWeaponName() << "!\n\n";
        return weaponChoice;
    }
    //if they chose a Sword, create one and assign it to weaponChoice
    else
    {
        weaponChoice = new Sword;
        std::cout << "The " << creature->getCreatureName() << " will  "
                   "now wield a " << weaponChoice->getWeaponName() << "!\n\n";
        return weaponChoice;
    }
}

void combatRound(int &starter, Creature* &creature1, Creature* &creature2,
                 Weapon* &weapon1, Weapon* &weapon2, std::ofstream &battleLog)
{
    //check if starter is even and not 0, if it is, the first creature
    //attacks
    if(starter > 0 && starter % 2 == 1)
    {
        int firstAttack = creature1->attack();
        int firstDefense = creature2->defend();

        //determines if an offensive special will be enacted
        enactOffenseSpecial(creature1, creature2, weapon2, firstAttack,
                            firstDefense, battleLog);

        //calculate how much damange is done
        calculateDamage(firstAttack, firstDefense, creature1, creature2,
                        weapon1, weapon2, battleLog);

        starter++;      //inrease starter so the other creature gets to attack.
        std::cout << std::endl;
    }
    //check if starter is even and not 0, if its not, the second creature
    //attacks
    else if(starter > 0 && starter % 2 == 0)
    {
        int firstAttack = creature2->attack();
        int firstDefense = creature1->defend();

        //determines if an offensive special will be enacted
        enactOffenseSpecial(creature2, creature1, weapon1, firstAttack,
                            firstDefense, battleLog);

        //calculate how much damange is done
        calculateDamage(firstAttack, firstDefense, creature2, creature1,
                        weapon2, weapon1, battleLog);

        starter++;      //inrease starter so the other creature gets to attack.

        std::cout << std::endl;
    }
    //if the value of starter is 0, the start values are the same and a new
    //start value will be created.
    else
    {
        std::cout << "Start values are equal. Recalculating start values."
                    << std::endl;
        starter = determineStart(creature1, creature2);
    }
}

void calculateDamage(int attack, int defense, Creature* &creature1,
                     Creature* &creature2, Weapon* &weapon1, Weapon* &weapon2,
                     std::ofstream &battleLog)
{

    //print the attack and damage that the creatures rolled to the console and
    //text document
    std::cout << creature1->getCreatureName() << " attacks for " << attack <<
                " damage." << std::endl;

    battleLog << creature1->getCreatureName() << " attacks for " << attack <<
                " damage." << std::endl;

    //if the Creature has a Sword or BowAndArrow, print the added attack to
    //the screen and the battleLog
    if(weapon1->getWeaponName() != "Shield" &&
       weapon1->getWeaponName() != "Broken Shield")
    {
        attack += weapon1->getAttack();
        std::cout << creature1->getCreatureName() << "'s " <<
                weapon1->getWeaponName() << " adds " << weapon1->getAttack()
                << " damage for a total damage of " << attack << std::endl;
        battleLog << creature1->getCreatureName() << "'s " <<
                weapon1->getWeaponName() << " adds " << weapon1->getAttack()
                << " damage for a total damage of " << attack << std::endl;
    }

    //check if the defense Special will be applied
    enactDefenseSpecial(creature1, creature2, attack, defense, weapon2,
                        battleLog);

    //if attack is greater than defense
    if(attack > defense)
    {
        int dead = 0;

        //set the damage
        int dmg = attack - defense;

        //get the strength of the creature
        int creatureStrength = creature2->getStrength();

        //get the total strength left after the damange is done
        int total = creatureStrength - dmg;

        //if the creature's strength is larger than the damage
        //set the new strength after taking the damage and print
        //it to the console and to the battlelog
        if(creatureStrength > dmg)
        {
            creature2->setStrength(total);
            std::cout << creature2->getCreatureName() << " takes " << dmg <<
                    " damange total." << std::endl;
            battleLog << creature2->getCreatureName() << " takes " << dmg <<
                    " damange total." << std::endl;


            std::cout << creature2->getCreatureName() << " has " <<
                    creature2->getStrength() << " strength " <<
                    "after the attack." << std::endl;
            battleLog << creature2->getCreatureName() << " has " <<
                    creature2->getStrength() << " strength " <<
                    "after the attack." << std::endl;
            battleLog << "----------------------------------------------\n";
        }

        //otherwise, the creature has been killed. Print this to the console
        //and to the battlelog
        else
        {
            creature2->setStrength(dead);
            std::cout << "The " << creature2->getCreatureName() <<
                        " was killed." << std::endl;
            battleLog << "The " << creature2->getCreatureName() <<
                        " was killed." << std::endl;
        }
    }

    //otherwise the attack is less than the defense and no damage is done
    else
    {
        //print that the creature took no damange to the console and to the
        //battlelog. Also print a dividing line to the battlelog
        std::cout << creature2->getCreatureName() << " takes no damage."
                    << std::endl;
        battleLog << creature2->getCreatureName() << " takes no damage."
                    << std::endl;
        battleLog << "----------------------------------------------\n";
    }
}

void enactOffenseSpecial(Creature* &creature1, Creature* &creature2,
                         Weapon* &enemyWeapon,int &attack, int &defense,
                         std::ofstream &battleLog)
{
    //generate a number between 0 and 9
    int enact = rand() % 10;

    //get the name of the creature
    std::string name = creature1->getCreatureName();

    //get the name of the weapon
    std::string weaponTitle = enemyWeapon->getWeaponName();

    std::string brokenWeapon = "Broken " + weaponTitle;

    //if the number is 0 or 1, and its a Goblin, call the
    //Goblin's special move.
    if (enact < 2 && (name == "Goblin" ||
                      name == "Goblin 1" || name == "Goblin 2"))
    {
        creature1->specialMove(battleLog);
    }

    //if the number is 0, and its a Reptile Man, call the
    //Reptile Man's special move, and give it 100 attack.
    else if (enact < 1 && (name == "Reptile Man" ||
                           name == "Reptile Man 1" || name == "Reptile Man 2"))
    {
        creature1->specialMove(battleLog);
        attack = 100;
    }

    //if the number is 0, and its a Blue Man, call the
    //Blue Man's special move, destroy the enemy's weapon.
    //Also sets the bame of the enemy's weapon to broken.
    else if(enact < 1 && (name == "Blue Man" || name == "Blue Man 1"
            || name == "Blue Man 2") && (weaponTitle != "Broken Sword")
            && (weaponTitle != "Broken Shield") && (weaponTitle !=
            "Broken Bow and Arrow"))
    {
        creature1->specialMove(battleLog);
        enemyWeapon->setAttack(0);
        enemyWeapon->setDefense(0);
        enemyWeapon->setWeaponName(brokenWeapon);
    }
}

void enactDefenseSpecial(Creature* &creature1, Creature* &creature2,
                         int &attack, int &defense, Weapon* &weapon,
                         std::ofstream &battleLog)
{
    int enact = rand() % 10;

    //get the name of the defending Creature
    std::string name = creature2->getCreatureName();

    //if the number is 0 and the Creature is a Barbarian,
    //call the Barbarian's special move and made the enemy's attack 0.
    if(enact < 1 && (name == "Barbarian" ||
                      name == "Barbarian 1" || name == "Barbarian 2"))
    {
        creature2->specialMove(battleLog);
        attack = 0;
    }

    //otherwise, carry out the defense as normal.
    else
    {
        //print the defense to the console and text document
        std::cout << creature2->getCreatureName() << " blocks " << defense <<
                    " damage." << std::endl;
        battleLog << creature2->getCreatureName() << " blocks " << defense <<
                    " damage." << std::endl;

        //if they have a shield, broken shield, sword, or broken sword,
        //print the defense to the screen and the battlelog.
        if(weapon->getWeaponName() != "Bow and Arrow" &&
           weapon->getWeaponName() != "Broken Bow and Arrow")
        {
            defense += weapon->getDefense();
            std::cout << creature2->getCreatureName() << "'s " <<
                    weapon->getWeaponName() << " adds " <<
                    weapon->getDefense() << " defense for a total defense of "
                    << defense << std::endl;
            battleLog << creature2->getCreatureName() << "'s " <<
                    weapon->getWeaponName() << " adds " <<
                    weapon->getDefense() << " defense for a total defense of "
                    << defense << std::endl;
        }
    }
}
bool runAgain()
{
        int runAgain;   //used to run the program again

        //get the choice from the user
        std::cout << "Continue? 1 for yes, 2 for no: ";
        std::cin >> runAgain;

        //check their input
        checkChoice(runAgain, 2, 1, "Please enter 1 for yes or 2 for no: ");

        //if they chose 1, continue and return true
        if(runAgain == 1)
        {
            return true;
        }

        //otherwise, return false to quit
        else
        {
            return false;
        }
}

void cont()
{
    //waits for the user to hit enter to continue
    std::cout << "Hit enter to continue:" << std::endl;
    std::cin.ignore(1);
}

void fillQueue(std::queue<Creature*> &thisQueue, int queueSize, int whichTeam)
{
    //holds the position of the queue we are in
    int position = 0;

    //holds the choice of the creature the user wants to create
    int choice;

    //holds the string stream to convert from int to string
    std::stringstream ss;

    //will be used to hold the converted int to string
    std::string num;

    while(position < queueSize)
    {
        //increases the position each iteration
        position++;

        //converts the int to a string to add to the name
        ss.str("");
        ss.clear();
        ss << position;
        ss >> num;

        //picks the creature by letting the user decice
        pickCreature(choice, position);

        //creates the Creature based on their choice
        Creature* chosenOne = createCreature(choice, num, whichTeam);

        //determines if the newly created Creature is Plagued
        plaguedCreature(choice, chosenOne, num, whichTeam);

        //adds the Creature to the bottom of the queue
        thisQueue.push(chosenOne);
    }
}

void fillStack(std::stack<Creature*> &theStack,
               std::queue<Creature*> &thisQueue)
{
    //gets the Creature at the front of the queue
    Creature* dead = thisQueue.front();

    //removes the creature off of the queue
    thisQueue.pop();

    //adds it to the stack
    theStack.push(dead);
}

void putBack(std::queue<Creature*> &thisQueue)
{
    //gets the creature from the front of the queue
    Creature* winner = thisQueue.front();

    //removes the creature off of the queue
    thisQueue.pop();

    //adds it to the end of the queue
    thisQueue.push(winner);
}

void printQueue(std::queue<Creature*> &thisQueue, int queueSize,
                std::string team, std::ofstream &battleLog)
{
    //holds the position in the queue we are in
    int position = 0;
    std::cout << team;
    battleLog << std::endl << team;

    //creatres a temporary queue to print with
    std::queue<Creature*> temp = thisQueue;

    //while the position is less than the size of the queue
    while(position < queueSize)
    {
        //increase the position
        position++;

        //get the front of the queue
        Creature* x = temp.front();

        //print the print of the queue's name
        std::cout << "\n\t" << x->getCreatureName();
        battleLog << "\n\t" << x->getCreatureName();

        //remove it from the front of the quee
        temp.pop();
    }
    std::cout << std::endl << std::endl;
    battleLog << std::endl << std::endl;
}

void printStats()
{
    //print the choice of creatures
    std::cout << "1) Goblin \t";
    std::cout << " - Attack: 2-12 | Defense: 1-6 | Armor 3 "
                << "| Strength 8\n\n";
    std::cout << "2) Barbarian\t";
    std::cout << " - Attack: 2-12 | Defense: 2-12 | Armor 0 "
                << "| Strength 12\n\n";
    std::cout << "3) Reptile Man\t";
    std::cout << " - Attack: 3-18 | Defense: 1-6 | Armor 7 "
                << "| Strength 18\n\n";
    std::cout << "4) Blue Man\t";
    std::cout << " - Attack: 2-20 | Defense: 3-18 | Armor 3 "
                << "| Strength 12\n\n";

    //let the user choose the first creature to fight
    std::cout << "Select your fighter by entering the corresponding number."
            << std::endl << std::endl;
}

void determineWinner(std::queue<Creature*> &firstQueue,
                     std::queue<Creature*> &secondQueue,
                     std::ofstream &battleLog)
{
    //if the first team's queue is greater than 1, print they have won
    if(firstQueue.size() > 0)
    {
        std::cout << "Team 1 wins!\n";
        battleLog << "Team 1 wins!\n";
    }

    //Otherwise the second team's queue is greater than 1, print they have won
    else
    {
        std::cout << "Team 2 wins!\n";
        battleLog << "Team 2 wins!\n";
    }
}

void printStack(std::stack<Creature*> &theStack, std::ofstream &battleLog)
{
    //get the Creature off the top of the stack
    Creature* temp1 = theStack.top();
    //remove it from the top of the stack
    theStack.pop();

    //get the Creature off the top of the stack
    Creature* temp2 = theStack.top();

    //remove it from the top of the stack
    theStack.pop();

     //get the Creature off the top of the stack
    Creature* temp3 = theStack.top();

    //remove it from the top of the stack
    theStack.pop();

    //get the number of wins of each Creature
    int temp1Wins = temp1->getWins();
    int temp2Wins = temp2->getWins();
    int temp3Wins = temp3->getWins();

    //gets the team name of each Creature
    std::string temp1Team = temp1->getTeam();
    std::string temp2Team = temp2->getTeam();
    std::string temp3Team = temp3->getTeam();

    //if top 3 creatures have the same number of wins and they are all on
    //the same team, they all tie for first
    if((temp1Wins == temp2Wins && temp2Wins == temp3Wins) &&
       (temp1Team == temp2Team && temp2Team == temp3Team))
    {
        std::cout << temp1->getCreatureName() << ", " <<
                    temp2->getCreatureName() << ", and " <<
                    temp3->getCreatureName() << " have all tied for first "
                    << "place\n\n";

        battleLog << temp1->getCreatureName() << ", " <<
                    temp2->getCreatureName() << ", and " <<
                    temp3->getCreatureName() << " have all tied for first "
                    << "place\n\n";
    }

    //if the top 2 creatures have the same number of wins and are on the same
    //team, they tie for first and the next creature gets third
    else if(temp1Wins == temp2Wins && temp1Team == temp2Team)
    {
        std::cout << temp1->getCreatureName() << " and " <<
                    temp2->getCreatureName() << " have tied for first place. "
                    << temp3->getCreatureName() << " has placed third\n\n";

        battleLog << temp1->getCreatureName() << " and " <<
                    temp2->getCreatureName() << " have tied for first place. "
                    << temp3->getCreatureName() << " has placed third\n\n";

    }

    //if the top creature has the most wins, it gets first, if the next two
    //creatures have the same number of wins, they tie for third
    else if(temp2Wins == temp3Wins)
    {
        std::cout << temp1->getCreatureName() << " has placed first! "
                    << temp2->getCreatureName() << " and "
                    << temp3->getCreatureName() <<
                    " have tied for third place.\n\n";

        battleLog << temp1->getCreatureName() << " has placed first! "
                    << temp2->getCreatureName() << " and "
                    << temp3->getCreatureName() <<
                    " have tied for third place.\n\n";
    }
    //otherwise, they are in order and get first, second, and third
    else
    {
        std::cout << temp1->getCreatureName() << " from " << temp1->getTeam()
                << " came in first place!\n";

        battleLog << std::endl << std::endl;
        battleLog << temp1->getCreatureName() << " from " << temp1->getTeam()
                    << " came in first place!\n";

        std::cout << temp2->getCreatureName() << " from " << temp2->getTeam()
                    << " came in second place!\n";

        battleLog << temp2->getCreatureName() << " from " << temp2->getTeam()
                    << " came in second place!\n";


        std::cout << temp3->getCreatureName() << " from " << temp3->getTeam()
                    << " came in third place!\n\n";

        battleLog << temp3->getCreatureName() << " from " << temp3->getTeam()
                    << " came in third place!\n\n";
    }
}

void assignTeam(Creature* &thisCreature, int whichTeam)
{
    //if they are on team 1, set their Team name to Team 1
    if(whichTeam == 1)
    {
        thisCreature->setTeam("Team 1");
    }
    //otherwise they are on Team 2, set thier Team name to Team 2
    else
    {
        thisCreature->setTeam("Team 2");
    }
}

void addBattles(Creature* &teamOneCreature, Creature* &teamTwoCreature)
{
    //get the number of battles
    int numBattles1 = teamOneCreature->getBattles();
    int numBattles2 = teamTwoCreature->getBattles();

    //add one to their number of battles
    numBattles1++;
    numBattles2++;

    //set the number of battles to the updated number
    teamOneCreature->setBattles(numBattles1);
    teamTwoCreature->setBattles(numBattles2);
}

void addWins(Creature* &winner, std::ofstream &battleLog)
{
    //get the number of wins
    int numWins = winner->getWins();

    //add one win
    numWins++;

    std::cout << winner->getCreatureName() << " now has " <<
                numWins << " wins!\n";

    battleLog << winner->getCreatureName() << " now has " <<
                numWins << " wins!\n";

    //update the number of wins
    winner->setWins(numWins);
}

void heal(Creature* current, std::ofstream &battleLog)
{
    //get the current strength of the Creature
    int newHealth = current->getStrength();

    //add three to their health since they won the previous fight
    newHealth += 3;

    //set the updeated health
    current->setStrength(newHealth);

    //print that the creature has healed and give the new Health
    std::cout << current->getCreatureName() <<
            " heals 3 for winning the fight and now has a total \nstrength of "
            << current->getStrength() << std::endl;

    battleLog << current->getCreatureName() <<
            " heals 3 for winning the fight and now has a total \nstrength of "
            << current->getStrength() << std::endl;
}

void freeMemory(std::queue<Creature*> &firstQueue,
                     std::queue<Creature*> &secondQueue,
                     std::stack<Creature*> &theStack)
{
    //loops through the queue and deletes it
    while(!firstQueue.empty())
    {
        delete(firstQueue.front());
        firstQueue.pop();
    }

    //loops through the queue and deletes it
    while(!secondQueue.empty())
    {
        delete(firstQueue.front());
        secondQueue.pop();
    }

    //loops through the stack and deletes it
    while(!theStack.empty())
    {
        delete(firstQueue.front());
        theStack.pop();
    }
}
