/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Game class header 
* **	
* ****************************************************************************/

#include "Menu.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "Character.hpp"
//guards against multiple headers
#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	protected:
		Menu menu;								//create menu object to get and validate user input
		Character User;							//Character object to represent the user (keeps track of health and items)
		Space* LocationPtr;						//pointer for the current location on the board
		Space* Board[10][10];					//game board that holds the spaces
		int viewGoalFlag;						//flag for testing, sets the goal to be visable
		
	public:
		Game();									//default constructor
		void createBoard();						//fills the board array with generated spaces
		void linkBoard();						//links the spaces together with pointers
		void deleteBoard();						//deletes the board and spaces
		void Day();								//controls movement, space effects, and checks health/win scenario
		void Move(char);						//changes the current location based on user input
		void printMap();						//prints out the map (and clears the screen)
		void genRanLoc();						//generates the spaces for the board
		void setFlag();							//call to set the current location to discovered
		int checkGoal();						//checks to see if the user has won the game
		void spaceEffect();						//modifies the character health based on the location pointer
};

//guards against multiple headers
#endif
