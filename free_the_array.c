#include "shell.h"

/**
 * free_the_array - frees the array of pointers arv
 *@array: array of pointers
 */

void free_the_array(char **array)
{
	int i = 0;

	if (!array)
	{
		return;
	}
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]), array[i] = NULL;
	}
	free(array), array = NULL;
}

/**
 * _intger_to_assci - converts a string to an integer
 * @num: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */

char *_intger_to_assci(int num)
{
	char bf[20];
	int i = 0;

	if (num == 0)
	{
		bf[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			bf[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	bf[i] = '\0';
	string_reverse(bf, i);
	return (strdup(bf));
}

/**
 * string_reverse - duplicates a string
 * @st: the string to duplicate
 * @length: size of string
 * Return: pointer to the duplicated string
 */

void string_reverse(char *st, int length)
{
	char temp;
	int start = 0;
	int ed = length - 1;

	while (start < ed)
	{
		temp = st[start];
		st[start] = st[ed];
		st[ed] = temp;
		start++;
		ed--;
	}
}

/**
 * _printerror - prints an error message
 * @cmd: the parameter & return info struct
 * @nm: string containing specified error type
 * @ix: an integer
 */

void _printerror(char *nm, char *cmd, int ix)
{
	char *idx, massege[] = ": not found\n";

	idx = _intger_to_assci(ix);
	write(STDERR_FILENO, nm, string_len(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, string_len(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, string_len(cmd));
	write(STDERR_FILENO, massege, string_len(massege));
	free(idx);
}
