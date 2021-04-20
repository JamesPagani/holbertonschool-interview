#ifndef HEAPSORT
#define HEAPSORT

/* Including this to use size_t */
#include <stdlib.h>

/* Function Prototypes */
void print_array(const int *array, size_t size);
void sift_down(int *array, size_t node, size_t curr_size, size_t real_size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif /* HEAPSORT */
