#include "monty.h"

/**
 * stack_add - adds a new node
 * @new_node: The new node
 * @l_n: The line number
 * Return: Nothing
 */
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int l_n)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - prints the stack
 * @stack: The stack
 * @line_number: The line number
 * Return: Nothing
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
