#include "monty.h"
/**
 * pstr - Fx prints the string @top of stack
 * @stack: points to top stack
 * @line_number: instruction appears here
 * Return: no return
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *var;
	(void)line_number;

	var = *stack;

	while (var && var->n > 0 && var->n < 128)
	{
		printf("%c", var->n);
		var = var->next;
	}

	printf("\n");
}
/**
 * rotr - rotates the stack to bottom
 * @stack: points to top stack
 * @line_number: instruction appears here
 * Return: no return
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *var = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	var = *stack;

	for (; var->next != NULL; var = var->next)
		;

	var->prev->next = NULL;
	var->next = *stack;
	var->prev = NULL;
	(*stack)->prev = var;
	*stack = var;
}
