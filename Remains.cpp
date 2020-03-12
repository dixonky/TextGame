/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Remains class implementation

* ****************************************************************************/
#include "Remains.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Remains::Remains()
{
	type = "Remains";
	description = "You found frozen remains";  //not used
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	discoverFlag = 0;
}

//Get Functions
//
std::string Remains::getDescription()
{
	return description;
}

std::string Remains::getType()
{
	return type;
}

std::string Remains::getMarker()
{
	if (discoverFlag == 0)
	{
		return " ? ";
	}
	else
	{
		return " R ";	
	}

}

//Special Function
//
int Remains::special()
{
	if (discoverFlag == 0)
	{
		std::cout << "You stumbled across some remains... \nYou gained 30 health and a Rope!!" << std::endl<< std::endl;
		return 40;
	}
	else
	{
		return 0;
	}
}
