/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the implementation file for the
 * Weapon Base class.
***********************************************************/
#include "Weapon.h" //includes the header file

//constructor, assigns attack, defense, and name of weapon
Weapon::Weapon()
{
    this->attack = attack;
    this->defense = defense;
    this->weaponName = weaponName;
}

Weapon::~Weapon()
{
    //dtor
}

//gets attack
int Weapon::getAttack() const
{
    return this->attack;
}

//gets defense
int Weapon::getDefense() const
{
    return this->defense;
}

//gets weaponName
std::string Weapon::getWeaponName() const
{
    return this->weaponName;
}

//sets attack
void Weapon::setAttack(int att)
{
    this->attack = att;
}

//sets defense
void Weapon::setDefense(int def)
{
    this->defense = def;
}

//sets weaponName
void Weapon::setWeaponName(std::string name)
{
    this->weaponName = name;
}
