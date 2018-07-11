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


#include <orbItem.hpp>
#include <string>



using namespace std;

/*********************************************************************
orbs set the false at the beginning because they haven't
picked up any yet
*********************************************************************/	

OrbItem::OrbItem()
{
	// color = c;
	playerHas = false;
}

/*********************************************************************
get the color of the orb
*********************************************************************/	
string OrbItem::getColor()
{
	return color;
}


/*********************************************************************
 set color
*********************************************************************/	
void OrbItem::setColor(string c)
{
	color = c;
}


/*********************************************************************
 if the player has an orb or not
*********************************************************************/	
bool OrbItem::hasOrb()
{
	return playerHas;
}

	
/*********************************************************************
 player picks up an orb
*********************************************************************/	
void OrbItem::playerPickup()
{
	playerHas = true;
}

	
/*********************************************************************
player places an orb on an altar so no longer has it in their bag
*********************************************************************/	
void OrbItem::playerPlaceOnAltar()
{
	playerHas = false;
}
		
	