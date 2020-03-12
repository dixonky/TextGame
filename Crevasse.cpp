/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Crevasse class implementation

* ****************************************************************************/
#include "Crevasse.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Crevasse::Crevasse()
{
	type = "Crevasse";
	description = "A deep fissure in the ground";  //not used
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	discoverFlag = 0;
}

//Get Functions
//
std::string Crevasse::getDescription()
{
	return description;
}

std::string Crevasse::getType()
{
	return type;
}

std::string Crevasse::getMarker()
{
	if (discoverFlag == 0)
	{
		return " ? ";
	}
	else
	{
		return " C ";	
	}

}

//Special Functions
//
int Crevasse::special()
{
	std::cout << "You fell down a Crevasse and lost 30 health!!!" << std::endl<< std::endl;
	return -20;
}
