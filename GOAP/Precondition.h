#pragma once

enum Type {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE
};

class Precondition
{
private:
	Type preconType;
	int actionId;
public:
	Precondition();
	Precondition(Type type, int id);
	int getActionId();
	Type getType();
	void setActionId(int id);
};

