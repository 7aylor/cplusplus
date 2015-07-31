/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the Sword
 * class.
***********************************************************/
#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"     //includes the header for the base class

//inherits from Weapon
class Sword : public Weapon
{
    public:
        //default constructor
        Sword();

        //destructor
        virtual ~Sword();

        //needed to instantiate a Sword object
        void abstract();
};

#endif // SWORD_H
