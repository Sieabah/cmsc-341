/**************************************************************
 * File:    HashTable.h
 * Project: CMSC 341 - Project 4 - Hash Tables
 * Author : Christopher S Sidell
 * Date   : 18-November-2014
 * Section: Lecture-01
 * E-mail:  csidell1@umbc.edu
 *
 * Generalized hash table, abstract class cannot be directly created
 *************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
public:
	explicit HashTable(int size = 101) : array(size)
	{
		makeEmpty();
		probes = maxProbe  = 0;
	}

	bool contains(const HashedObj & x) const
	{
		return isActive(findPos(x));
	}

	void makeEmpty()
	{
		currentSize = 0;
		for (unsigned int i = 0; i < array.size(); i++)
			array[i].info = EMPTY;
	}

	bool insert(const HashedObj & x)
	{
		const int probNow = probes;
		try
		{
			// Insert x as active
			int currentPos = findPos(x);
			if (isActive(currentPos))
				return false;

			array[currentPos] = HashEntry(x, ACTIVE);
		}
		//If it fails, still count calculate max probe
		catch(NoPositionAvailable &e)
		{
			if((probes - probNow) > maxProbe)
			{
				maxProbe = probes - probNow;
			}
			//rethrow to driver
			throw NoPositionAvailable();
			return false;
		}

		if((probes - probNow) > maxProbe)
		{
			maxProbe = probes - probNow;
		}
		return true;
	}

	bool remove(const HashedObj & x)
	{
		int currentPos = findPos(x);
		if (!isActive(currentPos))
			return false;

		array[currentPos].info = DELETED;
		return true;
	}

	enum EntryType { ACTIVE, EMPTY, DELETED };

	int nextPrime(int n)
	{
		if (n <= 0)
			n = 3;

		if (n % 2 == 0)
			n++;

		for (; !isPrime(n); n += 2)
			;

		return n;
	}

	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;

		if (n == 1 || n % 2 == 0)
			return false;

		for (int i = 3; i * i <= n; i += 2)
			if (n % i == 0)
				return false;

		return true;
	}

	int GetProbeCount()
	{
		return probes;
	}

	int NumClusters(int &bigCluster, double &avgClust)
	{
		int clusterLength = 0;
		int clusterAmount = 0;

		double avg = 0;

		bool inCluster = false;

		for (unsigned int i = 0; i < array.size(); ++i)
		{
			if(array[i].info == ACTIVE && inCluster == false)
			{
				inCluster = true;

				clusterAmount++;
				clusterLength = 1;

				if(bigCluster == 0)
				{
					bigCluster = clusterLength;
				}
			} 
			else if (array[i].info == ACTIVE && inCluster == true)
			{
				clusterLength++;
			} 
			else if((array[i].info == DELETED || array[i].info == EMPTY) && inCluster == true)
			{
				inCluster = false;
				avg += clusterLength;
			}

			if (clusterLength >= bigCluster)
			{
				bigCluster = clusterLength;
			}
		}

		if(clusterLength == (int)array.size())
		{
			avg += clusterLength;
		}

		avgClust = avg / clusterAmount;
		return clusterAmount;
	}

	int MaxProbesForEntry()
	{
		return maxProbe;
	}
protected:
	int probes;
	int maxProbe;

	void IncrementProbe()
	{
		probes++;
	}

	virtual int findPos(const HashedObj& x) = 0;

	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
			: element(e), info(i) { }
	};

	vector<HashEntry> GetArray()
	{
		return array;
	}

	vector<HashEntry> array;
	int currentSize;

	bool isActive(int currentPos) const
	{
		return array[currentPos].info == ACTIVE;
	}

	virtual int myhash(const HashedObj & x) const
	{
		int hashVal = hashIt(x);

		hashVal %= HashTable<HashedObj>::array.size();
		if (hashVal < 0)
			hashVal += HashTable<HashedObj>::array.size();

		return hashVal;
	}
};

int hashIt(const string & key)
{
	int hashVal = 0;

	for (unsigned int i = 0; i < key.length(); i++)
		hashVal = 37 * hashVal + key[i];

	return hashVal;
}

int hashIt(int key)
{
	return key;
}
#endif
