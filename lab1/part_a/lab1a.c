/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "../life_game/lifegame.h"
#include "../life_game/lab01.h"

int main(void)
{
	initialize_world();

	for (int n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();
	}

	output_world();

	return 0;
}
