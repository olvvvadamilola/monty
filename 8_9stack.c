#include "monty.h"

/**
 * m_mul - multiplies the top two elements
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * m_mod - divides the top two elements
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		stack_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		stack_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
