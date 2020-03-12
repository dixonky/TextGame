/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Space class header 

* ****************************************************************************/

#include <string>

//guards against multiple headers
#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:	
		std::string description;					//string description of character (not used)
		std::string type;							//name of the space 
		char marker;								//marker for the map
		Space* top; 								//pointers that connect the space to other adjacent game board spaces
		Space* left; 
		Space* right; 
		Space* bottom;
		int discoverFlag; 							//0=space has not been found, 1=space has been found
		
	public:
		Space();									//default constructor (never initiated)
		virtual std::string getDescription() = 0;
		virtual std::string getType() = 0;
		virtual std::string getMarker() = 0;
		virtual int special() = 0;
		void setTop(Space*);						//sets the passed pointer to the top pointer
		void setLeft(Space*);
		void setRight(Space*);
		void setBottom(Space*);
		Space* goTop();								//returns the top pointer 
		Space* goLeft();
		Space* goRight();
		Space* goBottom();
		void setDiscoverFlag();						//sets the discover flag to 1
		void setDiscoverFlag(int);					//sets the discover flag to the passed in integer
};

//guards against multiple headers
#endif


