template<class T>
Stack<T>::Stack()
{

}

template<class T>
Stack<T>::~Stack()
{

}

template<class T>
void Stack<T>::Push(T* elm)
{
	m_stack.push_back(elm);
}

template<class T>
T* Stack<T>::Pop()
{
	T* n = m_stack.front();
	m_stack.pop_front();
	return n;
}

template<class T>
bool Stack<T>::Empty()
{
	return m_stack.size() <= 0;
}

template<class T>
int Stack<T>::Size()
{
	return m_stack.size();
}

