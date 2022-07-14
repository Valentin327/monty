#include "monty.h"
#include <ctype.h>

/**
 * isonlydigit - function that check if a string only
 * contains digits
 * @str: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int isonlydigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i] == 0))
			return (1);
	}
	return (0);
}

/**
 * op_push - function that push an integer
 * onto the stack
 * @stack: pointer to pointer to the beginning
 * of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || isonlydigit(arg))
	{
		dprintf(STDOUT_FILENO, "L%u: usage: push integer\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.len_s++;
}
