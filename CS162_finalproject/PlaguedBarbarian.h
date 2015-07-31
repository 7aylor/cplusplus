/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the PlaguedBarbarian
 * class.
***********************************************************/
#ifndef PLAGUEDBARBARIAN_H
#define PLAGUEDBARBARIAN_H
#include "Barbarian.h" //includes parent class header Barbarian.h

//inherits from Barbarian
class PlaguedBarbarian : public Barbarian
{
    public:
        //default constructor
        PlaguedBarbarian();

        //destructor
        virtual ~PlaguedBarbarian();

        //overriden attack function
        int attack();

        //redefined defend function
        int defend();
};

#endif // PLAGUEDBARBARIAN_H
