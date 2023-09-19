#include "shell.h"

/**
 * get_environment - splits a string and makes it an array of pointers to words
 * @var: the string to be split
 * Return: array of pointers to words
 */

char *get_environment(char *var)
{
size_t l = strlen(var);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(var, environ[i], l) == 0 && environ[i][l] == '=')
		{
			return (environ[i] + l + 1);
		}
	}
	return (NULL);
}
