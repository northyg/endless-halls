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



#include <iostream>
#include <string>
#include <teleportRoom.hpp>

using namespace std;

/********************************************************************
	Space constructor; this is a plain room and will never have objects, altars or teleports
*********************************************************************/
Teleport::Teleport() : Space()
{

}


/********************************************************************
	Teleport rooms can't have orbs
*********************************************************************/
bool Teleport::hasOrb()
{
	return false;
}

/********************************************************************
	Teleport rooms can't have altars
*********************************************************************/
bool Teleport::hasAltar()
{
	return false;
}

/********************************************************************
	returns true all the time because teleport room always exists
*********************************************************************/

bool Teleport::hasTeleport()
{
	return true;
}
