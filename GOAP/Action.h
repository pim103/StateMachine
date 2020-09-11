#pragma once
#include <iostream>
#include <vector>
#include "Precondition.h"

using namespace std;

enum Effect {
	GET_MANA,
	GET_POTION,
	DO_DAMAGES,
	MOVE_TOWARDS_ENEMY,
	MOVE_TOWARDS_POTION
};

class Action
{
private:
	Effect effect;
	vector<Precondition*> preconditions;
	int id;
	int cost;
	int amount;
public:
	Action();
	Action(int nId, Effect nEffect, int _amount, vector<Precondition*> nPreconditions);
	vector<Precondition*> getPreconditions();
	Effect getEffect();
	int getId();
	int getCost();
	void setCost(int nCost);
	void executeAction();
};

