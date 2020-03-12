/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Rope class header

* ****************************************************************************/
#include "Rope.hpp"
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

//default constructor
Rope::Rope()
{
	type = "Rope";
	description = "A length of old, fraying rope";  //not used
}

//Get Functions
std::string Rope::getDescription()
{
	return description;
}

std::string Rope::getName()
{
	return type;
}
