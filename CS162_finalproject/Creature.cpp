/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Creature class, the base class
***********************************************************/
#include "Creature.h"   //includes the header file of the Creature class
#include <iostream>     //for cout, and endl
#include <cstdlib>      //for rand and srand
#include <time.h>       //for using time

//default constructor
Creature::Creature()
{
    this->armor = armor;
    this->strength = strength;
    this->diceNumAtt = diceNumAtt;
    this->diceFacesAtt = diceFacesAtt;
    this->diceNumDef = diceNumDef;
    this->diceFacesDef = diceFacesDef;
    this->creatureName = creatureName;
    this->startNum = 0;
    this->team = "No Team";
    this->wins = 0;
    this->battles = 0;
}

//destructor
Creature::~Creature()
{
    //dtor
}

//gets the armor of the creature
int Creature::getArmor() const
{
    return this->armor;
}

//gets the strength of the creature
int Creature::getStrength() const
{
    return this->strength;
}

//gets the number of attack dice of the creature
int Creature::getDiceNumAtt() const
{
    return this->diceNumAtt;
}

//gets the number of faces of the attack dice
int Creature::getDiceFacesAtt() const
{
    return this->diceFacesAtt;
}

//gets the number of defense dice of the creature
int Creature::getDiceNumDef() const
{
    return this->diceNumDef;
}

//gets the number of faces of the defense dice
int Creature::getDiceFacesDef() const
{
    return this->diceFacesDef;
}

//gets the name of the creature
std::string Creature::getCreatureName() const
{
    return this->creatureName;
}

//gets the start number of the creature
int Creature::getStartNum() const
{
    return this->startNum;
}

//gets the name of the Team the Creature is on
std::string Creature::getTeam() const
{
    return this->team;
}

//gets the number of wins of the Creature
int Creature::getWins() const
{
    return this->wins;
}

//gets the number of battles of the Creature
int Creature::getBattles() const
{
    return this->battles;
}

//sets the strength of the creature
void Creature::setStrength(int thisStrength)
{
    this->strength = thisStrength;
}

//sets the name of the creature
void Creature::setCreatureName(std::string name)
{
    this->creatureName = name;
}

//uses a psuedo random number to determine the start number
void Creature::setStartNum()
{
    srand(time(NULL));
    int startNumber = rand() % 100;
    this->startNum = startNumber;
}

//sets the name of the Team of the Creature
void Creature::setTeam(std::string theTeam)
{
    this->team = theTeam;
}

//sets the number of Wins of the Creature
void Creature::setWins(int numWins)
{
    this->wins = numWins;
}

//sets the number of battles of the Creature
void Creature::setBattles(int numBattles)
{
    this->battles = numBattles;
}

//determines the attack of the creature
int Creature::attack()
{
    int att = 0;

    //loops through the number of rolls and adds the roll to the total
    //to determine the attack
    for(int i = 0; i < diceNumAtt; i++)
    {
       int round = ((rand() % diceFacesAtt) + 1);
       att += round;
    }
    return att;			//returns the number they rolled
}

//determines the attack of the creature
int Creature::defend()
{
    int def = 0;

    //loops through the number of rolls and adds the roll to the total
    //to determine the defense
    for(int i = 0; i < diceNumDef; i++)
    {
        int round = ((rand() % diceFacesDef) + 1);
        def += round;
    }
    return def;			//returns the number they rolled
}
