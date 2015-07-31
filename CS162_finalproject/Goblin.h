/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/11/2014
 *
 * Description: This is the interface file for the
 * Goblin class.
***********************************************************/
#ifndef GOBLIN_H
#define GOBLIN_H
#include "Creature.h"   //includes the base class header, Creature.h

//inherits traits from the Creature class
class Goblin : public Creature
{
    //really don't need more than public right now
    public:
        //default constructor
        Goblin();

        //destructor
        virtual ~Goblin();

        //special move
        void specialMove(std::ofstream &battleLog);
};

#endif // GOBLIN_H
