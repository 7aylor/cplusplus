/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Goblin class.
***********************************************************/
#include <iostream>
#include <fstream>
#include "Goblin.h"

//constructs a Barbarian with the proper values as outlined in the assignment
Goblin::Goblin()
{
    this->armor = 3;
    this->strength = 8;
    this->diceNumAtt = 2;
    this->diceFacesAtt = 6;
    this->diceNumDef = 1;
    this->diceFacesDef = 6;
    this->creatureName = "Goblin";
    this->startNum = 0;
}

//destructor
Goblin::~Goblin()
{
    //dtor
}

//special move sets strength back to 8 and prints what it did
void Goblin::specialMove(std::ofstream &battleLog)
{
    setStrength(8);
    std::cout << this->creatureName << " has regenerated full strength! "
                << "Goblin strength is " << this->strength << std::endl;

    battleLog << this->creatureName << " has regenerated full strength! "
                << "Goblin strength is " << this->strength << std::endl;
}
