#include "monty.h"
/**
 * push - This funtion pushes new elements to the stack.
 * @stack: pointer to top of stack.
 * value: value to push.
 * @line_number: where instruction appears.
 */
stack_t *stack = NULL;
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_n;
	(void)line_number;

	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_n->n = value;
	new_n->prev = NULL;
	new_n->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_n;
	}
	*stack = new_n;
}
/**
 * pall - This function prints values of stack.
 * @stack: pointer to top of stack.
 * @line_number: where instruction appears.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * initialize_stack - This function configures the stack.
 * @stack: pointer to top of stack.
 */
void initialize_stack(stack_t **stack)
{
	*stack = NULL;
}
/**
 * free_stack - Function that frees memory allocated to stack.
 * @stack: pointer to top of stack.
 */
void free_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
