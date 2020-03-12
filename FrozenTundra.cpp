/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Frozen Tundra class header

* ****************************************************************************/
#include "FrozenTundra.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
FrozenTundra::FrozenTundra()
{
	type = "Frozen Tundra";
	description = "A desolate wasteland of permafrost and nothingness";  //not used
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	discoverFlag = 0;
}

//Get Functions
//
std::string FrozenTundra::getDescription()
{
	return description;
}

std::string FrozenTundra::getType()
{
	return type;
}

std::string FrozenTundra::getMarker()
{
	if (discoverFlag == 0)
	{
		return " ? ";
	}
	else
	{
		return "   ";	
	}

}

//Special Functions
//
int FrozenTundra::special()
{
	std::cout << "You spend the day crossing the desolate tundra" << std::endl<< std::endl;
	return 0;
}
