/**************************************************************
 * File:    DHashTable.h
 * Project: CMSC 341 - Project 4 - Hash Tables
 * Author : Christopher S Sidell
 * Date   : 18-November-2014
 * Section: Lecture-01
 * E-mail:  csidell1@umbc.edu
 *
 * Double hashing hash table implementation
 *************************************************************/

#ifndef DOUBLE_PROBING_H
#define DOUBLE_PROBING_H

#include <vector>
#include <string>
#include "HashTable.h"

using namespace std;

// DoubleHashing Hash table class
//h(K,I) = (h(K)+I * h_2(K) )modM
//h_2 (K) = R - (K mod R)
// CONSTRUCTION: an approximate initial size or default of 101

template <typename HashedObj>
class DHashTable : public HashTable<HashedObj>
{
private:
	int m_R;
public:
	explicit DHashTable(int size = 101, int largestPrime=97) : 
		HashTable<HashedObj>( size )
	{
		m_R = largestPrime;
	}

	
	//h(K,I) = (h(K)+I * h_2(K) )modM
	virtual int firstHash(int hash) const
	{
		return hash;
	}
	
	//h_2 (K) = R - (K mod R)
	virtual int secondHash(int hash) const
	{
		return (m_R - (hash % m_R));
	}

	virtual int findPos(const HashedObj & x)
	{
		unsigned int currentPos = firstHash(myhash(x));
		int hashOffset = secondHash(x);

		const unsigned int firstHash = currentPos;

		HashTable<HashedObj>::IncrementProbe();

		// Assuming table is half-empty, and table length is prime,
		// this loop terminates
		while (HashTable<HashedObj>::array[currentPos].info != HashTable<HashedObj>::EMPTY &&
			HashTable<HashedObj>::array[currentPos].element != x)
		{
			HashTable<HashedObj>::IncrementProbe();

			currentPos += hashOffset;  // Compute ith probe

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
