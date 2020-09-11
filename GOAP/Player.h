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
	int getMana();
	void setMana(int mana);
	void setPotions(int _potions);
	int getPotions();
	vector<int> getPos();
	void setPos(int nposX, int nposY);


};

