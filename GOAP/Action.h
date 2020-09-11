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
public:
	Action();
	Action(int nId, Effect* nEffect, int _amount, vector<Precondition*> nPreconditions);
	vector<Precondition*> getPreconditions();
	Effect* getEffect();
	int getId();
	int getCost();
	void setCost(int nCost);
};

