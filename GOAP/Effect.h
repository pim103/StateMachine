#pragma once
#include<iostream>
#include<functional>
#include "WorldState.h"
using namespace std;

enum EffectType {
	GET_MANA,
	GET_POTION,
	DO_DAMAGES,
	MOVE_TOWARDS_ENEMY,
	MOVE_TOWARDS_POTION,
	KILL_ENEMY
};

class Effect
{
private:
	EffectType effectType;
	int amount;
	function<void(WorldState*)> callback;
public:
	Effect();
	Effect(EffectType nEffectType, int nAmount, function<void(WorldState*)> nCallback);
	Effect(function<void(WorldState*)> f) : callback(f) {}

	EffectType getEffectType() const;
	void execute(WorldState* worldState) const;
	int getAmount() const;
};

