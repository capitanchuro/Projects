#include "PlotFour.h"

PlotFour::PlotFour() {
	grid = List<List<int>>();
	
	//Creates a 2 dimensional array with 6 rows and 7 columns
	for (int r = 0; r < 6; r++) {
		grid.push(List<int>());
		for (int c = 0; c < 7; c++)
			grid[r].push(0);
	}
	//Pushes unites representing each player into the units array
	units = List<int>();
	units.push(1);
	units.push(2);
}

List<List<int>>& PlotFour::list() {
	return grid;
}

int PlotFour::win(int y, int x, int v, int u, int n) {
	int r = y, c = x, count = 0;

	//Checks half a vertical, diagonal, or horizontal line basedon the arguments assigned to r and c
	while ((r >= 0 && c >= 0) && (r < grid.size() && c < grid[r].size())) {

		if (grid[r][c] == units[turn])
			count++;
		else
			break;

		r += v, c += u;
	}

	r = y, c = x; //Re-assigns the values of y and x to r and c to check the other half of the line

	while ((r >= 0 && c >= 0) && (r < grid.size() && c < grid[r].size())) {

		if (grid[r][c] == units[turn] && (r != y || c != x))
			count++;
		else if (r != y || c != x)
			break;

		r += v * -1, c += u * -1;

	}

	//Recursively checks the area centering a unit before returning the value of the unit
	//that won or 0.
	if (count == 4)
		return units[turn];
	else if (n < 4) {
		if (v + u == -1)
			return win(y, x, v, 1, ++n);
		else if (v + u == 0)
			return win(y, x, 0, u, ++n);
		else
			return win(y, x, 1, u, ++n);
	}
	else
		return 0;
}


bool PlotFour::move(int c) {
	int i = 0;
	if (grid[i][c] < 1) {

		//Drops down the rows before plotting a piece (if the column is open)
		while (i < grid.size() && grid[i][c] < 1)
			i++;

		grid[i - 1][c] = units[turn]; //Plots the unit in the matrix

		//Checks to see if there is a victor or if there are no more moves left
		if (win(i - 1, c, -1, 0) || ++n >= 42) {
			return false;
		}

		turn = (turn) ? 0 : 1; //Changes whose turn it is

		//Returns that there are moves to make
		return true;
	}
	else if (n < 42)
		return true; //Column is empty but there are still moves to make 
	else
		return false; // No moremoves to make
}

PlotFour::~PlotFour() {
}
