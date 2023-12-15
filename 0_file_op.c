#include "monty.h"

/**
 * open_f - opens a file
 * @sourceFile: source file
 * Return: void
 */
void open_f(char *sourceFile)
{
	FILE *fd = fopen(sourceFile, "r");

	if (sourceFile == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", sourceFile);
		exit(EXIT_FAILURE);
	}

	read_f(fd);
	fclose(fd);
}

/**
 * read_f - reads a file
 * @fd: file description
 * Return: void
 */
void read_f(FILE *fd)
{
	int line_number, frmt = 0;
	char *cache = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&cache, &len, fd) != -1; line_number++)
	{
		frmt = parse_line(cache, line_number, frmt);
	}
	free(cache);
}


/**
 * parse_line - tokenizes a line to invoke functions
 * @cache: cache of the line
 * @line_number: line number
 * @frmt: 0 if the opcode is stack. 1 if queue.
 * Return: 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *cache, int line_number, int frmt)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (cache == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}

	opcode = strtok(cache, delim);
	if (opcode == NULL)
		return (frmt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	execute(opcode, value, line_number, frmt);
	return (frmt);
}
