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

#ifndef ORBITEM_HPP
#define ORBITEM_HPP


#include <string>


using namespace std;

/*********************************************************************
	Orb class keeps track if orbs can be placed, if they have been
	placed and so forth
*********************************************************************/	

class OrbItem
{
	
private:
	
	string color;
	bool playerHas;
	
	
public:

	OrbItem();
	
	string getColor();
	void setColor(string c);
	bool hasOrb();
	void playerPickup();
	void playerPlaceOnAltar();
		
};

#endif