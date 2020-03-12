/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Game class implementation 
* **	
* ****************************************************************************/
#include "Game.hpp"
#include "Space.hpp"
#include "FrozenTundra.hpp"
#include "Home.hpp"
#include "Goal.hpp"
#include "Remains.hpp"
#include "Crevasse.hpp"
#include "Item.hpp"
#include "Rope.hpp"
#include "Radio.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

//Default Constructor
	//runs user through setting up the program and the game board
Game::Game()
{
	system ("CLS");							//clear the screen does not work on school compiler :(				
	std::cout << "Welcome to Tundra" << std::endl<< std::endl;
	std::cout << "The Earth has plunged into an arctic freeze" << std::endl<< std::endl;
	std::cout << "Humanity has diminished, forced underground into survival shelters" << std::endl<< std::endl;
	char enter;						
	enter = '1';					
	while (enter != '\n')			
	{
		enter = menu.cont();					//pauses screen until user hits enter
	}
	system ("CLS");	
	std::cout << "You are one of the few left in your rapidly declining base"<< std::endl<< std::endl;
	std::cout << "In order to survive you have been tasked with retrieving an old radio from a nearby abandoned shelter"<< std::endl<< std::endl;
	std::cout << "Your goal is to navigate the tundra, find the radio, and bring the radio back to the home base"<< std::endl<< std::endl;
	std::cout << "WARNING: The freezing temperatures will degrade your health over time \nBeware of environmental hazards..."<< std::endl<< std::endl;
	enter = '1';					
	while (enter != '\n')			
	{
		enter = menu.cont();					//pauses screen until user hits enter		
	}
	system ("CLS");
	std::cout << "FOR TESTING\n";
	viewGoalFlag = menu.input3();				//For testing, turns the goal space visible to the user
	enter = '1';					
	while (enter != '\n')			
	{
		enter = menu.enter();		
	}
	std::srand(time(NULL));						//seed random number generator
	Game::createBoard();						//create the game board
	Game::linkBoard();							//link the game board spaces together
	Game::printMap();							//print the beginning map
	Game::Day();								//run the day function until the player wins or dies
}

//Create Board Function
	//Loops through the game board array and fills array with pointers to spaces
void Game::createBoard()
{
	for (int i = 0; i<10; i++)					//loop through game board array
	{
		for (int j = 0; j<10; j++)
		{
			Game::genRanLoc();					//generates a random space type and points towards space with location pointer
			Board[i][j] = LocationPtr;			//fills the current board location with the generated space
			LocationPtr = NULL;					//set the location pointer to null before generating another space
		}
		std::cout << std::endl;					//used for debugging
	}
	int x = ((std::rand() % 10));				//generate a random number 0-9
	int y = ((std::rand() % 10));				//generate a random number 0-9
	while (x == 4 && y == 4)					//make sure that both of the numbers are not 4
	{
		int x = ((std::rand() % 10));			//if they are, regenerate the numbers until they both are not 4
		int y = ((std::rand() % 10));	
	}
	delete Board[x][y];							//deletes the space at the generated location
	LocationPtr = new Goal;						//set the location pointer to be the goal space
	LocationPtr->setDiscoverFlag(viewGoalFlag);	//set the goal to be visible depending on the user choice
	Board[x][y] = LocationPtr;					//fill that space with the goal
	delete Board[4][4];							//delete the space at 4,4
	LocationPtr = new Home;						//set the location pointer to be the home space
	Board[4][4] = LocationPtr;					//fill 4,4 with the home space, the location pointer is also now set at the home base for the start
}

//Generate Random location Function
	//sets the location pointer to a new space
void Game::genRanLoc()
{
	int newSpace = (std::rand()%10)+1;		//Generate a random number to decide the new space
	std::cout << newSpace;					//print out the number for debugging
	if (newSpace < 8)						//if the number is 1-7 than the space is blank (frozen tundra)
	{
		LocationPtr = new FrozenTundra;
	}
	else if (newSpace == 8)					//if the number is 8 than the space is a crevasse
	{
		LocationPtr = new Crevasse;	
	}
	else if (newSpace >= 9)					//if the number is 9 or 10 than the space is remains
	{
		LocationPtr = new Remains;	
	}
	else									//if there was some sort of problem set the space to blank (should never be called in the current design)
	{
		LocationPtr = new FrozenTundra;
	}
}

