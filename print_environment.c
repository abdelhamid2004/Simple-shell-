#include "shell.h"

/**
 * print_environment - prints the current environment
 * @env: Structure containing potential arguments. Used to maintain
 *constant function prototype.
 */

void print_environment(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
