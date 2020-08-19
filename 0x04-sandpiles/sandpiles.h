#ifndef SANDPILES
#define SANDPILES

/* Header files */
#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */
void sandpile_topple(int grid[3][3], int check[3][3]);
int stability_check(int grid[3][3], int check[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
