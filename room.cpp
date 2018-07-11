/*********************************************************************
** Program name: Endless Halls
** Author: Giselle Northy
** Date: 6/3/2018
** Description:

This program is a maze of rooms linked together by pointers. Players need
to find orbs in rooms, pick them up and place them on altars in altar rooms
to win. In easy mode, the player has 20 steps before they go "insane" and lose.
In hard mode, they can take 500 steps before they go "insane." 

*********************************************************************/


#include <room.hpp>

#include <iostream>
#include <string>



/********************************************************************
 Space constructor; this is a plain room and will never have objects, altars or teleports
*********************************************************************/
Room::Room() : Space()
{

}


/********************************************************************
	Rooms that have orbs
*********************************************************************/
bool Room::hasOrb()
{
	return false;
}

/********************************************************************
	Rooms that have altars
*********************************************************************/
bool Room::hasAltar()
{
	return false;
}

/********************************************************************
	Room that has hidden teleport
*********************************************************************///
bool Room::hasTeleport()
{
	return false;
}
