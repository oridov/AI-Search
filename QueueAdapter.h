#ifndef QUEUEADAPTER_H_
#define QUEUEADAPTER_H_

#include <queue>
#include "SimpleQueue.h"

using namespace std;

template <class T>
class QueueAdapter : public SimpleQueue<T>, std::queue<T>
{
public:
	QueueAdapter(void){}
	~QueueAdapter(void){}

	bool empty() const
	{
		return queue<T>::empty();
	}
	// this function is written so it can support raw type like int
	void insert(T &&elem)
	{
		insert(elem);
	}
	void insert(T &elem)
	{
		queue<T>::push(elem);
	}
	T removeFirst()
	{
		T top = queue<T>::front();
		queue<T>::pop();
		return top;
	}
};

#endif