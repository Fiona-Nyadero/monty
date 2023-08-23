#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void initialize_stack() {
    top = -1;
}

void free_stack()
{
    }

int parse_line(const char *line, int line_number) {
    char opcode[10];
    int arg;
    int num_args = sscanf(line, "%s %d", opcode, &arg);

    if (strcmp(opcode, "push") == 0 && num_args == 2) {
        
    } else if (strcmp(opcode, "pall") == 0 && num_args == 1) {
        
    } else if (strcmp(opcode, "") != 0) {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        return EXIT_FAILURE;
    }

    return 0;
}