//Link Board Function
	//Loops through the game board array and sets the pointers of the space to appropriate place
void Game::linkBoard()
{
	for (int i = 0; i<10; i++)				//loop through the array
	{
		for (int j = 0; j<10; j++)
		{
			if (i == 0)						//set the top pointer for the first row to null
			{
				Board[i][j]->setTop(NULL);
			}
			else							//else set the top pointer to the above space in the array
			{
				Board[i][j]->setTop(Board[(i-1)][j]);	
			}
			if (j == 0)						//set the left pointer for the first column to null
			{
				Board[i][j]->setLeft(NULL);
			}
			else							//else set the left pointer to the left space in the array
			{
				Board[i][j]->setLeft(Board[i][(j-1)]);	
			}
			if (i == 9)						//set the bottom pointer for the last row to null
			{
				Board[i][j]->setBottom(NULL);
			}
			else							//else set the bottom pointer to the below space in the array
			{
				Board[i][j]->setBottom(Board[(i+1)][j]);	
			}
			if (j == 9)						//set the right pointer for the last column to null
			{
				Board[i][j]->setRight(NULL);
			}
			else							//else set the right pointer to the right space in the array
			{
				Board[i][j]->setRight(Board[i][(j+1)]);	
			}
		}
	}
}

//Delete Board function
	//Loops through the game board array and deletes each space in the array
void Game::deleteBoard()
{
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if(Board[i][j])
			{
				delete Board[i][j];	
			}
		}
	}
	std::cout << "Board deleted" << std::endl;
}

//Day Function
	//Loops for 100 times or until the character wins or dies
	//modifies the character health and moves the character according to user input
	//then calls the effect of the new space and updates the game board, finally checks user health and loops
void Game::Day()
{
	int check = 0;						//set check to 0 and begin loop
	for(int i = 0; i < 100; i++)
	{
		User.modifyHealth(-10);			//first decrease character health by 10 for environmental effect of cold temp
		char choice = menu.input1();	//ask for user input and validate to get next move
		Game::Move(choice);				//send the choice to the move function which updates the location pointer
		Game::spaceEffect();			//get the space effect of the location pointer
		Game::setFlag();				//set the discover flag of the location if it is not already set
		char enter;						//pause until the user hits enter so they can read the space effect
		enter = '1';					
		while (enter != '\n')			
		{
			enter = menu.cont();		
		}
		Game::printMap();				//update the map on the screen (in the process clears the screen)
		check = Game::checkGoal();		//check to see if the user is on the home base space with the radio in the inventory
		if (check == 1)					//if the user has succeeded than exit the loop
		{
			i=100;
		}
		check = User.getHealth();		//check to see if the character still has health remaining
		if (check <= 0)					//if the character health is 0 or less than exit the loop
		{
			i=100;
		}
	}
	if (check > 0)						//use the check integer to report to the user the state of the game (win or loss)
	{
		std::cout << "\nYou got the Radio back to the Base! \n\nYou WON!!!" << std::endl << std::endl;
	}
	else if (check <= 0)
	{
		std::cout << "You vanished in the tundra, never to be seen again..." << std::endl << std::endl;
	}
}

//Move Function
	//Sets the location pointer to a new space based on the pointers of the space
	//passed in char determines the pointer to use
void Game::Move(char direction)
{
	Space* oldLocation = LocationPtr;					//copy the old location incase the user hits the boundary of the board
	switch (direction)								
	{
		case 'w': LocationPtr = LocationPtr->goTop();	//w corresponds to moving the location up one space
			break;
		case 'a': LocationPtr = LocationPtr->goLeft();	//a corresponds to moving the location left one space
			break;
		case 's': LocationPtr = LocationPtr->goBottom();//s corresponds to moving the location down one space
			break;
		case 'd': LocationPtr = LocationPtr->goRight();	//d corresponds to moving the location right one space
			break;			
	}
	if (LocationPtr == NULL)							//if the user attempts to move outside of the game board than set the location pointer to the old location and print a message
	{
		std::cout << "You aimlessly walked in circles, finding yourself back where you started..." << std::endl<< std::endl;
		LocationPtr = oldLocation;
	}
}

