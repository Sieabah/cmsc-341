/*****************************************
** File:    MyList.h
** Project: CMSC 341 In Class Assignment, Fall 2014
** Author:  Christopher Sidell
** Date:    9/9/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	MyList class definition
**
**
***********************************************/

#ifndef MYLIST_H
#define MYLIST_H

#include <vector>
#include <iostream>

template<class T>
class MyList
{
	public:
		//-------------------------------------------------------
		// Name: MyList (no-arg)
		// PreCondition:  None
		// PostCondition: List is created
		//---------------------------------------------------------
		MyList();
		
		//-------------------------------------------------------
		// Name: ~MyList
		// PreCondition: None 
		// PostCondition: List is destroyed
		//---------------------------------------------------------
		~MyList();

		//-------------------------------------------------------
		// Name: AddItem
		// PreCondition: Item is of valid template class 
		// PostCondition: Item is added to list
		//---------------------------------------------------------
		void AddItem(T item);

		//-------------------------------------------------------
		// Name: RemoveList
		// PreCondition: List is not empty
		// PostCondition: List pops off end element
		//---------------------------------------------------------
		void RemoveItem();

		//-------------------------------------------------------
		// Name: PrintList
		// PreCondition: List exists
		// PostCondition: None
		//---------------------------------------------------------
		void PrintList();
	private:
		//Vector of elements for ease
		//	Could have used array but used vector for sake of time
		std::vector<T> m_list;
};

#include "MyList.cpp"

MyList<int> ints();
#endif