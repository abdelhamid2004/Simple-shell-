#include "shell.h"

/**
 * main- function to show simple shell
 * @c: number of arguments
 * @argv: vector of arguments
 * @env: gets the value of an environ variable
 * Return: 0 Always (success)
 */

int main(int c, char **argv, char **env)
{
	char *order = NULL;
	char **order_words = NULL;
	int stat = 0, flag = 1, ix = 0;

	(void)c;

	while (flag)
	{
		int l;
		int n;

		order = habiba_read();
		if (order == NULL)
		{
			if (isatty(STDOUT_FILENO) == 1)
			{
				fflush(STDIN_FILENO);
				write(STDOUT_FILENO, "\n", 1);
			}
			return (stat); }
		ix++;
		order_words = abdelhamid_tokin(order, &n);

		if (!order_words)
		{
			continue; }
		l = bulit_in(order_words[0], env);
		if (l)
			free_the_array(order_words);
		else
			stat = _execv(order_words, n, argv, ix);
			}
	return (0);
}
