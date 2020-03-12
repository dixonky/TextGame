/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: main function for the tundra game (final project CS 162)
* **
* ****************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "Game.hpp"
#include "Menu.hpp"

int main()
{
	Menu menu;								//create menu object
	int choice = menu.start();				//get user choiceto start program
	while (choice != 0)						
	{	
		Game();								//runs the tundra program
		choice = menu.playAgain();			//asks user to play again
	}
	return 0;	
}
