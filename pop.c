#include "monty.h"
/**
 * pop - this removes the first element on top of stack
 *
 * @stack: this pointer to top of stack.
 * @line_number: instruction appears here.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *var;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	var = *stack;
	*stack = (*stack)->next;
	free(var);
}
