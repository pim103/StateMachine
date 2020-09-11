#pragma once
#include <iostream>
#include <vector>
#include "Precondition.h"

using namespace std;

enum Effect {
	GET_MANA,
	DO_DAMAGES,
	MOVE_TOWARDS_ENEMY,
	MOVE_TOWARDS_POTION
};


class Action
{
private:
	Effect effect;
	vector<Precondition> preconditions;
	int id;
	int cost;
public:
	Action();
	Action(int nId, Effect nEffect, vector<Precondition> nPreconditions, int nAmount);
	vector<Precondition> getPreconditions();
	Effect getEffect();
	int getAmount();
	int getId();
	int getCost();
	void setCost(int nCost);
	void executeAction();
};

