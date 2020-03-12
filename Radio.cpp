/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Radio class header

* ****************************************************************************/
#include "Radio.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Radio::Radio()
{
	type = "Radio";
	description = "A functioning am/pm radio with microphone";  //not used
}

//Get Functions
std::string Radio::getDescription()
{
	return description;
}

std::string Radio::getName()
{
	return type;
}
