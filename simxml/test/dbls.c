
#include <stdio.h>

#include "../src/parser.h"


int main(int argc, char **argv) {
    input_source_t *input;
    double val;

    if (argc < 2) {
        printf("words <file-name>\n");
        return -1;
    }

    input = file_source_new(argv[1], NULL);
    ASSERT(input);

    do {
        if (parse_real(input,
                  PARSE_NUM_COMMA
                | PARSE_NUM_UNDERLINE
                | PARSE_REAL_EXP
                , &val) < -1)
            break;

        printf("%lf\n", val);
    } while (1);

    printf("Stopped: %s\n", input->last_error);
    printf("\n");

    return 0;
}
