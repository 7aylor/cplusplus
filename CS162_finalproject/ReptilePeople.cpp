/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * ReptilePeople class.
***********************************************************/
#include <iostream>
#include <fstream>
#include "ReptilePeople.h"

//constructs a Barbarian with the proper values as outlined in the assignment
ReptilePeople::ReptilePeople()
{
    this->armor = 7;
    this->strength = 18;
    this->diceNumAtt = 3;
    this->diceFacesAtt = 6;
    this->diceNumDef = 1;
    this->diceFacesDef = 6;
    this->creatureName = "Reptile Man";
    this->startNum = 0;
}

//destructor
ReptilePeople::~ReptilePeople()
{
    //dtor
}

//special move prints what it will do
void ReptilePeople::specialMove(std::ofstream &battleLog)
{
    std::cout << this->creatureName << " has gone into a Cold Blooded Rampage\n";

    battleLog << this->creatureName << " has gone into a Cold Blooded Rampage\n";

}

