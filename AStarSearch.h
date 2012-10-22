#ifndef ASTARSEARCH_H_
#define ASTARSEARCH_H_

#include "SearchAlgorithm.h"
#include "GeneralSearch.h"
#include "PriorityQueueAdapter.h"

typedef double (*heuristic)(const State&);

struct NodeCompare
{
public:
	NodeCompare(heuristic h) : h_(h){}

	bool operator()(const Node* l, const Node* r) const
	{
		return h_(l->state()) > h_(r->state());
	}

private:
	heuristic h_;
};

class AStarSearch : public SearchAlgorithm
{
public:
	AStarSearch(heuristic h) : h_(h){}

	const Node* Search(const Problem &problem) const
	{
		NodeCompare node_compare(h_);
		return GeneralSearch::graphSearch(problem, PriorityQueueAdapter<const Node*, NodeCompare>(node_compare));
	}

private:
	heuristic h_;
};

#endif
