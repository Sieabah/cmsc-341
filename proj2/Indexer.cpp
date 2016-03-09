/*****************************************
** File:    
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Implementation for the indexer class
**
***********************************************/

#include "Indexer.h"
#include "Utility.h"
#include "Word.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

//Indexer
Indexer::Indexer(std::string filterName, std::string dataFile)
{
	//Validate the input files
	if(!FileExists(filterName.c_str()))
	{
		throw Exceptions("Filter file cannot be found!");
	}
	else if(!FileExists(dataFile.c_str()))
	{
		throw Exceptions("Data file cannot be found!");
	}

	m_filterFile = filterName;
	m_dataFile = dataFile;
}

//Complete all the indexing
void Indexer::DoIndex()
{
	//Created filteredBST (stop words)
	m_filteredBST = FileFilterReader(m_filterFile);

	//Build IndexedBST
	m_indexedBST = FileWordReader(m_dataFile);

	OutputResults();
}

//Check if file exists
bool Indexer::FileExists(const char* filename)
{
	//Buffer
	struct stat buffer;   
	//See if anything can be read from the file into the buffer
	return (stat (filename, &buffer) == 0); 
}

//FileFilterReader
//Return filter tree | Read in stop words (gsl.txt)
BinarySearchTree<Word> Indexer::FileFilterReader(std::string filename)
{
	//Define temp tree
	BinarySearchTree<Word> tree;

	//Define the input file
	std::ifstream file;

	//Open file given
	file.open(filename.c_str());

	//Define line
	std::string line;

	//Go through all the lines and put into filter
	while(getline(file,line))
	{
		std::string temp = Utility::Lower(line);

		temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace),
			temp.end());

		tree.insert(temp);
	}

	//Close the file
	file.close();

	return tree;
}

//Return indexed tree
BinarySearchTree<Word> Indexer::FileWordReader(std::string filename)
{
	//Define temp tree
	BinarySearchTree<Word> tree;

	//Define the input file
	std::ifstream file;

	//Open file given
	file.open(filename.c_str());

	//Define line
	std::string line;

	int lineNum = 1;
	//build case insensitive list
	while(getline(file,line))
	{
		std::stringstream ssin(line);
		//store line number where the word appears
			
		while(ssin.good())
		{
			std::string temp;
			ssin >> temp;

			//Get all punctuation
			temp.erase(std::remove_if(temp.begin(), temp.end(), ::ispunct),
				temp.end());

			//make it lowercase
			temp = Utility::Lower(temp);

			//remove all whitespace
			temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace),
				temp.end());

			//Check if it's in the filter list
			if(m_filteredBST.contains(temp) || temp == "\0")
			{
				continue;
			}
			//Check if we already have it
			else if(tree.contains(temp))
			{
				//if we do, increment it
				tree.GetNode(temp)->CountWord(lineNum);
			}
			else
			{
				//stored object (word) hbas to know how many times it appears
				tree.insert(Word(Utility::Lower(temp),lineNum));
			}
		}
		//have line number increment every \n
		lineNum++;
	}

	//Close the file
	file.close();

	return tree;
}

//print resulting indexed tree
void Indexer::OutputResults()
{
	ofstream file;
	//FilteredBST in alphabetical order to "filterResults.txt"	
	file.open("filterResults.txt");
	m_filteredBST.printTree(file);
	file.close();

	
	file.open("indexResults.txt");
	//indexedBST in alphabetical order to "indexResults.txt"
	m_indexedBST.printTree(file);
	
	file.close();
}