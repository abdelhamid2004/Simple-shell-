#include "shell.h"
/**
 * _execv - executes a command
 * @order_words: array of arguments
 * @argv: previous pointer
 * @n: old size of previous pointer
 * @ix: an input
 * Return: array of pointers to words
 */
int _execv(char **order_words, int n, char **argv, int ix)
{
		char *cmd;
		pid_t pt;
		int st;

		if (string_cmp(order_words[0], "exit") == 0)
		{
			char *k;
			int h;

			h = 0;
			if (n >= 2)
			{
				k = strdup(order_words[1]);
				h = atoi(k);
				free(k);
			k = NULL; }
			else if (ix > 1)
			{
				h = ix; }
			free_the_array(order_words);
			exit(h); }
		cmd = get_path(order_words[0]);
		if (cmd == NULL)
		{
			_printerror(argv[0], order_words[0], ix);
			free_the_array(order_words);
			return (127); }
		pt = fork();
		if (pt == 0)
		{
			if (execve(cmd, order_words, environ) == -1)
			{
				free(cmd);
				cmd = NULL;
				free_the_array(order_words); } }
		else
		{
				waitpid(pt, &st, 0);
				free_the_array(order_words);
				free(cmd), cmd = NULL; }
		return (WEXITSTATUS(st)); }
