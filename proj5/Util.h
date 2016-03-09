/**************************************************************
* File:    Util.h
* Project: CMSC 341 - Project 5 - Graph Traversal 
* Author : Christopher Sidell
* Date   : 12/9/2014
* Section: Lecture-01
* E-mail: csidell1@umbc.edu
*

*************************************************************/

#ifndef PROJ4_AUX_H
#define PROJ4_AUX_H

#include <sys/stat.h>
#include <string>

class Util
{
public:
	static bool FileExists(std::string filename)
	{
		//Buffer
		struct stat buffer;   
		//See if anything can be read from the file into the buffer
		return (stat (filename.c_str(), &buffer) == 0); 
	}
};

#endif