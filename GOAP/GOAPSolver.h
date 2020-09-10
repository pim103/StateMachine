#pragma once
#include "WorldState.h"
#include "Action.h"
class GOAPSolver
{
private:
	WorldState worldState;
public:
	GOAPSolver(WorldState nWorldState);
	bool checkPreconditions(Action action);
	void solve();
};

