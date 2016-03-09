/*****************************************
** File:    ThreeDimension.cpp
** Project: CMSC 341 Homework 1, Fall 2014
** Author:  Christopher S Sidell
** Date:    9/5/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Contains the implementation of ThreeDimension.
**
***********************************************/

#include "ThreeDimension.h"

//ThreeDimension
//Default constructor
ThreeDimension::ThreeDimension()
{}

//ThreeDimension
//Create object with given values
ThreeDimension::ThreeDimension(double i, double j, double k)
: TwoDimension(i,j), z(k) 
{}

//SetZ
//Sets Z variable
void ThreeDimension::SetZ(double NewZ)
{
	z = NewZ;
}

//GetZ
//Returns Z value
double ThreeDimension::GetZ() const
{
 return z; 
}

//DisplayPoints
//Displays points from given array
void ThreeDimension::DisplayPoints(ThreeDimension **arr, int size)
{
	//Go through array and print point
	for (int i = 0; i < size; ++i)
	{
		std::cout << *arr[i];
	}
}

//SameXYZ
//Checks array to see if any duplicate points exist
ThreeDimension* ThreeDimension::SameXYZ(ThreeDimension **arr, int size)
{
	//Go through array
	for (int i = 0; i < size; ++i)
	{
		if( (arr[i]->GetX() == arr[i]->GetY()) == arr[i]->GetZ() )
		{
			return arr[i];
		}
	}

	//If none found, return NULL
	return NULL;
}

//operator<<
//Stream append operator
std::ostream& operator<< (std::ostream& out, const ThreeDimension& dim)
{
    //Print formating of fraction
    out << "This 3D point has the values of:" << std::endl
    	<< "x: " << dim.GetX() << std::endl
    	<< "y: " << dim.GetY() << std::endl
    	<< "z: " << dim.GetZ() << std::endl
    	<< "---" << std::endl;
    return out;
}
