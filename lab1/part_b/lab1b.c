/*
 * lab1b.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include <stdio.h>
#include <stdlib.h>
#include "../life_game/lifegame.h"
#include "../life_game/lab01.h"

#define OUTPUT_FILE "world.txt"

int main(int argc, char ** argv)
{
	char * initializer;

	if (argc > 2) {
		printf("Invalid format: ./lib01 [initilizer_file]\n");
		exit(-1);
	}

	initializer = argc == 2 ? argv[1] : "glider.txt";

	initialize_world_from_file(initializer);

	for (int n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();
	}

	save_world_to_file(OUTPUT_FILE);

	return 0;
}
