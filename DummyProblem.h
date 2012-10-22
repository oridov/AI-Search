#ifndef DUMMYPROBLEM_H_
#define DUMMYPROBLEM_H_

#include "problem.h"

class DummyProblem :
	public Problem
{
public:
	DummyProblem(void);
	~DummyProblem(void);

	void succesorsFunction(const State &state, vector<const ActionState*> &out) const {out.push_back(new ActionState(Action(), State()));};
	bool isGoalState(const State &state) const {return false;};
	int stepCost(const State &from, const Action &action, const State &to) const {return 1;};
};

#endif
