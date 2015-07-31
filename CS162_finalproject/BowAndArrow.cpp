/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * BowAndArrow class.
***********************************************************/
#include "BowAndArrow.h"//includes the header file

//constructor, assigns attack, defense, and name of weapon
BowAndArrow::BowAndArrow()
{
    this->attack = 6;
    this->defense = 0;
    this->weaponName = "Bow and Arrow";
}

//destructor
BowAndArrow::~BowAndArrow()
{
    //dtor
}

//needed to instantiate a BowAndArrow object
void BowAndArrow::abstract()
{
    //blank
}
