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


#include <iostream>
#include <string>
#include <game.hpp>
#include <board.hpp>
#include <cstdlib>
#include <time.h>
#include <fstream>


using namespace std;


int menu(string question, int min, int max);

int main()
{
	srand(time(NULL));
	
/*********************************************************************
	Display the title text file at the beginning of the game
*********************************************************************/
	
	string lines = "";
	string fileName = "banner.txt";


	ifstream inputFile;
	inputFile.open(fileName.c_str());
	
	if (inputFile)
	{
		while (inputFile)
		{
			string temp;
			getline(inputFile, temp);
			temp += "\n";
			lines += temp;			
		}
		cout << lines << endl;
		
		inputFile.close();	
		
	}
	else
	{
		cout << "Error reading text file!\n";
	}

	
	int option = 1;
	
	bool playAgain = true;
	Game game;
	
/*********************************************************************
	Game intro text
*********************************************************************/		
	cout <<
		"Your long quest to uncover the mysterious Lucid Nightmare Steed \n"
		"has brought you to Kun-Lai Summit, with a faint clue written on parchment:\n"
		"What you seek is buried within...'\n\n"
		"After entering the Tomb of Secrets, you discover the path forward \n"
		"can only be obtained by consuming the ashes of an evil sorcerer.\n"
		"While this seemed like a good idea at the time, this unfortunately \n"
		"causes you to pass out, and upon awakening, find yourself in an endless maze with nothing more than a bag and some scratch paper.\n"
		"Some paths are blocked by rubble "<< SET_YELLOW << "#####"<< SET_COLOR_NORMAL <<" and doorways are marked by "<< SET_GREEN <<"====="<< SET_COLOR_NORMAL <<" or "<<SET_GREEN<<"|"<< SET_COLOR_NORMAL <<"\n\n"
		<< SET_BOLD_BLUE <<"Welcome to the Endless Halls." <<SET_COLOR_NORMAL <<
		"\n\nExplore through the maze and pick up colored orbs " << SET_RED << "~0~" << SET_COLOR_NORMAL" and place them on their same colored altar" << SET_RED << " -+-\n" << SET_COLOR_NORMAL
		"Find and place them all to win before you lose your sanity...\n\n";
	
	while(playAgain == true)
	{
		option = menu("1. Explore easy maze\n2. Explore hard maze\n3. Quit\n", 1, 3);
		if (1 == option || 2 == option)
		{
			game.start(option);
		}			
		else 
		{
			playAgain = false;
			break;
		}		
		
		
/*********************************************************************
	End game menu. Play again or quit?
*********************************************************************/	

	
		option = menu("1. Play again?\n2. Quit\n", 1, 2);
		if (2 == option)
		{
			break;
		}

	}	
	return 0;
}



/*********************************************************************
	// Menu for validation includes input validation to only take ints. 
	// If invalid input is given, asks user for valid input
*********************************************************************/
int menu(string question, int min, int max)
{
	
	bool loop = true; //initialize loop to true to re-use it
	string choice;
	int numChoice;
	
	while (loop == true)
	{
		cout << question; //function parameter
		cin >> choice;			
		

		if ((choice.length() < 10) && (choice.find_first_not_of("0123456789") == string::npos )) // make sure there are only ints in the string. if this is true they only entered numbers
		{
			numChoice = stoi(choice); // turns the char into an int
			
			if (numChoice >= min && numChoice <= max) // both these two (min and max) function parameter
			{
				loop = false;
			}
			else
			{
				cout << "Try again. Enter a valid choice." << endl;
			}
			
		}	
		else
		{
			cout << "Try again. Enter a valid choice." << endl;
		}

	}
	
	return numChoice;
	

}