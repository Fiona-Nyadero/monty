#include "monty.h"
/**
 * swap - this swaps the top two stack elements
 *
 * @stack: points to top of stack
 * @line_number: instruction appears here
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = (*stack)->next;
	top->prev = second;
	top->next = second->next;
	second->prev = NULL;
	second->next = top;

	if (top->next != NULL)
		top->next->prev = top;

	*stack = second;
}
/**
 * _sub - subtracts the top element from the second top element of the stack
 *
 * @stack: pointer to top of stack
 * @line_number: where instruction appears
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
