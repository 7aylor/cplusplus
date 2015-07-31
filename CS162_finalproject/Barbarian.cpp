/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Barbarian class.
***********************************************************/
#include <iostream>
#include <fstream>
#include "Barbarian.h"  //includes the Barbarian header file

//constructs a Barbarian with the proper values as outlined in the assignment
Barbarian::Barbarian()
{
    this->armor = 0;
    this->strength = 12;
    this->diceNumAtt = 2;
    this->diceFacesAtt = 6;
    this->diceNumDef = 2;
    this->diceFacesDef = 6;
    this->creatureName = "Barbarian";
    this->startNum = 0;
}

//destructor
Barbarian::~Barbarian()
{
    //dtor
}

//special move prints what it will do
void Barbarian::specialMove(std::ofstream &battleLog)
{
    std::cout << this->creatureName << " has gone into a bersek rage and "
                << "absorbs the damage.\n";

    battleLog << this->creatureName << " has gone into a bersek rage and "
                << "absorbs the damage.\n";
}

