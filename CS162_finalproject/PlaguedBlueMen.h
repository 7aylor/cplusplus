/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the
 * PlaguedBlueMen class.
***********************************************************/
#ifndef PLAGUEDBLUEMEN_H
#define PLAGUEDBLUEMEN_H
#include "BlueMen.h"    //includes parent class header BlueMen.h

//inherits from BlueMen
class PlaguedBlueMen : public BlueMen
{
    public:
        //default constructor
        PlaguedBlueMen();

        //destructor
        virtual ~PlaguedBlueMen();

        //overrideen attack function
        int attack();

        //redefined defend function
        int defend();
};

#endif // PLAGUEDBLUEMEN_H
