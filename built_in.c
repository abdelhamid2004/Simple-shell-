#include "shell.h"

/**
 * bulit_in - Remove an environment variable
 * @env: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @s: string of char
 *  Return: 1 on delete, 0 otherwise
 */

int bulit_in(char *s, char **env)
{
	char *funs[] = {"cd", "env", NULL};
	int i;

	for (i = 0; funs[i]; i++)
	{
		if (string_cmp(s, funs[i]) == 0 && string_cmp(s, "env") == 0)
		{
			print_environment(env);
			return (1);
		}
	}
	return (0);
}
