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


#ifndef ALTARROOM_HPP
#define ALTARROOM_HPP

#include <string>


/********************************************************************
	Altar rooms constructors
*********************************************************************/
class Altar : public Space
{
	public:
		Altar();
		void reset();
		bool hasOrb();
		bool hasAltar();
		bool hasTeleport();		
		string getColorAltar(); // get the color of the altar in the room
		void setColorAltar(string); // set the color of the altar in the room
		void playerPlaceOrb();
		
	private:
		bool altarExists;
		string color; // string for the name of the color of the altar in the room 
		
		
};


#endif