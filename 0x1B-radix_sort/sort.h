#ifndef SORT
#define SORT

/* Header Files */
#include <stdlib.h>

/* Function Prototypes */
void print_array(const int *array, size_t size);
int _pow(int base, int exp);
void counting_radix(int *array, size_t size, size_t digit);
void radix_sort(int *array, size_t size);

#endif
