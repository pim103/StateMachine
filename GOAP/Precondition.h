#pragma once

enum PreconditionType {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE
};

class Precondition
{
private:
	PreconditionType preconType;
	int actionId;
	int amount;
public:
	Precondition();
	Precondition(PreconditionType type, int id, int nAmount);
	int getActionId();
	PreconditionType getType();
	int getAmount();
	void setActionId(int id);
};

