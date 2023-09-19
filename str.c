#include "shell.h"


/**
 * string_cmp - performs lexicogarphic comparison of two strangs.
 * @s: the first strang
 * @s1: the second strang
 *
 * Return: negative if s < s1, positive if s > s1, zero if s == s1
 */

int  string_cmp(char *s, char *s1)
{
	int c;

	c = (int)*s - (int)*s1;
	while (*s)
	{
		if (*s != *s1)
		{
			break; }
		s++;
		s1++;
		c = (int)*s - (int)*s1; }
	return (c);
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */

int string_len(char *s)
{
	int length = 0;

	while (s[length])
	{
		length++; }
	return (length);
}

/**
 * string_cat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */

char *string_cat(char *destination, char *source)
{
	char *ptr = destination;

	while (*ptr)
	{
		ptr++;
	}
	while (*source)
	{
		*ptr = *source;
		ptr++, source++; }
	*ptr = '\0';
	return (destination);
}

/**
 * string_cpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */

char *string_cpy(char *dest, char *src)
{
	size_t ptr;

	for (ptr = 0; src[ptr] != '\0'; ptr++)
	{
		dest[ptr] = src[ptr];
	}
	dest[ptr] = '\0';
	return (dest);
}
