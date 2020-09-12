#pragma once
#include <iostream>
#include <vector>
#include "Precondition.h"

using namespace std;

class Action
{
private:
	Effect* effect;
	vector<Precondition*> preconditions;
	int id;
	int cost;
	string description;

public:
	Action();
	Action(int nId, Effect* nEffect, int _cost, vector<Precondition*> nPreconditions, string desc);
	vector<Precondition*> getPreconditions() const;
	Effect* getEffect() const;
	int getId() const;
	int getCost() const;
	void setCost(int nCost);
	string getDescription() const;
};

