#include "GeneralSearch.h"

void GeneralSearch::expand(const Node &node, const Problem &problem, list<const Node*> &out)
{
	vector<const ActionState*> legalActions;
	problem.succesorsFunction(node.state(), legalActions);
	vector<const ActionState*>::iterator it;
	const Node* s;

	for (it = legalActions.begin(); it != legalActions.end(); ++it)
	{
		s = new Node((**it).state(), 
			(**it).action(), 
			&node, 
			node.path_cost() + problem.stepCost(node.state(), (**it).action(), (**it).state()), 
			node.depth() + 1);	
		
		out.push_back(s);
	}
}

// todo: revise
const Node* GeneralSearch::treeSearch(const Problem &problem, SimpleQueue<const Node*> &fringe)
{
	const Node* node = new Node(problem.initial_state());
	fringe.insert(node);
	
	while (true)
	{
		if (fringe.empty())
			return 0;

		node = fringe.removeFirst();
		if (problem.isGoalState(node->state()))
			return node;
		
		list<const Node*> expanded;
		expand(*node, problem, expanded);

		// insert all exapnded to fringe
		list<const Node*>::iterator it;
		for (it = expanded.begin(); it != expanded.end(); ++it)
		{
			fringe.insert(*it);
		}
	}
}

const Node* GeneralSearch::graphSearch(const Problem &problem, SimpleQueue<const Node*> &fringe)
{
	set<const State*> closed;
	
	// inserts the initial state to the fringe
	const State *state = &problem.initial_state();
	const Node *node = new Node(*state);
	fringe.insert(node);

	while (true)
	{
		// we explored all the states
		if (fringe.empty())
			return 0;
		
		// get the next state
		node = fringe.removeFirst();
		state = &node->state();

		// check if it's a goal state
		if (problem.isGoalState(*state))
			return node;
		
		// check if it's a new state
		if (closed.find(state) == closed.end())
		{
			// add state to closed
			closed.insert(state);
			
			// get all successor states
			list<const Node*> expanded;
			expand(*node, problem, expanded);

			// insert them to fringe
			fringe.insertAll(expanded.begin(), expanded.end());

			/*
			list<const Node*>::iterator it;
			for (it = expanded.begin(); it != expanded.end(); ++it)
				fringe.insert(*it);

			*/
		}
	}
}
