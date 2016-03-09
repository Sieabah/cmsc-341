/*****************************************
** File:    
** Project: CMSC 341 Project 2, Fall 2014
** Author:  Christopher S Sidell
** Date:    10/20/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Word class implementation
**
***********************************************/

#include "Word.h"
#include <cmath>

//Word (no arg constructor)
//Default constructor
Word::Word()
{}

//Word
//Take in word and starting line number
Word::Word(std::string inWord, int lineNumber)
{
	m_wordText = inWord;
	m_lineNumbers.push(lineNumber);
}

//CountWord
//Add count of word at line
void Word::CountWord(int lineNumber)
{
	//Increment word's occurence
	m_count++;

	//Check previous input for equality, no need to check more than that
	//	the reason is we're never going down the line number, only up
	if(m_lineNumbers.back() != lineNumber)
	{
		//Add value to queue
		m_lineNumbers.push(lineNumber);
	}
}

//GetWord
//Returns the word that the word is
std::string Word::GetWord() const
{
	return m_wordText;
}

//GetQueue
//Returns 
std::queue<int> Word::GetQueue() const
{
	return m_lineNumbers;
}

//operator<
//Checks if left side is less than right side
bool Word::operator<(const Word &RHS) const
{
	return GetWord().compare(RHS.GetWord()) < 0;
}

//SetWord
//Sets string to new word
void Word::SetWord(std::string word)
{
	m_wordText = word;
}

//operator=
//sets word equal to right side
Word Word::operator=(const Word &RHS)
{
	//Copy the word over
	SetWord(RHS.GetWord());

	//Time to make sure we have all the lines
	std::queue<int> lines = RHS.GetQueue();

	//Get rid of all the previous lines
	for (unsigned int i = 0; i < m_lineNumbers.size(); i++)
	{
		m_lineNumbers.pop();
	}

	//Add all from other list
	for (unsigned int i = 0; i < lines.size(); ++i,lines.pop())
	{
		m_lineNumbers.push(lines.front());
	}

	return *this;
}

//Operator==
//Check equality operator
bool Word::operator==(Word &RHS)
{
	return GetWord().compare(RHS.GetWord()) == 0;
}

//operator<<
//Stream append operator
std::ostream& operator<< (std::ostream& out, const Word& wordy)
{
	std::queue<int> lines = wordy.GetQueue();

	int wordSize = wordy.GetWord().size();

	//calculate the number of digits in the frequency
	unsigned int digits = lines.size() > 0 ? 
		(int) (log10 ((double) lines.size())) + 1: 1;

	//Print formating of fraction
	out << wordy.GetWord();

	if(lines.front() != 0)
	{
		//For gap in space
		for (unsigned int i = 0; i < 25-(wordSize+digits); ++i)
		{
			out << ".";
		}
		out	<< lines.size()
			<< ":" 
			<< " ";


		for (; !lines.empty() ; lines.pop())
		{
			out << lines.front() << " ";
			
		}
	}

	return out;
}