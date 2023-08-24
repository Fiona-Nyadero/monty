#include "monty.h"
/**
 * analyze_row - parses a line of Monty bytecode and execute
 * the corresponding instruction.
 * @line: The line of Monty bytecode to be parsed.
 * @line_number: The line number in the file being processed.
 *
 * Return: EXIT_SUCCESS on successful parsing and execution,
 * EXIT_FAILURE on error.
 */
int analyze_row(const char *line, unsigned int line_number)
{
	char opcode[10];
	int args;
	int args_number = sscanf(line, "%s %d", opcode, &args);

	if (strcmp(opcode, "push") == 0 && args_number == 2)
	{
		push(&stack, args, line_number);
	}
	else if (strcmp(opcode, "pall") == 0 && args_number == 1)
	{
		pall(&stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0 && args_number == 1)
	{
		pint(&stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0 && args_number == 1)
	{
		pop(&stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0 && args_number == 1)
	{
		swap(&stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0 && args_number == 1)
	{
		add(&stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0 && args_number == 1)
        {
                nop(&stack, line_number);
        }
	else if (strcmp(opcode, "sub") == 0 && args_number == 1)
        {
                sub(&stack, line_number);
        }
	else if (strcmp(opcode, "div") == 0 && args_number == 1)
        {
                _divide(&stack, line_number);
        }
	else if (strcmp(opcode, "mul") == 0 && args_number == 1)
        {
                _multiply(&stack, line_number);
	}
	else if (strcmp(opcode, "") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

