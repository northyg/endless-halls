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

#ifndef TELEPORTROOM_HPP
#define TELEPORTROOM_HPP

#include <space.hpp>

using namespace std;


/********************************************************************
	Teleport room constructors
*********************************************************************/
class Teleport : public Space
{
	public:
		Teleport();
		bool hasOrb();
		bool hasAltar();
		bool hasTeleport();

	
};

#endif