/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the Weapon
 * base class.
***********************************************************/
#ifndef WEAPON_H
#define WEAPON_H
#include <string>   //for strings

class Weapon
{
    public:
        //default constructor
        Weapon();

        //destructor
        virtual ~Weapon();

        //makes the Weapon base class abstract
        virtual void abstract() = 0;

        //accessor functions
        int getAttack() const;
        int getDefense() const;
        std::string getWeaponName() const;

        //mutator function
        void setAttack(int att);
        void setDefense(int def);
        void setWeaponName(std::string name);

    protected:
        int attack;             //weapon's attack
        int defense;            //weapon's defense
        std::string weaponName; //weapon's name
};

#endif // WEAPON_H
