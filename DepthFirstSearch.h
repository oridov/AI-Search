#ifndef DEPTHFIRSTSEARCH_H_
#define DEPTHFIRSTSEARCH_H_

#include "SearchAlgorithm.h"
#include "GeneralSearch.h"
#include "StackAdapter.h"

class DepthFirstSearch : public SearchAlgorithm
{
public:
	const Node* Search(const Problem &problem) const
	{
		return GeneralSearch::graphSearch(problem, StackAdapter<const Node*>());
	}
};

#endif