//Print Map Function
	//Prints out the game board array with a boundary
	//loops through the game board array and calls the marker function for each space
void Game::printMap()
{
	system ("CLS");									//clear the screen does not work on school compiler :(
	std::cout << std::endl << "\t \t Map" << std::endl;	//labels the map
	std::cout << "   -------------------------------- " << std::endl; //border
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (j==0)
			{
				std::cout << "   |";					//border
			}
			if (Board[i][j] == 0)						//if there was an error and the array is empty, print out a space
			{
				std::cout << " ";		
			}
			else if (Board[i][j] == LocationPtr)		//print out an X at the location pointer (character's current location)
			{
				std::cout << " X ";
			}
			else 										
			{
				std::cout << Board[i][j]->getMarker();	//place the character sign of the object in the appropriate place
			}
			if (j==9)									//border
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "   -------------------------------- "<< std::endl; //border
	std::cout << "Key: \t?=Unknown  X=You  B=Base"<< std::endl; //key
	std::cout << "\tC=Crevasse  R=Remains  G=Goal" << std::endl<< std::endl; //key
	std::cout << "Health: " << User.getHealth() << std::endl; //display the current character health
	User.printBag();									//function that prints out the current contents of the character's bag
}

//Set Flag Function
	//loops through the array and sets the discover flag to 1 at the location pointer
void Game::setFlag()
{
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (Board[i][j] == LocationPtr)
			{
				Board[i][j]->setDiscoverFlag();			//sets flag to one even if the flag is already set to one
			}
		}
	}
}

//Check Goal Function
	//checks the location of the character and the inventory for the win scenario
int Game::checkGoal()
{
	if (LocationPtr->getMarker() == " B ")	//Check the current character location to see if they are at the home base
	{
		if (User.checkRadio() == 1)			//if the character is at the home base then check to see if they are carrying the radio
		{
			return 1;						//if they are, the player has won the game and return 1 to signify the win
		}
		else								//else return 0 to continue the game
		{
			return 0;
		}
	}
	else 
	{
		return 0;							//return 0 to continue if the character is not at the home base
	}
}

//Space Effect Function
	//Calls the effect of the current space and stores it in int x
	//Modifies the character health by int x 
void Game::spaceEffect()
{
	int x = LocationPtr->special();			//store the effect of the current character space in x
	if (x == 40)							//if the value is 40, the character is on the remains space and gets a rope item 
	{
		Item* iPtr = new Rope;				//create a rope item
		User.addItem(iPtr);					//add the item to the character inventory
	}
	else if (x == 10)						//if the value is 10, the character is at the goal space
	{
		int check = User.checkRadio();		//check the characters inventory
		if (check == 1)						//if they are already have a radio then print a message and set x to 0 for no space effect
		{
			std::cout << "You already have a radio, get out of there!\n\n";
			x=0;
		}
		else								//add the radio to the inventory if it is not there 
		{
			Item* iPtr = new Radio;			//create the radio
			User.addItem(iPtr);				//add to inventory
		}
	}
	else if (x == -20)						//if the value is -20, the character is on the crevasse space
	{
		int check = User.checkRope();		//check the character to see if they have a rope
		if (check == 1)						//if they do print a message
		{
			std::cout << "You used your rope to escape the Crevasse and not take any damage!\n\n";
			User.removeFirstItem();			//delete a rope from the character inventory (function will only delete a rope item)
			x= 10;							//set x to 10 to indicate they did not recieve damage this day (offsets the beginning 10 decrease for temp effects)
		}
	}
	User.modifyHealth(x);					//modify the character health by the appropriate amount
}
