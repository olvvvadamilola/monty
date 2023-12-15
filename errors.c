#include "monty.h"

/**
 * err - handles errors.
 * @error_msg: handles errors.
 */
void err(int error_msg, ...)
{
	va_list arg;
	char *op;
	int line_n;

	va_start(arg, error_msg);
	switch (error_msg)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line_n = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
