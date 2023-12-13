#include "monty.h"

/**
 * F_open - open file
 * @file: file
 * Return: void
 */
void F_open(char *file)
{
	FILE *fd = fopen(file, "r");

	if (fd == NULL || file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
	}
	F_read(fd);
	fclose(fd);
}

/**
 * F_read - read file
 * @fd: file
 * Return: void
 */
void F_read(FILE *fd)
{
	int line_number = 1;
	char *buffer = NULL;
	size_t len = 0;
	int frmt = 0;

	while (getline(&buffer, &len, fd) != -1)
	{
		frmt = tokenize(buffer, line_number, frmt);
		line_number++;
	}
	free(buffer);
}

/**
 * tokenize - tokenize
 * @buffer: buffer
 * @line_number: line number
 * @frmt: storage format
 * Return: void
 */
int tokenize(char *buffer, int line_number, int frmt)
{
	char *opcode, *val;

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, DELIM);

	if (opcode == NULL)
		return (frmt);

	val = strtok(NULL, DELIM);

	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	fn_search(opcode, val, line_number, frmt);
	return (frmt);
}
