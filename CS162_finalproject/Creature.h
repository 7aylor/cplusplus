/***********************************************************
 * Author: Taylor Buchheit
 * Date: 5/6/2014
 * Date Last Modified: 5/25/2014
 *
 * Description: This is the interface file for the Abstract
 * Creature class, the base class.
***********************************************************/
#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include <fstream>

class Creature
{
    public:
        //default constructor
        Creature();

        //destructor
        virtual ~Creature();

        //accessors
        int getArmor() const;
        int getStrength() const;
        int getDiceNumAtt() const;
        int getDiceFacesAtt() const;
        int getDiceNumDef() const;
        int getDiceFacesDef() const;
        std::string getCreatureName() const;
        int getStartNum() const;
        std::string getTeam() const;
        int getWins() const;
        int getBattles() const;

        //mutators
        void setStrength(int thisStrength);
        void setCreatureName(std::string name);
        void setStartNum();
        void setTeam(std::string theTeam);
        void setWins(int numWins);
        void setBattles(int numBattles);

        //special move makes Creature abstract
        virtual void specialMove(std::ofstream &battleLog) = 0;

        //virtual attack function, will be overridden later
        virtual int attack();

        //defend function, will be redefined later
        int defend();

    protected:
        int armor;		        //holds the armor of the creature
        int strength;	    	//holds the strength of the creature
        int diceNumAtt;     	//holds the number of attack dice
        int diceFacesAtt;		//holds the number of attack faces of a die
        int diceNumDef;     	//holds the number of defending dice
        int diceFacesDef;		//holds the number of defense faces of a die
        std::string creatureName;//holds the name of the creature
        int startNum;	    	//holds the starting value of the creature
        std::string team;       //holds the team name
        int wins;               //holds the number of wins
        int battles;
};

#endif // CREATURE_H
