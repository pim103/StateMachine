#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum GameState {
	ATT,
	HEAL,
	BUFF_ATT,
	BUFF_DEF,
	NEUTRAL
};

enum Element {
	WIND,
	FIRE,
	EARTH,
	WATER
};

class Entity {
public:
	Entity(int _id, int _hp, int _def, int _att, Element _element);

	const int getId() const;
	int getHp() const;
	int getDef() const;
	int getAtt() const;
	int getCdHeal() const;
	int getCdBuffDef() const;
	int getCdBuffAtt() const;
	const Element getElement() const;

	void setHp(int newHp);
	void setDef(int newDef);
	void setAtt(int newAtt);
	void setElement(Element newElement);

	void updateEntity();
	void applyState(Entity* otherEntity, GameState currentState);

private:
	int id;
	int hp;
	int att;
	int def;

	int cdHeal;
	int cdBuffAtt;
	int cdBuffDef;

	Element element;
};