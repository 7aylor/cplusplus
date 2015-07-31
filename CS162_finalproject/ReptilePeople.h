/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/11/2014
 *
 * Description: This is the interface file for the
 * ReptilePeople class.
***********************************************************/
#ifndef REPTILEPEOPLE_H
#define REPTILEPEOPLE_H
#include "Creature.h"   //includes the base class header, Creature.h

//inherits traits from the Creature class
class ReptilePeople : public Creature
{
    //really don't need more than public right now
    public:
        //default constructor
        ReptilePeople();

        //destructor
        virtual ~ReptilePeople();

        //special move
        void specialMove(std::ofstream &battleLog);
};

#endif // REPTILEPEOPLE_H
