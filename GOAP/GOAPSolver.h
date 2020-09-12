#pragma once

#include <map>

#include "WorldState.h"
#include "NodeParser.h"

class GOAPSolver
{
private:
	WorldState worldState;

	vector<Action*> possibleActions;
	vector<Precondition*> preconditions;
	vector<Effect*> effects;

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

	void deleteGoap();
};