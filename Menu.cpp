/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: menu class implementation 
* **	
* ****************************************************************************/

#include "Menu.hpp"
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

//Default menu constructor
Menu::Menu()
{
	//optionally run start function from here
}

//Start menu function
//checks user input to make sure it is an option
int Menu::start()
{
	int choice;
	cout << "Enter 1 to start Tundra (0 to quit): ";
	cin >> choice;
	
	while (!cin || (choice != 1 && choice != 0))				//input is approved when integer 1 or 0
	{
		cout << "Enter 1 to start the program (0 to quit): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cin >> choice;	
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return choice;
}

//Start menu function
//checks user input to make sure it is an option
int Menu::playAgain()
{
	int choice;
	cout << "Enter 1 to play again! (0 to quit): ";
	cin >> choice;

	while (!cin || (choice != 1 && choice != 0))				//input is approved when integer 1 or 0
	{
	cout << "Enter 1 to play again (0 to quit): ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin >> choice;	
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return choice;
}

//Generic menu function
//checks user input to make sure it is an option
char Menu::input1()
{
	char choice;
	cout << endl << "Enter w to move North \n      d to move East \n      s to move South \n      a to move West \n-> ";
	std::cin.get(choice);
	
	while (!cin || (choice != 'w' && choice != 's' && choice !='a' && choice !='d' ))				//input is approved char w a s or d
	{
		cout << endl << "Enter w to move North \n      d to move East \n      s to move South \n      a to move West \n-> ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		std::cin.get(choice);	
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl; 
	return choice;
}

//Generic menu function
//checks user input to make sure it is an option
char Menu::enter()
{
	char choice;
	cout << "Hit Enter to begin... ";
	std::cin.get(choice);
	while (!cin)												//input is approved when string
	{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Hit Enter to begin... ";
	std::cin.get(choice);
	}
	return choice;
}

//Generic menu function
//checks user input to make sure it is an option
char Menu::cont()
{
	char choice;
	cout << "Hit Enter to continue... ";
	std::cin.get(choice);
	while (!cin)												//input is approved when string
	{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Hit Enter to continue... ";
	std::cin.get(choice);
	}
	return choice;
}

//Generic menu function
//checks user input to make sure it is an option
int Menu::input2()
{
	int choice;
	cout << "Enter 1 to remove a rope from the bag (0 to continue without adding the new item): ";
	cin >> choice;

	while (!cin || (choice != 1 && choice != 0))				//input is approved when integer 1 or 0
	{
	cout << "Enter 1 to remove a rope from the bag (0 to continue without adding the new item): ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin >> choice;	
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return choice;
}

//Generic menu function
//checks user input to make sure it is an option
int Menu::input3()
{
	int choice;
	cout << "Enter 1 to view the location of the goal (0 to continue): ";
	cin >> choice;

	while (!cin || (choice != 1 && choice != 0))				//input is approved when integer 1 or 0
	{
	cout << "Enter 1 to view the location of the goal (0 to continue): ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin >> choice;	
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl;
	return choice;
}
