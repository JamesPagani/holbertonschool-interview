#ifndef SLIDE_LINE
#define SLIDE_LINE

/* Other header files */
#include <stdlib.h>

/* Macros */

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

/* Prototypes */
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
