/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Remains class header

* ****************************************************************************/
#include "Space.hpp"
#include <string>

//guards against multiple headers
#ifndef REMAINS_HPP
#define REMAINS_HPP

class Remains: public Space
{
	private:	
		
	public:
		Remains();
		virtual std::string getDescription();
		virtual std::string getType();
		virtual std::string getMarker();
		int special();
};

//guards against multiple headers
#endif
