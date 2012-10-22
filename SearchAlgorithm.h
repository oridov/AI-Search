#ifndef SEARCHALGORITHM_H_
#define SEARCHALGORITHM_H_

#include "Node.h"
#include "Problem.h"

class SearchAlgorithm
{
public:
	virtual ~SearchAlgorithm() {}
	virtual const Node* Search(const Problem&) const = 0;
};

#endif