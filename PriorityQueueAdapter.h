#ifndef PRIORITYQUEUEADAPTER_H_
#define PRIORITYQUEUEADAPTER_H_

#include "SimpleQueue.h"

using namespace std;

template <class T, class Compare = std::less<T>>
class PriorityQueueAdapter : public SimpleQueue<T>, public std::priority_queue<T, vector<T>, Compare>
{
public:
	// add evaluation function to arguments
	PriorityQueueAdapter(void){}
	PriorityQueueAdapter(Compare &predicate) : priority_queue<T, vector<T>, Compare>(predicate) {}
	~PriorityQueueAdapter(void){}

	bool empty() const
	{
		return priority_queue<T, vector<T>, Compare>::empty();
	}
	// this function is written so it can support raw type like int
	void insert(T &&elem)
	{
		insert(elem);
	}
	void insert(T &elem)
	{
		priority_queue<T, vector<T>, Compare>::push(elem);
	}
	T removeFirst()
	{
		T top = priority_queue<T, vector<T>, Compare>::top();
		priority_queue<T, vector<T>, Compare>::pop();
		return top;
	}
};

#endif