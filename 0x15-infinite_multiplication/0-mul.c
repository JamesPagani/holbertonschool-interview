#include "holberton.h"
/**
 * _calloc - DIY (and type specific) version of the standard library's calloc.
 * @size: Amount of contiguous bytes to allocate.
 * Return: Pointer to the first allocated byte.
 */
char *_calloc(size_t size)
{
	char *new;
	size_t i;

	new = malloc(size);
	for (i = 0; i < size; i++)
	{
		new[i] = '0';
	}
	return (new);
}

/**
 * print_error - Print an error message and exits the program.
 */
void print_error(void)
{
	char *error_msg = "Error\n";
	int i;

	for (i = 0; i < 6; i++)
	{
		_putchar(error_msg[i]);
	}
	exit(98);
}

/**
 * _strlen - Calculate the length of a string
 * @str: A string (array of characters).
 * Return: Length of the string.
 */
size_t _strlen(char *str)
{
	int i;
	size_t len;

	i = 0;
	len = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
			print_error();
		len++;
		i++;
	}
	return (len);
}

/**
 * reset - Reset the value of the number to zero.
 * @num: Number to reset.
 * @size: Size of the number.
 */
void reset(char **num, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		num[0][i] = '0';
	}
}

/**
 * sum - Adds two numbers together.
 * @a: Answer number.
 * @b: Partial product result.
 * @size: Size of both numbers.
 */
void sum(char **a, char *b, size_t size)
{
	int reminder, num_a, num_b, c;
	int i;

	reminder = 0;
	for (i = (int)size - 1; i >= 0; i--)
	{
		num_a = (int)a[0][i] - 48;
		num_b = (int)b[i] - 48;
		c = num_a + num_b + reminder;
		a[0][i] = ((char)c % 10) + 48;
		reminder = c / 10;
	}
}

/**
 * mul - Multiplies two numbers together.
 * @a: First number.
 * @b: Second number.
 * Return: Pointer to the product of @a and @b.
 */
char *mul(char *a, char *b)
{
	size_t size_a = _strlen(a);
	size_t size_b = _strlen(b);
	size_t size_c = size_a + size_b;
	size_t offset;
	char *final_prod = _calloc(sizeof(char) * size_c);
	char *parti_prod = _calloc(sizeof(char) * size_c);
	int int_a, int_b, prod, reminder, i, j, k;

	offset = 0;
	for (i = (int)size_b - 1; i >= 0; i--)
	{
		reminder = 0;
		k = size_c - 1 - offset;
		int_b = (int)b[i] - 48;
		for (j = (int)size_a - 1; j >= 0; j--)
		{
			int_a = (int)a[j] - 48;
			prod = int_a * int_b + reminder;
			parti_prod[k] = ((char)prod % 10) + 48;
			reminder = prod / 10;
			k--;
		}
		parti_prod[k] = ((char)reminder % 10) + 48;
		sum(&final_prod, parti_prod, size_c);
		reset(&parti_prod, size_c);
		offset++;
	}

	free(parti_prod);
	return (final_prod);
}

/**
 * main - Entry point
 * @argc: Amount of arguments supplied (app name included).
 * @argv: Arguments passed to the program, including its name.
 * Return: 1 on success, anything else on failure.
 */

int main(int argc, char *argv[])
{
	size_t total_size, i;
	char *answer;

	if (argc < 3)
		print_error();

	answer = mul(argv[1], argv[2]);
	total_size = _strlen(argv[1]) + _strlen(argv[2]);
	i = 0;
	while (answer[i] == '0' && i < total_size)
		i++;
	if (i >= total_size)
		_putchar('0');
	for (; i < total_size; i++)
		_putchar(answer[i]);
	_putchar('\n');
	free(answer);
	return (1);
}
