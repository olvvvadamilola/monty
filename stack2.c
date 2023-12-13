#include "monty.h"
/**
 * popt - pops the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Integer
 * Return: void
 */
void popt(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * pint_top - prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Integer
 * Return: void
 */
void pint_top(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
	}
	printf("%d\n", (*stack)->n);
}
