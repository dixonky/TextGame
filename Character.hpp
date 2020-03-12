/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Character class header 

* ****************************************************************************/

#include <string>
#include "Item.hpp"

//guards against multiple headers
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
	int health;								//holds the current health of the user	
	int itemCount;							//counter to limit the amount of items stored in the bag
	Item* itemPtr;							
	struct Bag								//structure that holds the Item objects
		{
			Item* item1;									
			Bag *next;
			Bag *prev;
			Bag (Item* item2, Bag *next1 = NULL, Bag *prev1 = NULL)
			{
				item1 = item2;
				next = next1;
				prev = prev1;
			}
		};
		Bag *head;
		
	public:
		Character();						//default constructor 
		void modifyHealth(int);				//changes the health integer by the passed in value
		int getHealth();					//returns the health integer
		void addItem(Item*);				//adds the pointed to item to the bag
		bool isEmpty();						//checks the state of the bag
		void printBag();					//prints out the items in the bag
		void removeFirstItem();				//removes the first item of the bag (does not delete the radio)
		int checkRadio();					//checks the bag for the radio item
		int checkRope();					//checks the bag for the rope item
};

//guards against multiple headers
#endif
