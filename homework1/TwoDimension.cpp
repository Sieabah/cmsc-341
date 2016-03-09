/*****************************************
** File:    TwoDimension.h
** Project: CMSC 341 Homework 1, Fall 2014
** Author:  Christopher S Sidell
** Date:    9/5/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
**   This file contains the class implementation of TwoDimension
**
***********************************************/

#include "TwoDimension.h"

//TwoDimension
//Default constructor
TwoDimension::TwoDimension()
{} 

//TwoDimension
//Create point at given values
TwoDimension::TwoDimension(double i, double j)
:x(i), y(j)
{} 
	
//SetX
//Set X variable
void TwoDimension::SetX(double NewX)
{
	x = NewX;
}

//SetY
//Set Y variable
void TwoDimension::SetY(double NewY)
{
	y = NewY;
}

//GetX
//Return X variable
double TwoDimension::GetX() const 
{
	return x;
}

//GetY
//Return Y variable
double TwoDimension::GetY() const 
{
	return y;
}