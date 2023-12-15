#include "monty.h"
/**
 * f_open - opens a file
 * @fff: name of the file
 * Return: void
*/
void f_open(char *fff)
{
	FILE *fd = fopen(fff, "r");

	if (fff == NULL || fd == NULL)
		err(2, fff);

	f_read(fd);
	fclose(fd);
}

/**
 * f_read - reads the file
 * @fd: file description
 * Return: void
*/
void f_read(FILE *fd)
{
	int line_number, frmt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		frmt = parse_line(buffer, line_number, frmt);
	}
	free(buffer);
}

/**
 * parse_line - parses the line
 * @buffer: buffer
 * @line_number: line number
 * @frmt: 0 into stack, 1 into queue
 * Return: void
*/
int parse_line(char *buffer, int line_number, int frmt)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (frmt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	executef(opcode, value, line_number, frmt);
	return (frmt);
}
