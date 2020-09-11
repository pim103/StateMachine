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
	
	int getCostAction(Action* action);
	vector<Precondition*> getUnvalidPreconditions(Action* action);
	Precondition* getFirstUnvalidPrecondition(Action* action);
	void solve();
	Action* getActionById(int id);
};

