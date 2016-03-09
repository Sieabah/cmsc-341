/*****************************************
** File:    ThreeDimension.h
** Project: CMSC 341 Homework 1, Fall 2014
** Author:  Christopher S Sidell
** Date:    9/5/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
**   This file contains the class definition of ThreeDimension
**		Contains the extension upon TwoDimension
**
***********************************************/

#ifndef THREEDIMENSION_H
#define THREEDIMENSION_H

#include "TwoDimension.h"
#include <iostream>

class ThreeDimension : public TwoDimension
{
protected:
	//Z variable
	double z;
public:
	//-------------------------------------------------------
	// Name: ThreeDimension (no-arg)
	// PreCondition:  None
	// PostCondition: Object is created
	//---------------------------------------------------------
	ThreeDimension();

	//-------------------------------------------------------
	// Name: ThreeDimension
	// PreCondition:  All values are given
	// PostCondition: Object with given values is created
	//---------------------------------------------------------
	ThreeDimension(double i, double j, double k);

	//-------------------------------------------------------
	// Name: SetZ
	// PreCondition: value is given
	// PostCondition: z will have given value
	//---------------------------------------------------------
	void SetZ(double NewZ);

	//-------------------------------------------------------
	// Name: GetZ
	// PreCondition: Z is defined
	// PostCondition: current z is returned
	//---------------------------------------------------------
	double GetZ() const;

	//-------------------------------------------------------
	// Name: DisplayPoints
	// PreCondition: Size is correct length of array
	// PostCondition: Prints all points in array given
	//---------------------------------------------------------
	static void DisplayPoints(ThreeDimension **arr, int size);

	//-------------------------------------------------------
	// Name: SameXYZ
	// PreCondition: Size is correct length of array 
	// PostCondition: returns null if no match found
	//---------------------------------------------------------
	static ThreeDimension* SameXYZ(ThreeDimension **arr, int size);
};

/****************************************************************
* Name: Operator<<
*    Print out three dimension
* Preconditions:
*   dim is defined
* Postconditions:
*   Returns ostream
****************************************************************/
std::ostream& operator<< (std::ostream& out, const ThreeDimension& dim);

#endif