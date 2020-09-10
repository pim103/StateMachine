#pragma once

#include<iostream>
#include<vector>

using namespace std;
class Player
{
private:
	int currentMana;
	int maxMana;
	vector<int> pos;
public:
	Player();
	int getMana();
	void setMana(int mana);
	vector<int> getPos();
	void setPos(int nposX, int nposY);


};

