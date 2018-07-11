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


#include <room.hpp>
#include <orbRoom.hpp>
#include <iostream>
#include <string>

using namespace std;


/********************************************************************
	Orb rooms have orbs from the start
*********************************************************************/
Orb::Orb() : Space()
{
	orbExists = true;  // room starts off with an orb
	color = "";
}

/********************************************************************
	orb starts off as true
*********************************************************************/
void Orb::reset()
{
	orbExists = true;
}

/********************************************************************
  Function game will call when the player picks up the orb and removes it from this Space
*********************************************************************/

void Orb::playerGetOrb()
{
	orbExists = false;
}

/********************************************************************
	Orbs exist in orb rooms
*********************************************************************/
bool Orb::hasOrb()
{	
	return orbExists;
}

/********************************************************************
	Orb rooms can't have altars
*********************************************************************/	
bool Orb::hasAltar()
{
	return false;
}

/********************************************************************
	Orb rooms can't have teleports
*********************************************************************/
bool Orb::hasTeleport()
{
	return false;
}		
/********************************************************************
	get the color of the orb in the room
*********************************************************************/

string Orb::getColorOrb()
{
	return color;
}

/********************************************************************
// set the color of the orb in the room
*********************************************************************/
void Orb::setColorOrb(string c)
{
	color = c;
}
