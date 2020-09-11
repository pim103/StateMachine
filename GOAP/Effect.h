#pragma once
#include<iostream>
#include<functional>

using namespace std;

enum EffectType {
	GET_MANA,
	GET_POTION,
	DO_DAMAGES,
	MOVE_TOWARDS_ENEMY,
	MOVE_TOWARDS_POTION
};

class Effect
{
private:
	EffectType effectType;
	int amount;
	function<void(void)> callback;
public:
	Effect();
	Effect(EffectType nEffectType, int nAmount, function<void(void)> nCallback);
	EffectType getEffectType();
	Effect (function<void(void)> f) : callback(f) {}
	void execute();
	int getAmount();
};

