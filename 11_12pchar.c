#include "monty.h"

/**
 * p_char - prints char
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void p_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 87)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * p_str - prints string
 * @stack: The stack
 * @l_n: The line number
 * Return: Nothing
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int l_n)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 87)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
