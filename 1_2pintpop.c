#include "monty.h"
/**
 * m_pop - Removes the top element of the stack.
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
*/
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		stack_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * m_pint - Prints the value at the top of the stack.
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
*/
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		stack_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
