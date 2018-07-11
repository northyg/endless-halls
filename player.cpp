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


#include <player.hpp>
#include <vector>
#include <orbItem.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

#define NUMBER_OF_COLORS 5

using namespace std;



/*********************************************************************
constructor to set the orb colors in the bag
*********************************************************************/

Player::Player()
{
	sanity = 20;
	roomPlayerIsIn = NULL;
	
	bagArray[0].setColor("Red");
	bagArray[1].setColor("Blue");
	bagArray[2].setColor("Yellow");
	bagArray[3].setColor("Green");
	bagArray[4].setColor("Purple");
	
	
}

/*********************************************************************
	keeps track of which room the player is in
*********************************************************************/
void Player::updateLocation(Space* room)
{
	roomPlayerIsIn = room;
}

/*********************************************************************
	updates the bag if orb is picked up
*********************************************************************/

void Player::updateBag(string color, bool getsOrb)
{
	int index; // for the array slot

	if (color == "Red")
	{
		index = 0;
	}		
	
	else if (color == "Blue")
	{
		index = 1;
	}
	
	else if (color == "Yellow")
	{
		index = 2;
	}
	
	else if (color == "Green")
	{
		index = 3;
	}
	
	else if (color == "Purple")
	{
		index = 4;
	}
	
	else
	{
		cout << "ERROR Unknown string in update bag!\n";
		index = 0;
	}
	
	if (getsOrb == true)
	{
		bagArray[index].playerPickup();
	}
	
	else
	{
		bagArray[index].playerPlaceOnAltar();
	}
		
}

/*********************************************************************
	current sanity
*********************************************************************/
int Player::getSanity()
{
	return sanity;
}
	
/*********************************************************************
  room player is in
*********************************************************************/
Space* Player::getLocation()
{
	return roomPlayerIsIn;
}

/*********************************************************************
 return the bag array contents
*********************************************************************/
OrbItem* Player::getBag()
{
	return bagArray;
}
	
	
/*********************************************************************
 show contents of bag
*********************************************************************/	
void Player::printBag()
{
	int count = 0;
	
	cout << "Your bag has ";
	
	for (int i = 0; i < NUMBER_OF_COLORS; ++i)
	{
		if (bagArray[i].hasOrb() == true)
		{
			cout << bagArray[i].getColor() << " Orb ";
			++count;
		}
	}
	if (count == 0)
	{
		cout << "No Orbs";
	}
	cout << endl;
}

void Player::printSanity()
{
	cout << "You have " << (sanity-1) << " sanity remaining\n";
}

/*********************************************************************
 increment down sanity
*********************************************************************/	

void Player::reduceSanity()
{
	--sanity;
}

void Player::easySanity()
{
	sanity = 20;
}

void Player::hardSanity()
{
	sanity = 500;
}

/*********************************************************************
 reset the sanity after losing or starting a new game
*********************************************************************/	

void Player::reset()
{
	sanity = 20;
	roomPlayerIsIn = NULL;
	
	bagArray[0].playerPlaceOnAltar();
	bagArray[1].playerPlaceOnAltar();
	bagArray[2].playerPlaceOnAltar();
	bagArray[3].playerPlaceOnAltar();
	bagArray[4].playerPlaceOnAltar();
}


