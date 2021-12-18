#include "ConnectFour.h"

ConnectFour::ConnectFour() {
	grid = List<List<int>>();
	for (int r = 0; r < 6; r++) {
		grid.push(List<int>());
		for (int c = 0; c < 7; c++)
			grid[r].push(0);
	}
	units = List<int>();
	units.push(1);
	units.push(2);
}

List<List<int>>& ConnectFour::list() {
	return grid;
}

int ConnectFour::win(int y, int x, int v, int u, int n) {
	int r = y, c = x, count = 0;

	while ((r >= 0 && c >= 0) && (r < grid.size() && c < grid[r].size())) {

		if (grid[r][c] == units[turn])
			count++;
		else
			break;

		r += v, c += u;
	}

	r = y, c = x;

	while ((r >= 0 && c >= 0) && (r < grid.size() && c < grid[r].size())) {

		if (grid[r][c] == units[turn] && (r != y || c != x))
			count++;
		else if (r != y || c != x)
			break;

		r += v * -1, c += u * -1;

	}

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


bool ConnectFour::move(int c) {
	int i = 0;
	if (grid[i][c] < 1) {

		while (i < grid.size() && grid[i][c] < 1)
			i++;

		grid[i - 1][c] = units[turn];

		if (win(i - 1, c, -1, 0) || ++n >= 42) {
			return false;
		}

		turn = (turn) ? 0 : 1;

		return true;
	}
	else if (n < 42)
		return true;
	else
		return false;
}
