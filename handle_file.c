#include "monty.h"

/**
 * openF - opens a file
 * @sourceFile: the file namepath
 * Return: void
 */

void openF(char *sourceFile)
{
	FILE *fd = fopen(sourceFile, "r");

	if (sourceFile == NULL || fd == NULL)
		mp_error(2, sourceFile);

	read_F(fd);
	fclose(fd);
}


/**
 * read_F - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_F(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		mp_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	executef(opcode, value, line_number, format);
	return (format);
}
