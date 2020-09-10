#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"

using namespace std;

enum TransitionType {
	HP_SELF,
	HP_ENEMY,
	CD_HEAL,
	CD_BUFF_ATT,
	CD_BUFF_DEF,
	STATE
};

enum TransitionComparison {
	EQUAL,
	INFERIOR,
	SUPERIOR,
	EQUAL_SUPERIOR,
	EQUAL_INFERIOR
};

enum GameState {
	ATT,
	HEAL,
	BUFF_ATT,
	BUFF_DEF,
	NEUTRAL
};

class Transition {
public:
	Transition(TransitionType _transitiontype);

	virtual bool checkCondition(const Entity* selfEntity, const Entity* otherEntity) const {
		return false;
	}

	TransitionType getTransitionType();

protected:
	TransitionType transitionType;
};

class TransitionState: public Transition{
public:
	TransitionState(vector<GameState> _checkStateId);
	bool checkCondition(const Entity* selfEntity, const Entity* otherEntity) const;

private:
	vector<GameState> checkStateId;
};

class TransitionCompareInt : public Transition {
public:
	TransitionCompareInt(int _valueToCompare, TransitionType _transitionType, TransitionComparison _transitionComparison);
	TransitionCompareInt(int _valueToCompare, TransitionType _transitionType, TransitionComparison _transitionComparison, const Transition* _otherCheckTransition);
	bool checkCondition(const Entity* selfEntity, const Entity* otherEntity) const;

	int getCorrectArgument(const Entity* selfEntity, const Entity* otherEntity) const;

private:
	int valueToCompare;
	TransitionComparison transitionComparison;
	const Transition* otherCheckTransition;
};