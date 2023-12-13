#include "monty.h"

stack_t *h = NULL;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	free_node();
	return (0);
}
