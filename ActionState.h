#ifndef ACTIONSTATE_H_
#define ACTIONSTATE_H_

#include "Action.h"
#include "State.h"

class ActionState
{
public:
	ActionState(const Action &action, const State &state) : action_(action), state_(state){}
	~ActionState(void){}

	const Action& action() const { return action_;}
	const State& state() const {return state_;}

private:
	const Action &action_;
	const State &state_;
};

#endif
