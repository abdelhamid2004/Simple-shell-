#include "shell.h"

/**
 * abdelhamid_tokin - returns a pointer to allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @order: pointer to a string
 * @n: an input
 * Return: pointer to a string
 */

char **abdelhamid_tokin(char *order, int *n)
{
	char *word_tokin = NULL, *cpy = NULL;
	char delimi[] = " \n\t";
	char **order_words = NULL;
	int num = 0, i = 0;

	if (!order)
	{
		return (NULL); }
	cpy = strdup(order);
	word_tokin = strtok(cpy, delimi);
	if (word_tokin == NULL)
	{
		free(order);
		order = NULL;
		free(cpy);
		cpy = NULL;
		return (NULL); }
	while (word_tokin)
	{
		num++;
		word_tokin = strtok(NULL, delimi); }
	free(cpy);
	cpy = NULL;
	*n = num;
	order_words = malloc(sizeof(char *) * (num + 1));
	if (!order_words)
	{
		free(order);
		order = NULL;
		return (NULL); }
	word_tokin = strtok(order, delimi);
	while (word_tokin)
	{
		order_words[i] = strdup(word_tokin);
		word_tokin = strtok(NULL, delimi);
		i++; }
	free(order);
	order = NULL;
	order_words[i] = NULL;
	return (order_words); }
