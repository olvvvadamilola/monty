#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
void f_open(char *fff);
int parse_line(char *buffer, int line_number, int frmt);
void f_read(FILE *);
int len_chars(FILE *);
void executef(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void stack_queue(stack_t **, unsigned int);

void invokef(op_func, char *, char *, int, int);

void m_pint(stack_t **, unsigned int);
void m_pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void m_swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void m_add(stack_t **, unsigned int);
void m_sub(stack_t **, unsigned int);
void m_div(stack_t **, unsigned int);
void m_mul(stack_t **, unsigned int);
void m_mod(stack_t **, unsigned int);

/*String operations*/
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void stack_err(int error_code, ...);
void string_err(int error_code, ...);
void arith_err(int error_code, ...);

#endif
