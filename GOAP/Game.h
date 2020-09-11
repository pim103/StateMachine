#pragma once
#include"GOAPSolver.h"

class Game
{
private:
	GOAPSolver goapSolver;
	WorldState worldState;
public:
	Game();
	void runGame();
};

