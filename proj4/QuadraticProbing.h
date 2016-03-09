/**************************************************************
 * File:    QuadraticProbing.h
 * Project: CMSC 341 - Project 4 - Hash Tables
 * Author : Christopher S Sidell
 * Date   : 18-November-2014
 * Section: Lecture-01
 * E-mail:  csidell1@umbc.edu
 *
 * Quadratic probing hash table
 *************************************************************/

#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <string>
#include "HashTable.h"

using namespace std;

// QuadraticProbing Hash table class
// h(K,I) = (h(K) + I^2) modM
// CONSTRUCTION: an approximate initial size or default of 101

template <typename HashedObj>
class QHashTable : public HashTable<HashedObj>
{
public:
	explicit QHashTable(int size = 101) : 
		HashTable<HashedObj>( size )
	{}
	
	virtual int findPos(const HashedObj & x)
	{
		int offset = 1;
		unsigned int currentPos = myhash(x);

		const unsigned int firstHash = currentPos;

		HashTable<HashedObj>::IncrementProbe();

		// Assuming table is half-empty, and table length is prime,
		// this loop terminates
		while (HashTable<HashedObj>::array[currentPos].info != HashTable<HashedObj>::EMPTY &&
			HashTable<HashedObj>::array[currentPos].element != x)
		{
			HashTable<HashedObj>::IncrementProbe();

			// h(K,I) = (h(K) + I^2) modM
			currentPos += offset;  // Compute ith probe
			offset += 2;
			if (currentPos >= HashTable<HashedObj>::array.size())
				currentPos -= HashTable<HashedObj>::array.size();

			if(currentPos == firstHash)
			{
				throw NoPositionAvailable();
			}
		}

		return currentPos;
	}
};


#endif
