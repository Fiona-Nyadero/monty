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
 * sub - this function subtracts top element from the 2nd top element on stack
 *
 * @stack: points top stack
 * @line_number: instruction appears here
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
  * _divide - this function divides 2nd element by top stack element
  *
  * @stack: points to top of stack
  * @line_number: instruction appears here
  */
void _divide(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
/**
  * _multiply - function that multiplies top stack element 2nd top stack element
  *
  * @stack: points to top stack
  * @line_number: instruction appears here
  */
void _multiply(stack_t **stack, unsigned int line_number)
{
	stack_t *var;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	var = (*stack)->next;
	var->n *= (*stack)->n;
	pop(stack, line_number);
}
