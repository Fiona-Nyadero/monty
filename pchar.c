#include "monty.h"

/**
 * _pchar - this function prints char at the top of stack
 * followed by a new line
 * @stack: points to the top stack
 * @line_number: instruction appears here
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
