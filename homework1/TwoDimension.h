/*****************************************
** File:    TwoDimension.h
** Project: CMSC 341 Homework 1, Fall 2014
** Author:  Christopher S Sidell
** Date:    9/5/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
**   This file contains the class definition of TwoDimension
**
***********************************************/

#ifndef TWODIMENSION_H
#define TWODIMENSION_H

class TwoDimension
{
   protected:
   	//X and Y coordinates
   	double x, y; 
   public: 
   	//-------------------------------------------------------
	// Name: TwoDimension (no-arg)
	// PreCondition:  None
	// PostCondition: Object created
	//---------------------------------------------------------
    TwoDimension();

    //-------------------------------------------------------
	// Name: TwoDimension
	// PreCondition:  i, j are defined
	// PostCondition: Object with values is created
	//---------------------------------------------------------
	TwoDimension(double i, double j);
	
	//-------------------------------------------------------
	// Name: SetX
	// PreCondition: NewX is defined
	// PostCondition: X has will have new value
	//---------------------------------------------------------
	void SetX(double NewX);

	//-------------------------------------------------------
	// Name: SetY
	// PreCondition: NewY is defined
	// PostCondition: Y has will have new value
	//---------------------------------------------------------
	void SetY(double NewY);

	//-------------------------------------------------------
	// Name: GetX
	// PreCondition: X is defined
	// PostCondition: returns current value of X
	//---------------------------------------------------------
	double GetX() const;

	//-------------------------------------------------------
	// Name: GetY
	// PreCondition: Y is defined
	// PostCondition: returns current value of Y
	//---------------------------------------------------------
	double GetY() const;
};

#endif