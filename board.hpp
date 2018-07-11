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


#ifndef BOARD_HPP
#define BOARD_HPP

#include <space.hpp>
#include <vector>

#define SET_BOLD_RED        "\033[1;31m"
#define SET_RED             "\033[0;31m"
#define SET_BOLD_GREEN      "\033[1;32m"
#define SET_GREEN           "\033[0;32m"
#define SET_BOLD_YELLOW     "\033[1;33m"
#define SET_YELLOW          "\033[0;33m"
#define SET_BOLD_BLUE       "\033[1;34m"
#define SET_BLUE            "\033[0;34m"
#define SET_BOLD_MAGENTA    "\033[1;35m"
#define SET_MAGENTA         "\033[0;35m"

#define SET_COLOR_NORMAL    "\033[0m"

/********************************************************************
Console Colors thanks to Sarah Maas
http://blog.sarah-maas.com/2018/03/13/colors/ 
*********************************************************************/ 

using namespace std;



/********************************************************************
 Board Class constructors
*********************************************************************/
class Board
{
	private:
		vector <Space*> board; // vector of space pointers
		
		
	public:
		Board();
		~Board();
		void resetBoard();
		void displayRoom(Space* room);
		
		void printLeft(Space*);
		void printRight(Space*);
		
		Space* getStartRoom();
		Space* getSpecificRoom(int);
		
		int getNumberOfRooms();
		
		void createEasyBoard();
		void createHardBoard();
		
};



#endif