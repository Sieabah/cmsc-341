/*****************************************
** File:    Driver.cpp
** Project: CMSC 341 Homework 1, Fall 2014
** Author:  Christopher S Sidell
** Date:    9/5/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
**   This file contains the main driver program for Homework 1.
**		The contents are a random number generator and driver
**		for the ThreeDimension class
**
***********************************************/

#include "ThreeDimension.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//-------------------------------------------------------
// Name: RandomNumber (double)
// PreCondition:  range is given
// PostCondition: returns a double within given range
//---------------------------------------------------------
double RandomNumber(double range)
{
	return ((double)rand() / RAND_MAX) * (range*2) - range;
}

//-------------------------------------------------------
// Name: RandomNumber (int)
// PreCondition:  range is given
// PostCondition: returns an int within given range
//---------------------------------------------------------
int RandomNumber(int range)
{
	return rand() % (range*2) - range;
}


int main()
{
	//Change this if you want predictable results
	srand (time(NULL));

	//Constants for changing array length and max number
	const int DYN_AMOUNT = 10;
	//Change to double to get doubles
	const int DYN_MAX = 9;

	//#5
	//Create one instance
	ThreeDimension firstPt(3,4,5);
	cout << firstPt;

	//#6
	//Declare array of ThreeDimension objects
	ThreeDimension *points[DYN_AMOUNT];

	//Go through and create all points
	for (int i = 0; i < DYN_AMOUNT; ++i)
	{
		points[i] = new ThreeDimension(
			RandomNumber(DYN_MAX),
			RandomNumber(DYN_MAX),
			RandomNumber(DYN_MAX)
			);
	}

	//#7
	//Display all points
	ThreeDimension::DisplayPoints(points, DYN_AMOUNT);

	//#8
	//See if there are any duplicates
	ThreeDimension* pt = ThreeDimension::SameXYZ(points, DYN_AMOUNT);

	//Check to see if a point was found
	if(pt)
	{
		cout << "Point found!" << endl;
		cout << *pt;
	}
	else
	{
		cout << "point was not found with the same x, y, and z values" << endl;
	}

	return 0;
}