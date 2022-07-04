#pragma once
#include "List.h"

class PlotFour {
	int n = 0, turn = 0;
	List<int> units;
	List<List<int>> grid;

public:

	PlotFour();

	List<List<int>>& list();

	int win(int, int, int, int, int = 0);

	bool move(int);
};
