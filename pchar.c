#include "monty.h"

/**
 * _pchar - this function prints char at the top of stack
 * followed by a new line
 * @stack: points to the top stack
 * @line_number: instruction appears here
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (value < 0 || value >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}
