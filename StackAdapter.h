#ifndef STACKDAPTER_H_
#define STACKDAPTER_H_

#include <stack>
#include "SimpleQueue.h"

template <class T>
class StackAdapter : public SimpleQueue<T>, std::stack<T>
{
public:
	StackAdapter(void){}
	~StackAdapter(void){}

	bool empty() const
	{
		return stack<T>::empty();
	}
	// this function is written so it can support raw type like int
	void insert(T &&elem)
	{
		insert(elem);
	}
	void insert(T &elem)
	{
		stack<T>::push(elem);
	}
	T removeFirst()
	{
		T top = stack<T>::top();
		stack<T>::pop();
		return top;
	}
};

#endif