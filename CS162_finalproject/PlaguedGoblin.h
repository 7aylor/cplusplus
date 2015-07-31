/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/22/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the PlaguedGoblin
 * class.
***********************************************************/
#ifndef PLAGUEDGOBLIN_H
#define PLAGUEDGOBLIN_H
#include "Goblin.h"     //includes parent class header Goblin.h

//inherits from Goblin
class PlaguedGoblin : public Goblin
{
    public:
        //default constructor
        PlaguedGoblin();

        //destructor
        virtual ~PlaguedGoblin();

        //overriden attack function
        int attack();

        //redefined defend function
        int defend();
};

#endif // PLAGUEDGOBLIN_H
