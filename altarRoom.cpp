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
#include <altarRoom.hpp>

#include <iostream>
#include <string>

using namespace std;

/********************************************************************
	room starts off with an altar that disappears after orb is placed on it
*********************************************************************/
Altar::Altar() : Space()
{
	altarExists = true;
	color = "";
}

/********************************************************************
	resets the board to put altars back
*********************************************************************/
void Altar::reset()
{
	altarExists = true;
}

/********************************************************************
	when the correct color orb is placed on the altar the altar disappears
*********************************************************************/
void Altar::playerPlaceOrb() 
{
	altarExists = false;
}

/********************************************************************
	altar rooms can't have orbs
*********************************************************************/
bool Altar::hasOrb()
{
	return false;
}

/********************************************************************
	Altar rooms have altars
*********************************************************************/
bool Altar::hasAltar()
{
	return altarExists;
}

/********************************************************************
	Altar rooms can't have teleport rooms
*********************************************************************/
bool Altar::hasTeleport()
{
	return false;
}

/********************************************************************
	returns the color of the altar
*********************************************************************/
string Altar::getColorAltar() // get the color of the altar in the room
{
	return color;
}

/********************************************************************
	sets the color of the altar
*********************************************************************/
void Altar::setColorAltar(string c) // set the color of the altar in the room
{
	color = c;
}