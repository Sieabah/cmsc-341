/*****************************************
** File:    Utility.h
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Holds utility class that manipulates strings
**
***********************************************/

#ifndef UTILITY_H
#define UTILITY_H

#include <string>

class Utility
{
public:
	//-------------------------------------------------------
	// Name: Upper
	// PreCondition:  string is valid
	// PostCondition: word is completely upper
	//---------------------------------------------------------
	static std::string Upper(std::string inString);

	//-------------------------------------------------------
	// Name: Lower
	// PreCondition:  string is valid
	// PostCondition: word is completely lower
	//---------------------------------------------------------
	static std::string Lower(std::string inString);
};
#endif