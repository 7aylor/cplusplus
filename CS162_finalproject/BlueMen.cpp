/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * BlueMen class.
***********************************************************/
#include <iostream>
#include <fstream>
#include "BlueMen.h"

//constructs a Barbarian with the proper values as outlined in the assignment
BlueMen::BlueMen()
{
    this->armor = 3;
    this->strength = 12;
    this->diceNumAtt = 2;
    this->diceFacesAtt= 10;
    this->diceNumDef = 3;
    this->diceFacesDef = 6;
    this->creatureName = "Blue Man";
    this->startNum = 0;
}

//destructor
BlueMen::~BlueMen()
{
    //dtor
}

//special move prints what it will do
void BlueMen::specialMove(std::ofstream &battleLog)
{
    std::cout << this->creatureName << " has broken the opponent's weapon!\n";

    battleLog << this->creatureName << " has broken the opponent's weapon!\n";
}

