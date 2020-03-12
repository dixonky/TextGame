/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Crevasse class header

* ****************************************************************************/
#include "Space.hpp"
#include <string>

//guards against multiple headers
#ifndef CREVASSE_HPP
#define CREVASSE_HPP

class Crevasse: public Space
{
	private:	
		
	public:
		Crevasse();
		virtual std::string getDescription();
		virtual std::string getType();
		virtual std::string getMarker();
		int special();
};

//guards against multiple headers
#endif
