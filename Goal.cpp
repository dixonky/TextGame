/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Goal class implementation

* ****************************************************************************/
#include "Goal.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Goal::Goal()
{
	type = "Goal";
	description = "Safety";  //not used
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	discoverFlag = 1;
}

//Get Functions
//
std::string Goal::getDescription()
{
	return description;
}

std::string Goal::getType()
{
	return type;
}

std::string Goal::getMarker()
{
	if (discoverFlag == 0)
	{
		return " ? ";
	}
	else
	{
		return " G ";	
	}
}

//Special Function
//
int Goal::special()
{
	std::cout << "You found the Radio!!\nMake it back to Base!" << std::endl<< std::endl;
	return 10;

}

