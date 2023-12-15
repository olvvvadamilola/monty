#include "monty.h"

/**
 * mp_error - handles errors.
 * @error_msg: error codes
 * Return: void
 */
void mp_error(int error_msg, ...)
{
	va_list ag;
	char *op;
	int l_n;

	va_start(ag, error_msg);
	switch (error_msg)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			l_n = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * pp_error - handles errors.
 * @error_msg: error codes
 */
void pp_error(int error_msg, ...)
{
	va_list ag;

	va_start(ag, error_msg);
	switch (error_msg)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * Arith_error - handles errors.
 * @error_msg: errorcodes
 */
void Arith_error(int error_msg, ...)
{
	va_list ag;

	va_start(ag, error_msg);
	switch (error_msg)
	{
		case 'sw':
			fprintf(stderr, "L%d: can't swap, stack too short\n",
					va_arg(ag, unsigned int));
		case 'a':
			fprintf(stderr, "L%d: can't add, stack too short\n",
					va_arg(ag, unsigned int));
		case 's':
			fprintf(stderr, "L%d: can't sub, stack too short\n",
					va_arg(ag, unsigned int));
		case 'd':
			fprintf(stderr, "L%d: can't div, stack too short\n",
					va_arg(ag, unsigned int));
		case 'dd':
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(ag, unsigned int));
		case 'mul':
			fprintf(stderr, "L%d: can't mul, stack too short\n",
					va_arg(ag, unsigned int));
		case 'mod':
			fprintf(stderr, "L%d: can't mod, stack too short\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
