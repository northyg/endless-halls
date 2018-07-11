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


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <room.hpp>
#include <space.hpp>
#include <orbItem.hpp>
#include <string>
#include <cstdlib>


/********************************************************************
 Player class has the players room pointer, their bag, sanity
 game progress and what orbs they have
*********************************************************************/
class Player
{
	

private:

	Space* roomPlayerIsIn;
	int sanity;	
	OrbItem bagArray[5]; // an array with 5 spots for the 5 different orbs
	
public:

	Player();
	
	void updateLocation(Space* room);
	
	
	void updateBag(string color, bool getsOrb);
	int getSanity();
	Space* getLocation();
	OrbItem* getBag();
	void printBag(); // show contents of bag
	void printSanity();
	
	void reduceSanity();
	void easySanity();
	void hardSanity();

	void reset();
	
};



#endif