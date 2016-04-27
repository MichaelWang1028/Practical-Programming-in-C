#ifndef _LAB01_H_
#define _LAB01_H_

#include <stdbool.h>

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50

bool is_cell_out_of_bounds(int x, int y);
bool is_specified_cell(int x, int y, int i, int j);

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

#endif
