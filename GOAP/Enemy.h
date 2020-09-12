#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Enemy
{
private:
	int hp;
	vector<int> pos;
public:
	Enemy(int posX, int posY);
	int getHp() const;
	void setHp(int nHp);
	vector<int> getPos() const;
	void setPos(int nposX, int nposY);
};

