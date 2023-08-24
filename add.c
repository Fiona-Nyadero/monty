#include "monty.h"

/**
 * add - This function adds top two elements of the stack.
 * @stack: points to top of stack.
 * @line_number: instruction appears here
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *var;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	var = (*stack)->next;
	var->n += (*stack)->n;
	pop(stack, line_number);
}
