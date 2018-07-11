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


#ifndef GAME_HPP
#define GAME_HPP

#include <board.hpp>
#include <player.hpp>


/********************************************************************
	Game class keeps track of the game menu, movements and loops
	that keep game going until player wins or goes insane
*********************************************************************/
class Game
{
	
private:
	Board board;
	Player player;
	int progress;
	
	bool gameInProgress;
	
	string menuMove(string question);
	string menuAskYesNo(string question);
	string menu(string question, string restriction);
	
public:
	
	Game();	
	void start(int);	
	void gameLoop();
	
};


#endif