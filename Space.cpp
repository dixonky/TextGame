/*******************************************************************************
* ** Author: Kyle Dixon
* ** Date: 11-24-2018
* ** Descriptions: Space class implementation

* ****************************************************************************/

#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "Space.hpp"

//default constructor
Space::Space()
{
	
}

//Set Pointer Functions
void Space::setTop(Space* Old)
{
	top = Old;
}

void Space::setRight(Space* Old)
{
	right = Old;
}

void Space::setLeft(Space* Old)
{
	left = Old;
}

void Space::setBottom(Space* Old)
{
	bottom = Old;
}

//Go Pointer Functions
Space* Space::goTop()
{
	return top;
}
Space* Space::goRight()
{
	return right;
}
Space* Space::goLeft()
{
	return left;
}
Space* Space::goBottom()
{
	return bottom;
}

//Set Discover Flag Function
void Space::setDiscoverFlag()
{
	discoverFlag = 1;
}

void Space::setDiscoverFlag(int x)
{
	discoverFlag = x;
}
