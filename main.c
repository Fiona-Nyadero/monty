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
	char row[100];
	unsigned int row_num = 0;
	FILE *f_desc;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	f_desc = fopen(argv[1], "r");

	if (f_desc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	initialize_stack(&stack);

	while (fgets(row, sizeof(row), f_desc) != NULL)
	{
		row_num++;
		row[strcspn(row, "\n")] = '\0';
		if (analyze_row(row, row_num) == EXIT_FAILURE)
		{
			free_stack(&stack);
			fclose(f_desc);
			return (EXIT_FAILURE);
		}
	}
	free_stack(&stack);
	fclose(f_desc);
	return (EXIT_SUCCESS);
}
