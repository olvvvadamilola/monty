#include "monty.h"
/**
 * fn_search - search for function for opcode
 * @opcode: opcode
 * @val: value
 * @line_no: line number
 * @frmt: storage format
 * Return: void
 *
 */
void fn_search(char *opcode, char *val, int line_no, int frmt)
{
	int a = 0;
	int b = 0;

	instruction_t fn_list[] = {

	};

	if (opcode[0] == '#')
		return;

	while (fn_list[a].opcode != NULL)
	{
		if (strcmp(opcode, fn_list[a].opcode) == 0)
		{
			fn_call(fn_list[a].f, opcode, val, line_no, frmt);
			b = 0;
			break;
		}
		a++;
	}
	if (b == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
	}
}
/**
 * fn_call - call function
 * @f: function
 * @opcode: opcode
 * @val: value
 * @line_no: line number
 * @frmt: storage format
 * Return: void
*/
void fn_call(fn_op f, char *opcode, char *val, int line_no, int frmt)
{
	stack_t *node;
	int i;
	int j;

	i = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			i = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
				exit(EXIT_FAILURE);
			}
		}
		node = cr8_node(atoi(val) * i);
		if (frmt == 0)
			func(&node, line_no);
		if (frmt == 1)
			Queue(&node, line_no);
	}
	else
		func(&h, line_no);
}
