#include "lab01.h"
#include "lifegame.h"

bool is_cell_out_of_bounds(int x, int y)
{
	return x < 0 ||  y < 0 || x >= get_world_width() || y >= get_world_height();
}

bool is_specified_cell(int x, int y, int i, int j)
{
	return x == i && y == j;
}

void next_generation(void) {

	for (int i = 0; i < get_world_width(); i++) {
		for (int j = 0; j < get_world_height(); j++) {
			set_cell_state(i, j, get_next_state(i, j));
		}
	}

	finalize_evolution();
}

int get_next_state(int x, int y) {
	int current_cell_state = get_cell_state(x, y);
	int alive_neighbors = num_neighbors(x, y);

	if (current_cell_state == ALIVE) {
		return (alive_neighbors == 2 || alive_neighbors == 3) ? ALIVE : DEAD;
	}

	return alive_neighbors == 3 ? ALIVE : DEAD;

}

int num_neighbors(int x, int y) {
	int alive_neighbors = 0;

	for (int i = x -1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (is_cell_out_of_bounds(i, j) || is_specified_cell(x, y, i, j)) {
				continue;
			}

			if (get_cell_state(i, j) == ALIVE) {
				alive_neighbors++;
			}
		}
	}

	return alive_neighbors;
}
