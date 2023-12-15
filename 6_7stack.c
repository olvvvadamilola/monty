#include "monty.h"
/**
 * m_sub - subtracts the top two elements
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		stack_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * m_div - divides the top two elements
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_err(8, line_number, "div");

	if ((*stack)->n == 0)
		stack_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
