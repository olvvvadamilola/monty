#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>


#define DELIM "\n "

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
	void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

extern stack_t *h;
typedef void (*fn_op)(stack_t **, unsigned int);

/**Nodes*/
stack_t *cr8_node(int n);
void free_node(void);
void Queue(stack_t **new_node, __attribute__((unused))unsigned int line_no);

void F_open(char *file);
void F_read(FILE *fd);
int tokenize(char *buffer, int line_number, int frmt);

void fn_search(char *opcode, char *val, int line_no, int frmt);
void fn_call(fn_op f, char *opcode, char *val, int line_no, int frmt);

void stack_print(stack_t **stack, unsigned int line_no);
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int line_n);

void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);

#endif
