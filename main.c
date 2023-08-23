#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    char line[100];
    int line_number;
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    initialize_stack();
    line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        line[strcspn(line, "\n")] = '\0'; /* Remove trailing newline*/

        if (parse_line(line, line_number) == EXIT_FAILURE) {
            free_stack(); /* Free allocated memory */
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    free_stack(); /* Free allocated memory */
    fclose(file);
    return 0;
}
