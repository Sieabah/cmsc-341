/*****************************************
** File:    Utility.cpp
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Utility class implementation
**
***********************************************/

#include "Utility.h"
#include <locale>
#include <algorithm>

//Upper
//Make string all uppercase
std::string Utility::Upper(std::string inString)
{
	//Make it all uppercase
	std::locale loc;
	for(std::string::size_type i = 0; i<inString.length(); i++)
	{
		//For each letter in string make upper
		inString[i] = std::toupper(inString[i],loc);
	}
	return inString;
}

//Lower
//Make string all lowercase
std::string Utility::Lower(std::string inString)
{
	//Make it all uppercase
	std::locale loc;
	for(std::string::size_type i = 0; i<inString.length(); i++)
	{
		//For each letter in string make lower
		inString[i] = std::tolower(inString[i],loc);
	}
	return inString;
}
