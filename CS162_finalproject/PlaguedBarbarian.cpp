/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * PlaguedBarbarian class.
***********************************************************/
#include <iostream>             //for cout
#include <cstdlib>              //for srand rand
#include <time.h>               //for time
#include "PlaguedBarbarian.h"   //includes header file

//constructor that assigns the PlaguedBarbarian its proper values
PlaguedBarbarian::PlaguedBarbarian()
{
    //seeds a randomized seed
    srand(time(NULL));
    this->armor = 0;
    this->strength = 12;
    this->diceNumAtt = 2;
    this->diceFacesAtt = 6;
    this->diceNumDef = 0;
    this->diceFacesDef = 0;
    this->creatureName = "Plagued Barbarian";
    this->startNum = 0;
}

//destructor
PlaguedBarbarian::~PlaguedBarbarian()
{
    //dtor
}

//overridden attack functoin
int PlaguedBarbarian::attack()
{
    int att = 0;

    //loops through the number of rolls and adds the roll to the total
    //to determine the attack
    for(int i = 0; i < diceNumAtt; i++)
    {
       int round = ((rand() % diceFacesAtt) + 1);
       att += round;
    }

    //adds two poison damage
    std::cout << this->creatureName << " Base attack + " << att;
    att += 2;
    std::cout << ". Poison damage + 2.\n";
    return att;			//returns the number they rolled
}

//redefined defend function
int PlaguedBarbarian::defend()
{
    //defense is 0
    return 0;
}
