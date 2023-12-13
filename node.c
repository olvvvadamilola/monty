#include "monty.h"

stack_t *h = NULL;

/**
 * cr8_node - create new node
 * @n: integer
 * Return: new node
 */
stack_t *cr8_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}
/**
 * free_node - free node
 * Return: void
 */
void free_node(void)
{
	stack_t *temp;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
}

/**
 * Queue - queue node
 * @new_node: new node
 * @line_no: line number
 * Return: void
*/
void Queue(stack_t **new_node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (*new_node == NULL || *new_node == NULL)
	exit(EXIT_FAILURE);

	if (h == NULL)
	{
		h = *new_node;
		return;
	}
	for (temp = h; temp->next != NULL; temp = temp->next)
	{}

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
