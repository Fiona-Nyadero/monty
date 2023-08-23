#include "monty.h"
/**
 * parse_line - parses a line of Monty bytecode and execute
 * the corresponding instruction.
 * @line: The line of Monty bytecode to be parsed.
 * @line_number: The line number in the file being processed.
 *
 * Return: EXIT_SUCCESS on successful parsing and execution,
 * EXIT_FAILURE on error.
 */
int parse_line(const char *line, unsigned int line_number)
{
char opcode[10];
int arg;
int num_args = sscanf(line, "%s %d", opcode, &arg);
if (strcmp(opcode, "push") == 0 && num_args == 2)
{
push(&stack, arg, line_number);
}
else if (strcmp(opcode, "pall") == 0 && num_args == 1)
{
pall(&stack, line_number);
}
else if (strcmp(opcode, "") != 0)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
