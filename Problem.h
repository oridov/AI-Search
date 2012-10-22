#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <vector>
#include <list>
#include "ActionState.h"

using namespace std;

class Problem
{
public:
	Problem(const State &initial_state) : initial_state_(initial_state){};
	/// <summary>
    /// The initial state that the agent starts in
    /// </summary>
	const State& initial_state() const {return initial_state_;};
    /// <summary>
    /// A description of the possible actions available to the agent
    /// </summary>
    /// <param name="state">A given state</param>
    /// <returns>a set of (action, successor) ordered pairs, where each action is one of the legal actions in the given
    /// state and each successor is a state that can be reached from the given state by applying the action</returns>
    virtual void succesorsFunction(const State &state, vector<const ActionState*> &out) const = 0;
    /// <summary>
    /// Determines whether a given state is a goal state
    /// </summary>
    /// <param name="state">the state to be determined</param>
    /// <returns>true if a goal state</returns>
    virtual bool isGoalState(const State &state) const = 0;
    /// <summary>
    /// Assigns a numeric cost to each step
    /// </summary>
    /// <param name="from">the step from this state</param>
    /// <param name="action">with this action</param>
    /// <param name="to">to this state</param>
    /// <returns>the cost of the step</returns>
    virtual int stepCost(const State &from, const Action &action, const State &to) const = 0;

protected:
	const State& initial_state_;
};

#endif
