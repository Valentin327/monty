#include "monty.h"

/**
 * add_node - function that add a node to a
 * circular linked list
 * @stack: pointer to pointer to the beginning
 * of the circular linked list
 * @n: value to add to the new node
 *
 * Description: the function will to the
 * beginning if in stack mode and the end
 * if in queue mode
 *
 * Return: pointer to the new node, or NULL
 * on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.queue == STACK || var.len_s == 0)
		*stack = new;
	return (new);
}
