#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_f(char *sourceFile);
void read_f(FILE *);
int parse_line(char *cache, int line_number, int frmt);
void execute(char *, char *, int, int);
void invoke(op_func, char *, char *, int, int);

int c_length(FILE *);

/*------Stack operations------*/
stack_t *create_node(int n);
void free_nodes(void);
void stack_print(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);

void m_pint(stack_t **, unsigned int);
void m_pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void m_swap(stack_t **, unsigned int);

/*------Arithmetics------*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*------String operations----*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif
