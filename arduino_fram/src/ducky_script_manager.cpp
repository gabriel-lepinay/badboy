#include <string.h>
#include "utils.hpp"
#include "ducky_binder.hpp"

int ducky_parser(char *tmp_line) {
    char **line = space_split(tmp_line);

    for (int index = 0; ducky_binder[index].key != NULL; index++) {
        if (strcmp(line[0], ducky_binder[index].key) == 0) {
            ducky_binder[index].func(line);
            return 0;
        }
    }
    return 1;
}

// int main(int argc, char **argv) {
//     if (argc < 2) {
//         printf("Usage: %s '<testline>'\n\t testline: Should be a ducky script line to test.\n", argv[0]);
//         return 1;
//     }

//     char **line = space_split(argv[1]);

//     if (parser(line) == 1) {
//         printf("Error: Command not found.\n");
//     }

//     free_tab(line);
//     return 0;
// }