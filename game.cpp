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


#include <game.hpp>
#include <board.hpp>
#include <iostream>
#include <player.hpp>
#include <space.hpp>
#include <cstdlib>
#include <orbRoom.hpp>
#include <altarRoom.hpp>

using namespace std;


/*********************************************************************
	Game instantiation 
*********************************************************************/
Game::Game()
{	
	progress = 0;
	gameInProgress = false;
}

/*********************************************************************
	Creates the board and assigns difficulty
*********************************************************************/
void Game::start(int difficulty)
{
	// cout where they are	
	// gets the players location (Space*) and passes it to the board function to display the room
	
	gameInProgress = true;
	
	if (1 == difficulty)
	{
		board.createEasyBoard();
		player.easySanity();
		progress = 4;	// only need to place one more orb to win
	}
	else
	{
		board.createHardBoard();
		player.hardSanity();
		progress = 0;	// must place all five orbs to win
	}
	
	Space* startRoom;
	startRoom = board.getStartRoom();
	player.updateLocation(startRoom);	
	
	board.displayRoom(player.getLocation());
	
	while (gameInProgress == true)
	{
		
		gameLoop();
	}
	
	// Game finished, resetting board and player
	board.resetBoard();
	player.reset();
	
}

/*********************************************************************
	Game loop, makes sure that the way player is trying to go is valid
	also checks sanity, and has menu for directions to go and bag contents
*********************************************************************/
void Game::gameLoop()
{
	char move;

	Space* roomTryingToMoveTo = NULL;
	
	// First check if player is out of sanity
	
	if (player.getSanity() <= 0)
	{
		cout << "Game over! You went insane!\n";
		gameInProgress = false;
		return;
		
	}

	string movement = menuMove("Which way do you want to move?\nW = up, A = left, S = down, D = right\nB = display bag inventory.\n");
	// get the location they picked and will validate if its free to move there
	if (movement == "w" || movement == "W")
	{
		roomTryingToMoveTo = player.getLocation()->getUp();
	}
	else if(movement == "a" || movement == "A")
	{
		roomTryingToMoveTo = player.getLocation()->getLeft();
	}
	else if(movement == "s" || movement == "S")
	{
		roomTryingToMoveTo = player.getLocation()->getDown();
	}
	else if(movement == "d" || movement == "D")
	{
		roomTryingToMoveTo = player.getLocation()->getRight();
	}
	else if (movement == "b" || movement == "B")
	{
		player.printBag();
		return;
	}

	if (roomTryingToMoveTo == NULL)
	{
		// User entered a direction that has rubble
		cout << "That way is blocked; try again!\n";
		return;
	}
	
	// we get here if the way they chose is a room they can go into
	
	// First we need to see if this is a special teleporting room
	if (roomTryingToMoveTo->hasTeleport() == true)
	{
		// roomTryingToMoveTo = rand() % board.getNumberOfRooms() - 1;
		int roomIndex = rand() % board.getNumberOfRooms();

		// cout << "You found a teleport room, your chosen random room is " << (roomIndex+1) << endl;
		// cout << "Number of rooms in vector is: " << board.getNumberOfRooms() << endl;
		roomTryingToMoveTo = board.getSpecificRoom(roomIndex);
		
		// if(roomTryingToMoveTo == room7)
		// make sure we are not teleporting back into the teleport room
		if (roomTryingToMoveTo->hasTeleport() == true)
		{
			// WARNING, this will not work if the teleport room is the last room in the vector 
			roomTryingToMoveTo = board.getSpecificRoom(roomIndex + 1);
		}

	}
	
	// We can safely move the player into this room now
	player.updateLocation(roomTryingToMoveTo);
	board.displayRoom(player.getLocation());
	player.printSanity();

	// Check if this room has an Orb or an Altar
	if (roomTryingToMoveTo->hasOrb() == true)
	{
		// Ask the user if they want to pick up the orb
		string pickUpOrb = menuAskYesNo("There is an Orb in this room, would you like to pick it up? (Y or N)\n");
		
		if (pickUpOrb == "y" || pickUpOrb == "Y")
		{
			string color = ((Orb*)roomTryingToMoveTo)->getColorOrb();
			// If they want to pick up the orb, remove Orb from room and place it in Player's Bag
			((Orb*)roomTryingToMoveTo)->playerGetOrb();
			// need to get orb color here
			player.updateBag(color, true);
		}
	}
	else if (roomTryingToMoveTo->hasAltar() == true)
	{
		// need to check player's bag and see if they have the matching orb for this room first.
		OrbItem* bag = player.getBag();
		string altarColor = ((Altar*)roomTryingToMoveTo)->getColorAltar();
		
		if (altarColor == "Red")
		{
			if (bag[0].hasOrb() == true)
			{
				// Player has this atlar color orb in their bag
				
				//Display option for user to place orb or keep it
				string placeOrb = menuAskYesNo("There is an Altar in this room and you have the matching Orb, would you like to place it on the Altar? (Y or N)\n");
				if (placeOrb == "y" || placeOrb == "Y")
				{
					// remove Orb from player's bag
					player.updateBag("Red", false);
					// update progress of game
					++progress;
					// remove Altar from room so it stops asking the player
					((Altar*)roomTryingToMoveTo)->playerPlaceOrb();
				}
			}
		}
		else if (altarColor == "Blue")
		{
			if (bag[1].hasOrb() == true)
			{
				// Player has this atlar color orb in their bag
				
				//Display option for user to place orb or keep it
				string placeOrb = menuAskYesNo("There is an Altar in this room and you have the matching Orb, would you like to place it on the Altar? (Y or N)\n");
				if (placeOrb == "y" || placeOrb == "Y")
				{
					// remove Orb from player's bag
					player.updateBag("Blue", false);
					// update progress of game
					++progress;
					// remove Altar from room so it stops asking the player
					((Altar*)roomTryingToMoveTo)->playerPlaceOrb();
				}
			}
		}
		else if (altarColor == "Yellow")
		{
			if (bag[2].hasOrb() == true)
			{
				// Player has this atlar color orb in their bag
				
				//Display option for user to place orb or keep it
				string placeOrb = menuAskYesNo("There is an Altar in this room and you have the matching Orb, would you like to place it on the Altar? (Y or N)\n");
				if (placeOrb == "y" || placeOrb == "Y")
				{
					// remove Orb from player's bag
					player.updateBag("Yellow", false);
					// update progress of game
					++progress;
					// remove Altar from room so it stops asking the player
					((Altar*)roomTryingToMoveTo)->playerPlaceOrb();
				}
			}
		}
		else if (altarColor == "Green")
		{
			if (bag[3].hasOrb() == true)
			{
				// Player has this atlar color orb in their bag
				
				//Display option for user to place orb or keep it
				string placeOrb = menuAskYesNo("There is an Altar in this room and you have the matching Orb, would you like to place it on the Altar? (Y or N)\n");
				if (placeOrb == "y" || placeOrb == "Y")
				{
					// remove Orb from player's bag
					player.updateBag("Green", false);
					// update progress of game
					++progress;
					// remove Altar from room so it stops asking the player
					((Altar*)roomTryingToMoveTo)->playerPlaceOrb();
				}
			}
		}
		else if (altarColor == "Purple")
		{
			if (bag[4].hasOrb() == true)
			{
				// Player has this atlar color orb in their bag
				
				//Display option for user to place orb or keep it
				string placeOrb = menuAskYesNo("There is an Altar in this room and you have the matching Orb, would you like to place it on the Altar? (Y or N)\n");
				if (placeOrb == "y" || placeOrb == "Y")
				{
					// remove Orb from player's bag
					player.updateBag("Purple", false);
					// update progress of game
					++progress;
					// remove Altar from room so it stops asking the player
					((Altar*)roomTryingToMoveTo)->playerPlaceOrb();
				}
			}
		}
		
		// Check if this was the last orb to place and if the player wins
		if (progress >= 5)
		{
			// YOU WIN!
			cout << "Congratulations; you placed all the orbs and won!\n";
			gameInProgress = false;
		}
	}

	
	// Need to reduce player's sanity
	player.reduceSanity();

}
	



/********************************************************************
	Input validation for the menu
*********************************************************************/
string Game::menu(string question, string restriction)
{
	bool loop = true; //initialize loop to true to re-use it
	string choice;
	string selection;
	
	while (loop == true)
	{
		cout << question; //function parameter
		cin >> choice;			
		

		if ((choice.length() < 2) && (choice.find_first_not_of(restriction) == string::npos )) // make sure there are only ints in the string. if this is true they only entered numbers
		{
			loop = false;		
		}	
		
		else
		{
			cout << "Try again. Enter a valid choice." << endl;
		}

	}
	
	return choice;
	
}


/********************************************************************
	// Menu for validation for movement so that the user only puts
	in w or W or A, etc
*********************************************************************/
string Game::menuMove(string question)
{
	
	return menu(question, "wWaAsSdDbB");
}

/********************************************************************
	// Menu for validation for picking up orbs and placing them so that the user only puts
	in Y or y or N or n
*********************************************************************/
string Game::menuAskYesNo(string question)
{
	return menu(question, "yYnN");
}



