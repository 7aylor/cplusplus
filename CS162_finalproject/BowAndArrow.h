/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the BowAndArrow
 * class.
***********************************************************/
#ifndef BOWANDARROW_H
#define BOWANDARROW_H
#include "Weapon.h"     //includes the header for the base class

//inherits from Weapon
class BowAndArrow : public Weapon
{
    public:
        //default constructor
        BowAndArrow();

        //destructor
        virtual ~BowAndArrow();

        //needed to instantiate a BowAndArrow object
        void abstract();
};

#endif // BOWANDARROW_H
