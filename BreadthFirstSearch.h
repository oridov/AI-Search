#ifndef BREADTHFIRSTSEARCH_H_
#define BREADTHFIRSTSEARCH_H_

#include "SearchAlgorithm.h"
#include "GeneralSearch.h"
#include "QueueAdapter.h"

class BreadthFirstSearch : public SearchAlgorithm
{
public:
	const Node* Search(const Problem &problem) const
	{
		return GeneralSearch::graphSearch(problem, QueueAdapter<const Node*>());
	}
};

#endif
