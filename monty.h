#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct m_var - struct of the monty interpreter variables
 * @isStackQueue: variable to check if in stack or
 * queue mode
 * @len_s: length of the stack
 */

typedef struct m_var
{
	int isStackQueue;
	size_t len_s;
} var_t;

#define STACK 0
#define QUEUE 1

/* global struct to hold flag for queue and stack length */
extern var_t var;
/**
 * struct stack_s - doubly linked list representation of
 * a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack
 * (or queue)
 * @next: points to the next element of the stack
 * (or queue)
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
 * Description: opcode and its function for
 * stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_node(stack_t **stack, const int n);
void op_push(stack_t **stack, unsigned int line_number);

#endif /* HEADER_H */
