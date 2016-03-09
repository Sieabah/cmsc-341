/**************************************************************
* File:    Driver.cpp
* Project: CMSC 341 - Project 4 - Hashing
* Author : Christopher Sidel
* Date   : 11/17/2014
* Section: Lecture-01
* E-mail: csidell1@umbc.edu
*
* Program driver for the hashing simluations
*************************************************************/

#include "QuadraticProbing.h"
#include "DHashTable.h"
#include "LHashTable.h"

#include "Exception.h"
#include "Proj4Aux.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//Print table header
void PrintTitle(ofstream &out, string title, char* size)
{	
	//Create title
	title += " Analysis (Table size = ";
	title += size;
	title += ")";

	//Print out to given stream
	out << fixed;
	out << setw(58);
	out << title << endl;
	out << setw(28) << "--- Inserts ---" 
		<< setw(24) << " ------- Probes -------"
		<< " ----- Clusters -------" << endl;
	out << setw(2) << "N " << setw(8)
		<< " lambda"  << setw(9)
		<< " success" << setw(8)
		<< " failed" << setw(8)
		<< " total" << setw(8)
		<< " avg" << setw(8)
		<< " max" << setw(8)
		<< " number" << setw(8)
		<< " avg" << setw(8)
		<< " max" << setw(8)
		<< endl;
}

//Run simulation
void RunProject(int argc, char* argv[])
{
	//Check if file exists
	if(!Util::FileExists(argv[1]))
	{
		throw Exceptions("File does not exist!");
	}

	std::ofstream resultFile;
	resultFile.open("results.txt");

	//Define the input file
	std::ifstream file;

	//Open file given
	file.open(argv[1]);

	//Define line
	std::string line;

	//Get and split numbers
	getline(file,line);
	std::stringstream ssin(line);

	//Proj4.out $(FILE) $(N) $(INTERVAL) $(M) $(R)
	//argv[1] - name of file with random integers
	//argv[2] - total number of integers to attempt to insert
	//argv[3] - interval - number of attempted insertions
	//argv[4] - size of hash table
	//argv[5] - largest prime less than M

	/*
	
	After inserting interval integers, results.txt will have
		total number of attempted insertions
		value of lambda (successful insertions/table size)
		total number of probes so far
		The average number of probes needed to insert an integer into hash table
		Maximum number of probes needed to insert
		The number of successful insertions
		number of uncessful insertion attempts
		number of clusters in the hash table
			cluster being one or more consecutive occupied slots in hash table
		maximum cluster size in each table
		average cluster size in each table
	
	*/

	//For simplicity get all the numbers into a vector
	vector<int> numbers;
	for(int i = 0; i < atoi(argv[2]); i++)
	{
		if(!ssin.good())
		{
			throw Exceptions("Not enough random numbers!");
		}

		std::string temp;
		ssin >> temp;

		numbers.push_back(atoi(temp.c_str()));
	}

	file.close();

	//Pass fail structure
	struct PassFail
	{
		int pass;
		int fail;
	};

	//Linear Probing

	resultFile << fixed << setprecision(2);

	PrintTitle(resultFile,"Linear Probing",argv[4]);

	int bigClust = 0;
	double avgClust = 0;
	for (int i = atoi(argv[3]); i <= atoi(argv[2]); i+=atoi(argv[3]))
	{
		LHashTable<int> *ltble = new LHashTable<int>(atoi(argv[4]));

		PassFail lin;
		lin.pass = lin.fail = 0;
		for (int j = 0; j < i; ++j)
		{
			//Try to insert
			try
			{
				ltble->insert(numbers[j]);
				lin.pass++;
			}
			catch(NoPositionAvailable &e)
			{
				lin.fail++;
			}
		}
		//Print row from data gathered
		resultFile << setw(2) << i << setw(8)
		<< (double)lin.pass/atoi(argv[4])  << setw(9)
		<< lin.pass << setw(8)
		<< lin.fail << setw(8)
		<< ltble->GetProbeCount() << setw(8)
		<< ltble->GetProbeCount()/(double)i << setw(8)
		<< ltble->MaxProbesForEntry();
		int clust = ltble->NumClusters(bigClust,avgClust);
		resultFile << setw(8)
		<< clust << setw(8)
		<< avgClust << setw(8)
		<< bigClust << setw(8)
		<< endl;

		delete ltble;
	}
		
	/*
		Quadratic Probing
	*/

	PrintTitle(resultFile, "Quadratic Probing",argv[4]);

	bigClust = 0;
	avgClust = 0;
	for (int i = atoi(argv[3]); i <= atoi(argv[2]); i+=atoi(argv[3]))
	{
		QHashTable<int> *qtble = new QHashTable<int>(atoi(argv[4]));

		PassFail lin;
		lin.pass = lin.fail = 0;
		for (int j = 0; j < i; ++j)
		{
			try
			{
				qtble->insert(numbers[j]);
				lin.pass++;
			}
			catch(NoPositionAvailable &e)
			{
				lin.fail++;
			}
		}
		resultFile << setw(2) << i << setw(8)
		<< (double)lin.pass/atoi(argv[4])  << setw(9)
		<< lin.pass << setw(8)
		<< lin.fail << setw(8)
		<< qtble->GetProbeCount() << setw(8)
		<< qtble->GetProbeCount()/(double)i << setw(8)
		<< qtble->MaxProbesForEntry();
		int clust = qtble->NumClusters(bigClust,avgClust);
		resultFile << setw(8)
		<< clust << setw(8)
		<< avgClust << setw(8)
		<< bigClust << setw(8)
		<< endl;

		delete qtble;
	}
		
	/*
		Double Hashing
	*/

	PrintTitle(resultFile, "Double Hashing",argv[4]);

	bigClust = 0;
	avgClust = 0;
	for (int i = atoi(argv[3]); i <= atoi(argv[2]); i+=atoi(argv[3]))
	{
		DHashTable<int> *dtble = new DHashTable<int>(atoi(argv[4]),atoi(argv[5]));

		PassFail lin;
		lin.pass = lin.fail = 0;
		for (int j = 0; j < i; ++j)
		{
			try
			{
				dtble->insert(numbers[j]);
				lin.pass++;
			}
			catch(NoPositionAvailable &e)
			{
				lin.fail++;
			}
		}
		resultFile << setw(2) << i << setw(8)
		<< (double)lin.pass/atoi(argv[4])  << setw(9)
		<< lin.pass << setw(8)
		<< lin.fail << setw(8)
		<< dtble->GetProbeCount() << setw(8)
		<< dtble->GetProbeCount()/(double)i << setw(8)
		<< dtble->MaxProbesForEntry();
		int clust = dtble->NumClusters(bigClust,avgClust);
		resultFile << setw(8)
		<< clust << setw(8)
		<< avgClust << setw(8)
		<< bigClust << setw(8)
		<< endl;

		delete dtble;
	}

	resultFile.close();
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		cout << "Not enough arguments: Proj4.out $(FILE) $(N) $(INTERVAL) $(M) $(R)" << endl;
		return 1;
	}

	try
	{
		RunProject(argc, argv);
	}
	catch (Exceptions &cException) {
        cout << "EXCEPTION: " << cException.GetMessage() << endl;
        return 1;
    }

	return 0;
}