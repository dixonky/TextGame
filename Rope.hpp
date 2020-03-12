/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Rope class header

* ****************************************************************************/
#include "Item.hpp"
#include <string>

//guards against multiple headers
#ifndef ROPE_HPP
#define ROPE_HPP

class Rope: public Item
{
	private:	
		
	public:
		Rope();
		virtual std::string getDescription();
		virtual std::string getName();

};

//guards against multiple headers
#endif
