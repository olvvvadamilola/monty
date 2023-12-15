#include "monty.h"
/**
 * executef - executes the opcode
 * @opcode: opcode
 * @value: value
 * @ln: line number
 * @format: 0 into stack, 1 into queue
*/
void executef(char *opcode, char *value, int ln, int format)
{
	int i;
	int tag;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", print_stack},
		{"pint", m_pint},
		{"pop", m_pop},
		{"nop", nop},
		{"swap", m_swap},
		{"add", m_add},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (tag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			invokef(func_list[i].f, opcode, value, ln, format);
			tag = 0;
		}
	}
	if (tag == 1)
		err(3, ln, opcode);
}


/**
 * invokef - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void invokef(op_func func, char *op, char *val, int ln, int format)
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
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * tag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			stack_queue(&node, ln);
	}
	else
		func(&head, ln);
}
