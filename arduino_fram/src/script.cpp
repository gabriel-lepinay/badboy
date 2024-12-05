#include "script.hpp"
#include "utils.hpp"

ScriptManager::ScriptManager() {
    // Empty constructor
}

int ScriptManager::parse_cmd(char *tmp_line) {
    char **line = space_split(tmp_line);

    for (int index = 0; QUACK_BINDS[index].key != NULL; index++) {
        if (strcmp(line[0], QUACK_BINDS[index].key) == 0) {
            QUACK_BINDS[index].func(line);
            return 0;
        }
    }
    return 1;
}