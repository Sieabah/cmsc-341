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
	map<string, int> mep;
	string val;

	cin >> val;

	unsigned int length = 0;
	while(length < val.size())
	{
		cout << "Substr Length: " << length << endl;
		for (unsigned int i = 0; i+length <= val.size(); ++i)
		{	
			string str = val.substr(i,length);
			cout << "\tstring: '" << str << "'" << "(" << i << "," << length << ")" << endl;
			if(str == "")
			{
				cout << "\t\tSkipping: (" << str << ")" << endl;
				continue;
			}

			if(!mep[str] && mep[str] != 0)
			{
				cout << "\t\tAdd new elm (" << str << ") = 1" << endl;
				mep[str] = 1;	
			}
			else
			{
				++mep[str];
				cout << "\t\tIncrement Map Value (" << str << 
				")" << "val: " << mep[str] << endl;
			}
		}	

		length++;
	}

	for (map<string,int>::iterator it=mep.begin(); it!=mep.end(); ++it)
    {
    	cout << it->first << " " << it->second << endl;
    }
    

	return 0;
}