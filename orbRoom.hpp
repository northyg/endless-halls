/*********************************************************************
** Program name: Endless Halls
** Author: Giselle Northy
** Date: 6/3/2018
** Description: 

This program is a maze of rooms linked together by pointers. Players need
to find orbs in rooms, pick them up and place them on altars in altar rooms
to win. In easy mode, the player has 20 steps before they go "insane" and lose.
In hard mode, they can take 500 steps before they go "insane." 

Easy Map has 9 rooms
Hard Map has 222 rooms
*********************************************************************/


#ifndef ORBROOM_HPP
#define ORBROOM_HPP

#include <space.hpp>
#include <string>

using namespace std;

/********************************************************************
	Orb class has pointers to where orbs are, the colors and 
	removes them if they are picked up
*********************************************************************/
class Orb : public Space
{
	public:
		Orb();
		void reset();
		bool hasOrb();
		bool hasAltar();
		bool hasTeleport();
		string getColorOrb(); // get the color of the orb in the room
		void setColorOrb(string); // set the color of the orb in the room
		void playerGetOrb();
	
	private:
		bool orbExists;
		string color; // string for the name of the color of the orb in the room
		
};

#endif