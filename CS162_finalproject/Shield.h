/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the Shield
 * class.
***********************************************************/
#ifndef SHIELD_H
#define SHIELD_H
#include "Weapon.h"     //includes the header for the base class

//inherits from Weapon
class Shield : public Weapon
{
    public:
        //default constructor
        Shield();

        //destructor
        virtual ~Shield();

        //needed to instantiate a Shield object
        void abstract();
};

#endif // SHIELD_H
