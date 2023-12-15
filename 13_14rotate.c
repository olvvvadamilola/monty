#include "monty.h"
/**
 * rotl - rotates the stack to top
 * @stack: The stack
 * @l_n: The line number
 * Return: Nothing
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int l_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 *  rotr - rotates the stack to bottom
 * @stack: The stack
 * @l_n: The line number
 * Return: Nothing
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int l_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
