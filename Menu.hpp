/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: menu class header 
* **	
* ****************************************************************************/

#include <string>

//guards against multiple headers
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
	public:
		Menu();
		int start();
		int playAgain();
		char cont();
		char input1();
		int input2();
		int input3();
		char enter();
};

//guards against multiple headers
#endif
