#include "monty.h"
/**
 * arith_err - handles arithmetic errors.
 * @error_msg: handles errors.
*/
void arith_err(int error_msg, ...)
{
	va_list arg;
	char *op;
	int line_n;

	va_start(arg, error_msg);
	switch (error_msg)
	{
		case 12:
			line_n = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, op);
			break;
		case 13:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
