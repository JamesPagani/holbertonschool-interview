#ifndef SORT
#define SORT

/* Header Files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_subarray(int *array, size_t start, size_t end);
void split(int *array, int *tmp, size_t start, size_t end);
void merge(int *dest, int *src, size_t start, size_t mid, size_t end);
void merge_sort(int *array, size_t size);

#endif
