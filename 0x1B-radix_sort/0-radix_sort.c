#include "sort.h"
/**
 * _pow - Custom Exponentiation function
 * @base: Base
 * @exp: Exponent
 * Return: Base to the power of exp
 */
int _pow(int base, int exp)
{
	if (exp <= 0)
		return (1);
	return (base * _pow(base, exp - 1));
}


/**
 * counting_radix - Counting sort used with radix sort
 * @array: Integer array to sort
 * @size: Size of @array
 * @digit: Digit to use as basis to sort
 */
void counting_radix(int *array, size_t size, size_t digit)
{
	int *tmp;
	int idx, target;
	size_t i;
	int counting[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	target = _pow(10, digit + 1);
	for (i = 0; i < size; i++)
	{
		idx = array[i] % target;
		if (digit > 0)
			idx /= (target / 10);
		counting[idx]++;
	}
	for (i = 1; i < 10; i++)
	{
		counting[i] += counting[i - 1];
	}
	for (i = size; i != 0; i--)
	{
		idx = array[i - 1] % target;
		if (digit > 0)
			idx /= (target / 10);
		idx = --counting[idx];
		tmp[idx] = array[i - 1];
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
}

/**
 * radix_sort - Sort an array of integers using LSD Radix Sort
 * @array: Array of integers to sort.
 * @size: Size of @array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i, max_digits, digits;
	int num;

	max_digits = 0;
	for (i = 0; i < size; i++)
	{
		digits = 0;
		num = array[i];
		do {
			num /= 10;
			digits++;
		} while (num > 0);
		if (digits > max_digits)
			max_digits = digits;
	}
	for (i = 0; i < max_digits; i++)
	{
		counting_radix(array, size, i);
		print_array(array, size);
	}
}
