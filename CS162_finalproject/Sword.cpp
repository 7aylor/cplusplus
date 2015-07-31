/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Sword class.
***********************************************************/
#include "Sword.h"  //includes the header file

//constructor, assigns attack, defense, and name of weapon
Sword::Sword()
{
    this->attack = 3;
    this->defense = 3;
    this->weaponName = "Sword";
}

//destructor
Sword::~Sword()
{
    //dtor
}

//needed to instantiate a Sword object
void Sword::abstract()
{
    //blank
}
