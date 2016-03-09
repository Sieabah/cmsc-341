/*****************************************
** File:    
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Word class which holds a string and all lines it occurs on
**
***********************************************/

#ifndef WORD_H
#define WORD_H

#include <queue>
#include <string>
#include <iostream>

class Word
{
public:
	//-------------------------------------------------------
	// Name: Word
	// PreCondition:  None
	// PostCondition: Word is created
	//---------------------------------------------------------
	Word();

	//-------------------------------------------------------
	// Name: Word
	// PreCondition:  word is a valid string, line number > 0 or null
	// PostCondition: Word has line number and is a word
	//---------------------------------------------------------
	Word(std::string inWord, int lineNumber = 0);

	//-------------------------------------------------------
	// Name: CountWord
	// PreCondition:  line number is defined
	// PostCondition: line number is added to queue
	//---------------------------------------------------------
	void CountWord(int lineNumber);

	//-------------------------------------------------------
	// Name: GetWord
	// PreCondition: Word is defined  
	// PostCondition: returns valid word
	//---------------------------------------------------------
	std::string GetWord() const;

	//-------------------------------------------------------
	// Name: GetQueue
	// PreCondition:  Queue exists
	// PostCondition: Returns current queue of the word
	//---------------------------------------------------------
	std::queue<int> GetQueue() const;

	//-------------------------------------------------------
	// Name: operator<
	// PreCondition:  RHS is a word
	// PostCondition: returns correct boolean
	//---------------------------------------------------------
	bool operator<(const Word &RHS) const;

	//-------------------------------------------------------
	// Name: operator=
	// PreCondition:  RHS is a word
	// PostCondition: sets word to RHS word
	//---------------------------------------------------------
	Word operator=(const Word &RHS);

	//-------------------------------------------------------
	// Name: operator==
	// PreCondition:  RHS is a word
	// PostCondition: correct boolean for equality
	//---------------------------------------------------------
	bool operator==(Word &RHS);

private:
	//-------------------------------------------------------
	// Name: SetWord
	// PreCondition:  Sets the strings of the word
	// PostCondition: Word is the new string
	//---------------------------------------------------------
	void SetWord(std::string word);

	//Count of words
	int m_count;
	//All places word appears
	std::queue<int> m_lineNumbers;
	//The word itself
	std::string m_wordText;
};

//-------------------------------------------------------
// Name: operator<<
// PreCondition:  Word is defined
// PostCondition: prints word to 
//---------------------------------------------------------
std::ostream& operator<< (std::ostream& out, const Word& wordy);

#endif