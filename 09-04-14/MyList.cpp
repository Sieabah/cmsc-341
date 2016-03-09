/*****************************************
** File:    MyList.cpp
** Project: CMSC 341 In Class Assignment, Fall 2014
** Author:  Christopher Sidell
** Date:    9/9/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	MyList implementation
**
**
***********************************************/
//MyList(no-arg)
//Default constructor
template<class T>
MyList<T>::MyList()
{}

//~MyList
//Default deconstructor
template<class T>
MyList<T>::~MyList()
{}

//AddItem
//Adds item to end of list
template<class T>
void MyList<T>::AddItem(T item)
{
	m_list.push_back(item);
}

//RemoveItem
//Removes item from end of list
template<class T>
void MyList<T>::RemoveItem()
{
	m_list.pop_back();
}

//PrintList
//Prints the list separated by commas
template<class T>
void MyList<T>::PrintList()
{
	//For all elements in vector
	for (unsigned int i = 0; i < m_list.size(); ++i)
	{
		//Print
		std::cout << m_list[i];
		//print comma if more than one
		if(i+1 < m_list.size())
		{
			std::cout << ", ";
		}
	}
}

