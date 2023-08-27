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
	stack_t *first = *stack;
	stack_t *second = NULL;
	stack_t *last = NULL;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	second = (*stack)->next;

	while (first != NULL)
	{
		last = first;
		first = first->next;
	}
	last->next = *stack;
	(*stack)->prev = last;
	second->prev = NULL;
	*stack = second;
	last->next->next = NULL;
}
