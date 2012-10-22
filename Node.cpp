
#include <stack>
#include "Node.h"

Node::Node(const State &state, const Action &action, const Node *parent, int pathCost, int depth) : state_(state), action_(action), parent_(parent), path_cost_(pathCost), depth_(depth){}

Node::~Node(void)
{
}

const State& Node::state() const
{
	return state_;
}

const Node& Node::parent() const
{
	return *parent_;
}

// revise
const Action& Node::action() const
{
	return action_;
}

int Node::path_cost() const
{
	return path_cost_;
}

int Node::depth() const
{
	return depth_;
}
