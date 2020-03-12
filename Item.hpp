/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Item class header 

* ****************************************************************************/

#include <string>

//guards against multiple headers
#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	protected:	
		std::string description;				//string description of character
		std::string type; 
		
	public:
		Item();									//default constructor (never initiated)
		virtual std::string getDescription() = 0;
		virtual std::string getName() = 0;
};

//guards against multiple headers
#endif
