#include "monty.h"

/**
 * execute - Executes the opcode
 * @opcode: opcode
 * @value: value
 * @frmt: if 0 nodes will be entered as a stack. 1 queue
 * @ln: line number
 * Return: void
 */
void execute(char *opcode, char *value, int ln, int frmt)
{
	int tag;
	int i;

	instruction_t funct_list[] = {
		{"push", stack_add},
		{"pall", stack_print},
		{"pint", m_pint},
		{"pop", m_pop},
		{"nop", nop},
		{"swap", m_swap},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (tag = 1, i = 0; funct_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funct_list[i].opcode) == 0)
		{
			invoke(funct_list[i].f, opcode, value, ln, frmt);
			tag = 0;
		}
	}
	if (tag == 1)
	{
		fprintf(stderr, "l%d: unknown instruction %s\n", ln, opcode);
		exit(EXIT_FAILURE);
	}
}


/**
 * invoke - Invokes the opcode fnction
 * @func: function pointer
 * @op: opcode
 * @val: value number
 * @ln: line number
 * @frmt: if 0 nodes will be entered as a stack. 1 queue
 */
void invoke(op_func func, char *op, char *val, int ln, int frmt)
{
	stack_t *node;
	int tag;
	int i;

	tag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			tag = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "l%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "l%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		node = create_node(atoi(val) * tag);
		if (frmt == 0)
			func(&node, ln);
		if (frmt == 1)
			queue(&node, ln);
	}
	else
		func(&head, ln);
}
