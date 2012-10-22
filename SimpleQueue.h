#ifndef SIMPLEQUEUE_H_
#define SIMPLEQUEUE_H_

template <class T>
class SimpleQueue
{
public:
	virtual bool empty() const = 0;
	virtual void insert(T &elem) = 0;
	virtual T removeFirst() = 0;
	
	// learn how to do it
	//void insertAll(
	
	
	template<typename Iter>
	void insertAll(Iter first, Iter last)
	{
		for (;first != last; ++first)
			insert(*first);
	}
};

#endif