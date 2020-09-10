#pragma once
#include <iostream>
#include <vector>

#include "GOAPSolver.h"

using namespace std;

enum Effect {
	GET_MANA,
	DO_DAMAGES,
	MOVE_TOWARDS_ENEMY,
	MOVE_TOWARDS_POTION
};
enum Precondition {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE
};

class Action
{
private:
	Effect effect;
	vector<Precondition> preconditions;
	int amount;
public:
	Action(Effect nEffect, vector<Precondition> nPreconditions, int nAmount);
	vector<Precondition> getPreconditions();
	Effect getEffect();
};

