#include "monty.h"

/**
 * err - handles errors.
 * @error_code: error codes
 * Return: Nothing
 */
void m_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int line_n;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_n = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op);
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
 * stack_err - handles errors.
 * @error_code: error codes
 */
void stack_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int line_n;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_n = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * pchar_err - handles errors.
 * @error_code: error codes
 */
void pchar_err(int error_code, ...)
{
	va_list ag;
	int line_n;

	va_start(ag, error_code);
	line_n = va_arg(ag, int);
	switch (error_code)
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
