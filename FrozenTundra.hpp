/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Frozen Tundra class header

* ****************************************************************************/
#include "Space.hpp"
#include <string>

//guards against multiple headers
#ifndef FROZENTUNDRA_HPP
#define FROZENTUNDRA_HPP

class FrozenTundra: public Space
{
	private:	
		
	public:
		FrozenTundra();
		virtual std::string getDescription();
		virtual std::string getType();
		virtual std::string getMarker();
		int special();
};

//guards against multiple headers
#endif

