#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * main - This is the entry point to Monty.
 * @argc: Number of args.
 * @argv: Array of args.
 * Return: EXIT_SUCCESS (success) EXIT_FAILURE(failure).
 */

int main(int argc, char *argv[])
{
	char line[100];
	unsigned int line_number = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	initialize_stack(&stack);

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';
		if (parse_line(line, line_number) == EXIT_FAILURE)
		{
			free_stack(&stack);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
