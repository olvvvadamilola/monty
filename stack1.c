#include "monty.h"
/**
 * stack_add - add node to stack
 * @new_node: new node
 * @line_no: line number
*/
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (h == NULL)
	{
		h = *new_node;
		return;
	}
	temp = h;
	h = *new_node;
	h->next = temp;
	temp->prev = h;
}
/**
 * stack_print - print stack
 * @stack: stack
 * @line_no: line number
 * Return: void
*/
void stack_print(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	(void) line_no;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
