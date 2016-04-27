/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "lifegame.h"
#include "lab01.h"

int main(void)
{
	initialize_world();

	for (int n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();
	}

	output_world();

	return 0;
}
