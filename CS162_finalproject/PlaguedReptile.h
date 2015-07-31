/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the PlaguedReptile
 * class.
***********************************************************/
#ifndef PLAGUEDREPTILE_H
#define PLAGUEDREPTILE_H
#include "ReptilePeople.h"  //includes parent class header ReptilePeople.h

//inherits from ReptilePeople
class PlaguedReptile : public ReptilePeople
{
    public:
        //default constructor
        PlaguedReptile();

        //destructor
        virtual ~PlaguedReptile();

        //overriden attack function
        int attack();

        //redefined defend function
        int defend();
};

#endif // PLAGUEDREPTILE_H
