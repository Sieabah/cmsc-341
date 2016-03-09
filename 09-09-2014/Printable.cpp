/*****************************************
** File:    InClass.cpp
** Project: CMSC 341 In Class Assignment, Fall 2014
** Author:  Christopher Sidell
** Date:    9/11/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	Map Example
**
**
***********************************************/
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
	map<string, int> myMap;
	string val;

	cin >> val;

	unsigned int length = 0;
	//Go through getting all string subsets
	while(length < val.size())
	{
		//For all subsets of set length
		for (unsigned int i = 0; i+length <= val.size(); ++i)
		{	
			//Capture it
			string str = val.substr(i,length);
			//Skip blank
			if(str == "")
				continue;

			if(!myMap[str] && myMap[str] != 0)
				myMap[str] = 1;	//Create it if it doesn't exist
			else
				++myMap[str]; //Increment it if it does
		}	
		//One higher length
		length++;
	}
	//Print all subsets from the map
	for (map<string,int>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
    	cout << it->first << " " << it->second << endl;
	return 0;
}