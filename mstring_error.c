#include "monty.h"
/**
 * pchar_err - handles errors.
 * @error_msg: The error codes are the following:
 */
void pchar_err(int error_msg, ...)
{
	va_list ag;
	int l_n;

	va_start(ag, error_msg);
	l_n = va_arg(ag, int);
	switch (error_msg)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_n);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
