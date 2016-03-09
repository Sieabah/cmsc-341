#ifndef STACK_H
#define STACK_H

#include <deque>

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(T* elm);
	T* Pop();
	bool Empty();
	int Size();
private:
	std::deque<T*> m_stack;
};

#include "Stack.cpp"

Stack<int> non();

#endif