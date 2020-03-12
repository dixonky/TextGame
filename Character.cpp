/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Character class implementation 

* ****************************************************************************/
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "Character.hpp"
#include "Menu.hpp"
#include "Item.hpp"
#include "Rope.hpp"

//default constructor
	//sets base values
Character::Character()
{
	health = 100;
	itemCount = 0;
	head = NULL;
}

//Modify Health Function
	//Adds the passed integer to the health of the character
void Character::modifyHealth(int x)
{
	health = health + x;
}

//Get Health Function
	//returns the health of the character
int Character::getHealth()
{
	return health;
}

//is Empty Function
	//returns true if the bag is empty
bool Character::isEmpty()
{
	if (head == NULL)						
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Add Item Function
	//Adds the item at the passed pointer to the bag structure
void Character::addItem(Item* ItemPtr)
{
	if (itemCount > 2)							//if there are 3 or more items in the bag, print a message
	{
		std::cout << "You have filled your bag \nTo add another item you must first remove an item" << std::endl;
		Menu menu;
		int x = menu.input2();					//ask the user if they want to remove a rope from their bag to add the new item
		if (x == 1)
		{
			Character::removeFirstItem();		//remove the first item
			Character::addItem(ItemPtr);		//add the new item to the back of the bag
		}
	}
	else
	{
		if (Character::isEmpty())				//if the bag is empty, add the item and set it as the head
		{
			head = new Bag(ItemPtr);			//add item to the bag
			head -> next = head;				//set the head pointers
			head -> prev = head;
			itemCount++;						
		}
		else									//if there are 1 or 2 items in the bag, add the item and set the pointers
		{
			Bag* temp = new Bag(ItemPtr);		
			Bag* ptr;							
			ptr = head -> prev;					
			head -> prev = temp;				
			temp -> next = head;			
			temp -> prev = ptr;					
			ptr -> next = temp; 
			itemCount++;
		}
	}
}

//Print Bag Function
	//Prints the contents of the bag
void Character::printBag()
{
	Bag *Ptr = head;									//set the point at the head of the bag
	std::cout << "Bag: ";
	if (Character::isEmpty())							//if the bag is empty, print empty
	{
		std::cout << "Empty" << std::endl;
	}
	else												//if there are items in the bag
	{
		do {
			std::string n = Ptr->item1-> getName();		//print out the name of the item
			std::cout << n << " ";
			Ptr = Ptr->next;							//cycle to the next item
		}
		while (Ptr != head);							//cycle through the items until back at the beginning
		std::cout << std::endl;
	}
}

//Remove First Item Function
	//Removes the first item from the bag, unless it is a radio then it moves the radio and repeats
void Character::removeFirstItem()
{
	Bag *Ptr = head;						//set a pointer at the head of the bag
	if(Ptr->item1->getName() == "Radio")	//if that item is the radio then set the head as the next item in the bag
	{
		head = head->next;
	}
	
	if (head->next == head)					//if there is only one item, delete it and set the pointers to null
	{
		Bag* tempHead;
		tempHead = head;
		delete tempHead;
		head = NULL;
		itemCount--;
	}

	else									//if there are more than 1 items than remove the first item from the bag and reform the bag
	{
		Bag* tempLast;			
		Bag* tempHead;			

		tempLast = head->prev;	
		tempHead = head;		
		head = head->next;		
		delete tempHead;
		tempLast->next = head;		
		head->prev = tempLast;
		itemCount--;
	}
}

//Check Radio Function
	//Cycles through the bag, checking items
	//returns 1 if there is a radio in the bag
int Character::checkRadio()
{
	int check = 0;									//set the check int (flag) as zero (item not present)
	Bag *Ptr = head;
	if (Character::isEmpty())						//return 0 if the bag is empty
	{
		return check;
	}
	else
	{
		do {
				if (Ptr->item1->getName()== "Radio")
				{
					check = 1;						//return 1 if there is a radio in the bag
				}	
				Ptr = Ptr->next;					//set the pointer to the next item in the bag
			} while (Ptr != head);
	}
	return check;
}

//Check Rope Function
	//Cycles through the bag, checking items
	//returns 1 if there is a rope in the bag
int Character::checkRope()
{
	int check = 0;									//set the check int (flag) as zero (item not present)
	Bag *Ptr = head;
	if (Character::isEmpty())						//return 0 if the bag is empty
	{
		return check;
	}
	else
	{
		do {
				if (Ptr->item1->getName()== "Rope")
				{
					check = 1;						//return 1 if there is a radio in the bag
				}	
				Ptr = Ptr->next;					//set the pointer to the next item in the bag
			} while (Ptr != head);
	}
	return check;
}
