#pragma once
#include "List.h"

class ConnectFour {
	int n = 0, turn = 0;
	List<int> units;
	List<List<int>> grid;

public:

	ConnectFour();

	List<List<int>>& list();

	int win(int, int, int, int, int = 0);

	bool move(int);
};
