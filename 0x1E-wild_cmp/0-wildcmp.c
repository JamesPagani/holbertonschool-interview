#include "holberton.h"

/**
 * wildcmp - Compare two strings (supports star wildcard)
 * @s1: A string
 * @s2: Another string, which can contain the star widlcard
 * Return: 1 if both strings are identical, 0 if otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' || *s2 == '\0')
	{
		if (*s2 == '*')
		{
			if (*(s2 + 1) == '*')
				return (wildcmp(s1, s2 + 1));
			if (*(s2 + 1) == '\0')
				return (1);
			return (0);
		}
		return (*s1 == *s2);
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (*s1 == *(s2 + 1))
			if (wildcmp(s1, s2 + 1) == 1)
				return (1);
		return (wildcmp(s1 + 1, s2));
	}
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
