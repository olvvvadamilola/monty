#include "monty.h"
/**
 * string_err - handles errors.
 * @error_msg: handles errors.
 */
void string_err(int error_msg, ...)
{
	va_list arg;
	int line_n;

	va_start(arg, error_msg);
	line_n = va_arg(arg, int);
	switch (error_msg)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
