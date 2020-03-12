/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Radio class header

* ****************************************************************************/
#include "Item.hpp"
#include <string>

//guards against multiple headers
#ifndef RADIO_HPP
#define RADIO_HPP

class Radio: public Item
{
	private:	
		
	public:
		Radio();
		virtual std::string getDescription();
		virtual std::string getName();

};

//guards against multiple headers
#endif
