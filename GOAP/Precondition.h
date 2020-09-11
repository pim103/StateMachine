#pragma once

enum preconditionType {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE
};

class Precondition
{
private:
	preconditionType preconType;
	int actionId;
	int amount;
public:
	Precondition();
	Precondition(preconditionType type, int id, int nAmount);
	int getActionId();
	preconditionType getType();
	int getAmount();
	void setActionId(int id);
};

