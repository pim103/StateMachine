#pragma once

#include <map>

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
	GOAPSolver();
	GOAPSolver(WorldState nWorldState);
	
	//pair<int, vector<Action*>> getCostAction(Action* action);
	vector<Precondition*> getUnvalidPreconditions(Action* action);
	/*vector<Action*> findBestWay(Precondition* preconditions);
	map<int, vector<Action*>> findWaysToExecute(Action* actionToResolve);*/
	Precondition* getFirstUnvalidPrecondition(Action* action);
	void solve();
	Action* getActionById(int id);
};

