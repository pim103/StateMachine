#pragma once

#include <iostream>
#include <vector>

using namespace std;

enum PreconditionType {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE
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
	vector<int> getActionId();
	PreconditionType getType();
	int getAmount();
	void setActionIds(vector<int> ids);
};

