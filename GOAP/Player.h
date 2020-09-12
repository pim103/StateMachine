#pragma once

#include<iostream>
#include<vector>

using namespace std;
class Player
{
private:
	int currentMana;
	int maxMana;
	int potions;
	vector<int> pos;
public:
	Player();
	int getMana() const;
	void setMana(int mana);
	void setPotions(int _potions);
	int getPotions() const;
	vector<int> getPos() const;
	void setPos(int nposX, int nposY);


};

