/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/11/2014
 *
 * Description: This is the interface file for the
 * BlueMen class.
***********************************************************/
#ifndef BLUEMEN_H
#define BLUEMEN_H
#include "Creature.h"   //includes the base class header, Creature.h


//inherits traits from the Creature class
class BlueMen : public Creature
{
    //really don't need more than public right now
    public:
        //default constructor
        BlueMen();

        //destructor
        virtual ~BlueMen();

        //special move
        void specialMove(std::ofstream &battleLog);
};

#endif // BLUEMEN_H
