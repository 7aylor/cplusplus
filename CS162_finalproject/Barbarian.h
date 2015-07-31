/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the Barbarian
 * class.
***********************************************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Creature.h"   //includes the base class header, Creature.h


//inherits traits from the Creature class
class Barbarian : public Creature
{
    //really don't need more than public right now
    public:
        //default constructor
        Barbarian();

        //destructor
        virtual ~Barbarian();

        //special move
        void specialMove(std::ofstream &battleLog);
};

#endif // BARBARIAN_H
