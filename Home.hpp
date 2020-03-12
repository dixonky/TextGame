/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Home class header

* ****************************************************************************/
#include "Space.hpp"
#include <string>

//guards against multiple headers
#ifndef HOME_HPP
#define HOME_HPP

class Home: public Space
{
	private:	
		
	public:
		Home();
		virtual std::string getDescription();
		virtual std::string getType();
		virtual std::string getMarker();
		int special();
};

//guards against multiple headers
#endif
