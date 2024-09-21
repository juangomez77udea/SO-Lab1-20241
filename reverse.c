#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}

int main(int argc, char *argv[]) {
    FILE *input = NULL;
    FILE *output = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **lines = NULL;
    size_t num_lines = 0;

    // Handling too many arguments
    if (argc > 3) {
        print_error("usage: reverse <input> <output>");
        exit(1);
    }

    // Handling input file
    if (argc >= 2) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    } else {
        input = stdin;
    }

    // Handling output file
    if (argc == 3) {
        if (strcmp(argv[1], argv[2]) == 0) {
            print_error("Input and output file must differ");
            exit(1);
        }
        output = fopen(argv[2], "w");
        if (output == NULL) {
            fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
            fclose(input);
            exit(1);
        }
    } else {
        output = stdout;
    }

    // Reading lines from input and storing them
    while ((read = getline(&line, &len, input)) != -1) {
        char **temp = realloc(lines, (num_lines + 1) * sizeof(char *));
        if (temp == NULL) {
            print_error("malloc failed");
            free(line);
            fclose(input);
            if (argc == 3) fclose(output);
            exit(1);
        }
        lines = temp;
        lines[num_lines] = strdup(line);
        if (lines[num_lines] == NULL) {
            print_error("malloc failed");
            free(line);
            fclose(input);
            if (argc == 3) fclose(output);
            exit(1);
        }
        num_lines++;
    }
    free(line);

    // Writing lines in reverse order
    for (size_t i = num_lines; i > 0; i--) {
        fprintf(output, "%s", lines[i - 1]);
        free(lines[i - 1]);
    }
    free(lines);

    // Closing files
    fclose(input);
    if (argc == 3) fclose(output);

    return 0;
}
