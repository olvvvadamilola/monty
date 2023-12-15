#include "monty.h"
/**
 * stack_err - handles stack errors.
 * @error_msg: handles errors.
 */
void stack_err(int error_msg, ...)
{
	va_list arg;

	va_start(arg, error_msg);
	switch (error_msg)
	{
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
