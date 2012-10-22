#ifndef GENERALSEARCH_H_
#define GENERALSEARCH_H_

#include <set>
#include "Problem.h"
#include "Node.h"
#include "SimpleQueue.h"

class GeneralSearch
{
public:
	// todo: consider changing to static
	static const Node* treeSearch(const Problem &problem, SimpleQueue<const Node*> &fringe);
	static const Node* graphSearch(const Problem &problem, SimpleQueue<const Node*> &fringe);

private:
	static void expand(const Node &node, const Problem &problem, list<const Node*> &out);
};

#endif
