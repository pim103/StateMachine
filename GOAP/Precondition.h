#pragma once

#include <iostream>
#include <vector>
#include"Effect.h"

using namespace std;

enum PreconditionType {
	HAS_MANA,
	HAS_POTION,
	IS_IN_RANGE_ENEMY,
	IS_IN_RANGE_POTION,
	ENEMY_AT_ZERO_HP
};

class Precondition
{
private:
	PreconditionType preconType;
	int amount;
	EffectType effectTypeToResolveThis;

public:
	Precondition();
	Precondition(PreconditionType type, int nAmount, EffectType neffectTypeToResolveThis);
	EffectType getEffectTypeToResolveThis() const;
	PreconditionType getType() const;
	int getAmount() const;
};

