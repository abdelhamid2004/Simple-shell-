#include "shell.h"

/**
 * habiba_read - take command line from prompt
 * word: array of char
 * sz: size of array
 * word_len: the length of string
 * Return: 0 on success
 */

char *habiba_read(void)
{
	char *words = NULL;
	size_t sz = BUFSIZ;
	ssize_t word_len;

	if (isatty(STDOUT_FILENO) == 1)
	{
		fflush(STDIN_FILENO);
		write(STDOUT_FILENO, "$ ", 2);
	}
	word_len = getline(&words, &sz, stdin);
	if (word_len == -1)
	{
		free(words);
		words = NULL;
		return (NULL);
	}
	words[string_len(words) - 1] = '\0';
	return (words);
}
