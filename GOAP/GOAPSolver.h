#pragma once
#include "WorldState.h"
#include "Action.h"
class GOAPSolver
{
private:
	WorldState worldState;
	vector<Action*> possibleActions;
	Action* topGoal;
	Action* currentGoal;
public:
	GOAPSolver(WorldState nWorldState);
	vector<Precondition*> checkPreconditions(Action* action);
	void solve();
};

