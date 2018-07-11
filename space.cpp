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


#include <space.hpp>
#include <cstddef>

using namespace std;


/*********************************************************************
	Set values to NULL
*********************************************************************/	

Space::Space()
{
	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;	
	
}

/********************************************************************
	virtual destructor
*********************************************************************/
Space::~Space()
{
	
}

/********************************************************************
	connectSpace reduces the amount of pointers needed by pointing
	back to the space before it using "this"
*********************************************************************/
void Space::connectSpace(Space* otherSpace, Direction dir)
{
	if(dir == UP)
	{
		this->up = otherSpace;
		otherSpace->down = this;
	}
	else if(dir == DOWN)
	{
		this->down = otherSpace;
		otherSpace->up = this;
	}
	else if(dir == LEFT)
	{
		this->left = otherSpace;
		otherSpace->right = this;
	}
	else if(dir == RIGHT)
	{
		this->right = otherSpace;
		otherSpace->left = this;
	}
}


/*********************************************************************
	Function to set the next pointer that is up
*********************************************************************/	
void Space::setUp(Space* r)
{
	up = r;
}

/*********************************************************************
	Function to set the next pointer that is down
*********************************************************************/	
void Space::setDown(Space* r)
{
	down = r;
}


/*********************************************************************
	Function to set the next pointer to the left
*********************************************************************/	
void Space::setLeft(Space* r)
{
	left = r;
}

/*********************************************************************
	Function to set the next pointer to the right
*********************************************************************/	
void Space::setRight(Space* r)
{
	right = r;
}

/*********************************************************************
	Function to get the pointer to the top
*********************************************************************/	
Space* Space::getUp()
{
	return up;
}


/*********************************************************************
	Function to get the pointer that is down
*********************************************************************/	
Space* Space::getDown()
{
	return down;
}


/*********************************************************************
	Function to get the pointer to the left
*********************************************************************/	
Space* Space::getLeft()
{
	return left;
}


/*********************************************************************
	Function to get the pointer to the right
*********************************************************************/	
Space* Space::getRight()
{
	return right;
}

