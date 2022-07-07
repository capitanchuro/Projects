//A Plot Four program used to play connect four locally or 
//with online players
#pragma once
#include "List.h"

class PlotFour {
	//n keeps track of the # of moves and turn keeps track
	// of whoe turn it is
	int n = 0, turn = 0;
	//An array of units used by players
	List<int> units;
	//An array used to plot the moves of each player
	List<List<int>> grid;

public:

	//Construcor
	PlotFour();

	//Returns the array to the matrix
	List<List<int>>& list();

	//Recursively checks for a win 
	int win(int, int, int, int, int = 0);

	//Plots a unit in the matrix
	bool move(int);

	//Destructor
	~PlotFour();
};
