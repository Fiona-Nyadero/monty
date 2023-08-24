#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to top of stack.
 * @line_number: Where instruction appears.
 */
void pint(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }

        printf("%d\n", (*stack)->n);
}
