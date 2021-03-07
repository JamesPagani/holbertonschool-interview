#include "palindrome.h"

/**
 * rec_division - Divides until the desired amount of digits is reached.
 * @num: Number to divide.
 * @digits: Amount of digits to leave.
 * Return: @num with @digits left.
 */
unsigned long rec_division(unsigned long num, unsigned long factor)
{
	if (num < factor)
		return num;
	return (rec_division(num / 10, factor));
}

/**
 * is_palindrome - Determines if a given number is a palindrome.
 * @n: Unsigned long number.
 * Return: 1 if @n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long factor;
	unsigned long i, j;

	factor = 10;
	i = rec_division(n, 10);
	j = n % factor;
	while (n / factor != 0)
	{
		if (i != j)
			return (0);
		factor *= 10;
		i = rec_division(n, factor) % 10;
		j = rec_division(n % factor, 10);
	}
	return (1);
}
