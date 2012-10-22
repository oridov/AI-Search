#ifndef NODE_H_
#define NODE_H_

#include "Action.h"
#include "State.h"

class Node
{
public:
	Node(const State &state, const Action &action = Action(), const Node *parent = 0, int pathCost = 0, int depth = 0);
	~Node(void);

	const State& state() const;
	const Node& parent() const;
	const Action& action() const;
	int path_cost() const;
	int depth() const;
	void set_depth(int d) {depth_ = d;}

private:
	const State &state_;
	const Node* parent_;
	const Action &action_;
	int path_cost_;
	int depth_;
};

#endif
