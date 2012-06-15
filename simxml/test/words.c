
#include <stdio.h>

#include "../src/parser.h"


int main(int argc, char **argv) {
    input_source_t *input;
    string_t *args;
    string_t *arg;
    string_t str;
	int n;

    if (argc < 2) {
        printf("words <file-name>\n");
        return -1;
    }

    input = file_source_new(argv[1], NULL);
    ASSERT(input);

    str = parse_string(input, 0, NULL);
    printf("First string: <%s>\n", str);

    while (1) {
        printf("At [%d, %d]\n", input->row, input->column);

		n = 0;
        args = parse_arguments(input, PARSE_ARG_QUOTED, &n);

        if (args == NULL) {
            printf("Stopped: %s\n", input->last_error);
            return -2;
        }

		printf("    . ");
        for (arg = args; *arg; ++arg) {
            printf("%s . ", *arg);
        }

        free_arguments(args);

        printf("\n");
    }

    return 0;
}
