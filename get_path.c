#include "shell.h"

/**
 * get_path - finds the pathname of a filename
 * @order: name of file or command
 * Return: pathname of filename or NULL if no match
 */

char *get_path(char *order)
{
	char *pathEnv, *cmd, *cpy, *direct;
	int i;
	struct stat st;

	for (i = 0; order[i]; i++)
	{
		if (order[i] == '/')
		{
			if (stat(order, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
				return (strdup(order));
			return (NULL); } }
	pathEnv = get_environment("PATH");
	if (!pathEnv)
	{
		return (NULL);
	}
	cpy = strdup(pathEnv);
	if (cpy == NULL)
		return (NULL);
	direct = strtok(cpy, ":");
	while (direct)
	{char *sl = "/";

		cmd = malloc(string_len(direct) + string_len(order) + 2);
		if (cmd == NULL)
			{free(cpy);
				return (NULL);
			}
		if (cmd)
		{string_cpy(cmd, direct);
		strcat(cmd, sl);
		strcat(cmd, order);
		if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{free(cpy);
			return (cmd);
		}
		free(cmd), cmd = NULL;
		direct = strtok(NULL, ":"); } }
	free(cpy);
	return (NULL); }
