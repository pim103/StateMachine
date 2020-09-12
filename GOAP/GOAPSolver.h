#pragma once

#include <map>

#include "WorldState.h"
#include "NodeParser.h"

class GOAPSolver
{
private:
	WorldState* worldState;
	vector<const Action*> possibleActions;
	vector<const Precondition*> preconditions;
	vector<const Effect*> effects;

	Action* topGoal;
	Action* currentGoal;
public:
	GOAPSolver();
	GOAPSolver(WorldState* nWorldState);

	vector<const Action*> findActionToFillPrecondition(const Precondition* precondition) const;

	NodeParser* getNodeParserForAction(const Action* action) const;
	vector<const Precondition*> getUnvalidPreconditions(const Action* action) const;
	vector<const Action*> solve();
	const Action* getActionById(int id) const;

	void deleteGoap();
};