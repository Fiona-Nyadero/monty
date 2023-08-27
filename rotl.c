#include "monty.h"

/**
* _rotl - This function rotates stack to top.
*
* @stack: points linked-list head
* @line_number: The line
* Return: 0
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		exit(EXIT_FAILURE);

	first = *stack;
	second = first->next;
	last = first;

	while (last->next != NULL)
		last = last->next;

	last->next = first;
	first->prev = last;
	*stack = second;
	second->prev = NULL;
	first->next = NULL;
}
