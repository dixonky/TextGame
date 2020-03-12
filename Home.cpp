/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Home class implementation

* ****************************************************************************/
#include "Home.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Home::Home()
{
	type = "Home Base";
	description = "Your Base";  //not used
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	discoverFlag = 1;
}

//Get Functions
//
std::string Home::getDescription()
{
	return description;
}

std::string Home::getType()
{
	return type;
}

std::string Home::getMarker()
{
	return " B ";
}

//Special Functions
//
int Home::special()
{
	std::cout << "You entered your home base" << std::endl << std::endl;
	return 05;
}
