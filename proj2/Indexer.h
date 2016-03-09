/*****************************************
** File:    
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Indexer class takes a file and filter and gives requency of word
**
***********************************************/

#ifndef INDEXER_H
#define INDEXER_H

#include "Word.h"
#include "Exceptions.h"
#include "BinarySearchTree.h"
#include <string>
#include <sys/stat.h>

class Indexer
{
public:
	//-------------------------------------------------------
	// Name: Indexer
	// PreCondition: none  
	// PostCondition: Both filter file and data file exist
	//---------------------------------------------------------
	Indexer(std::string filterName, std::string dataFile);

	//-------------------------------------------------------
	// Name: DoIndex
	// PreCondition: both files exist  
	// PostCondition: Index is completely done
	//---------------------------------------------------------
	void DoIndex();

	//-------------------------------------------------------
	// Name: FileExists
	// PreCondition: filename is a valid char*
	// PostCondition: File exists at location
	//---------------------------------------------------------
	bool FileExists(const char* filename);

	//-------------------------------------------------------
	// Name: FileFilterReader
	// PreCondition:  exists
	// PostCondition: completed tree
	//---------------------------------------------------------
	BinarySearchTree<Word> FileFilterReader(std::string filename);

	//-------------------------------------------------------
	// Name: FileWordReader
	// PreCondition:  exists
	// PostCondition: completed tree
	//---------------------------------------------------------
	BinarySearchTree<Word> FileWordReader(std::string filename);

	//-------------------------------------------------------
	// Name: Output Results
	// PreCondition:  DoIndex has been called
	// PostCondition: none
	//---------------------------------------------------------
	void OutputResults();
private:
	//Trees for all data
	BinarySearchTree<Word> m_filteredBST;
	BinarySearchTree<Word> m_indexedBST;

	//Filenames for relevant files
	std::string m_dataFile;
	std::string m_filterFile;
};

#endif