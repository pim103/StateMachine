#pragma once
#include <iostream>
#include <vector>
#include "Precondition.h"

using namespace std;

class Action
{
private:
	const Effect* effect;
	vector<const Precondition*> preconditions;
	int id;
	int cost;
	string description;

public:
	Action();
	Action(int nId, const Effect* nEffect, int _cost, vector<const Precondition*> nPreconditions, string desc);
	vector<const Precondition*> getPreconditions() const;
	const Effect* getEffect() const;
	int getId() const;
	int getCost() const;
	void setCost(int nCost);
	string getDescription() const;
};

