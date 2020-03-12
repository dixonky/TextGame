/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Gaol class header

* ****************************************************************************/
#include "Space.hpp"
#include <string>

//guards against multiple headers
#ifndef GOAL_HPP
#define GOAL_HPP

class Goal: public Space
{
	private:	
		
	public:
		Goal();
		virtual std::string getDescription();
		virtual std::string getType();
		virtual std::string getMarker();
		int special();
};

//guards against multiple headers
#endif
