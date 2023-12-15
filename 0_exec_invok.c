#include "monty.h"
/**
 * executef - executes the opcode
 * @opcode: opcode
 * @value: value
 * @l_n: line number
 * @frmt: 0 into stack, 1 into queue
*/
void executef(char *opcode, char *value, int l_n, int frmt)
{
	int i;
	int tag;

	instruction_t f_list[] = {
		{"push", stack_add},
		{"pall", print_stack},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"nop", nop},
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

	for (tag = 1, i = 0; f_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, f_list[i].opcode) == 0)
		{
			invokef(f_list[i].f, opcode, value, l_n, frmt);
			tag = 0;
		}
	}
	if (tag == 1)
		err(3, l_n, opcode);
}


/**
 * invokef - invokes the opcode
 * @func: opcode
 * @op: opcode
 * @val: value
 * @l_n: line number
 * @frmt: 0 into stack, 1 into queue
 * Return: void
 */
void invokef(op_func func, char *op, char *val, int l_n, int frmt)
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
			err(5, l_n);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, l_n);
		}
		node = create_node(atoi(val) * tag);
		if (frmt == 0)
			func(&node, l_n);
		if (frmt == 1)
			stack_queue(&node, l_n);
	}
	else
		func(&head, l_n);
}
