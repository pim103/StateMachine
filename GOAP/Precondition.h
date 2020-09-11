#pragma once

#include <iostream>
#include <vector>

using namespace std;

enum PreconditionType {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE_ENEMY,
	IS_IN_RANGE_POTION
};

class Precondition
{
private:
	PreconditionType preconType;
	vector<int> actionIds;
	int amount;
public:
	Precondition();
	Precondition(PreconditionType type, int nAmount, vector<int> ids);
	vector<int> getActionIds();
	PreconditionType getType();
	int getAmount();
	void setActionIds(vector<int> ids);
};

