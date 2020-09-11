// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "GOAPSolver.h"

int main()
{
	WorldState worldState = WorldState();
	GOAPSolver goapSolver = GOAPSolver(worldState);

	goapSolver.solve();
}
