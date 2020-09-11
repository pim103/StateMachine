#pragma once

#include <map>

#include "WorldState.h"
#include "Action.h"

class NodeParser {
public:
	int cost;
	Action* action;
	vector<NodeParser*> prevNodeParse;
};

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

	vector<Action*> findActionToFillPrecondition(Precondition* const precondition);

	NodeParser* getCostAction(Action* action);
	vector<Precondition*> getUnvalidPreconditions(Action* action);
	void solve();
	Action* getActionById(int id);
};