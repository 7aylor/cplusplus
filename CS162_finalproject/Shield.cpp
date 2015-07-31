/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Shield class.
***********************************************************/
#include "Shield.h" //includes the header file

//constructor, assigns attack, defense, and name of weapon
Shield::Shield()
{
    this->attack = 0;
    this->defense = 6;
    this->weaponName = "Shield";
}

//destructor
Shield::~Shield()
{
    //dtor
}

//needed to instantiate a Shield object
void Shield::abstract()
{
    //blank
}
