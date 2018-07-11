/**********************************************************************
** Program name: Endless Halls
** Author: Giselle Northy
** Date: 6/3/2018
** Description: 


Space class

The game requires a Space class, which represents the space the player can be in. 
The Space class must be an abstract class that will have pure virtual functions.
Inside the Space class, there must be at least 4 Space pointers: top, right, left, and bottom.

Use the class to create a game with the structure of linked space. 
(You are free to add more Space pointers to the Space class, but must have at least 4 Space pointers)

Note:

Even if your structure is linear, such as a train, you still have at least 4 pointers in the Space class
Any unused pointers need to point to NULL.
 
The derived classes from space are the different rooms: normal, has orb rooms,
has altar rooms and have teleport
*********************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

enum Direction {UP, DOWN, LEFT, RIGHT};

using namespace std;


/********************************************************************
	Space class sets the pointer directions for the 4 types of rooms
	and has virtual child classes hasOrb, hasAltar, and hasTeleport
*********************************************************************/

class Space
{
protected:
	// connecting room pointers
	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	//Space class with pure virtual functions
	Space(); // values to NULL
	virtual ~Space();
	// room connecter function
	void connectSpace(Space* otherSpace, Direction dir); 

	void setUp(Space* r);
	void setDown(Space* r);
	void setLeft(Space* r);
	void setRight(Space* r);
	
	Space* getUp();
	Space* getDown();
	Space* getLeft();
	Space* getRight();

	// returns whether has an object in that room or is a teleport room
	virtual bool hasOrb() = 0;
	virtual bool hasAltar() = 0;
	virtual bool hasTeleport() = 0;

};



#endif