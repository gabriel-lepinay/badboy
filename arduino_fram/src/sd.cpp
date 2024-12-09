#include "utils.hpp"
#include "engine.hpp"
#include "sd.hpp"
#include <vector>

QuackSd::QuackSd(uint8_t SCK_GPIO, uint8_t MISO_GPIO, uint8_t MOSI_GPIO, uint8_t CS_GPIO, EngineManager &engine)
            :   SCK_GPIO(SCK_GPIO),
                MISO_GPIO(MISO_GPIO),
                MOSI_GPIO(MOSI_GPIO),
                CS_GPIO(CS_GPIO),
                engine(engine)
                {
    SPI.begin(SCK_GPIO, MISO_GPIO, MOSI_GPIO, CS_GPIO);

    if (!SD.begin(CS_GPIO, SPI)) {
        engine.init_failed();
    }
}

void QuackSd::exec_script(const char *path) {
    char *full_path = (char *) malloc(strlen(path) + 10);
    full_path[0] = '\0';
    strcat(full_path, "/scripts/");
    strcat(full_path, path);
    this->file = SD.open(full_path);

    if (this->file) {
        while (this->file.available()) {
            this->file.readBytesUntil('\n', this->buffer, sizeof(this->buffer));
            this->parse_cmd(this->buffer);
            clear_buffer(this->buffer, sizeof(this->buffer));
        }
        this->file.close();
    } else {
        Serial.print("Error opening ");
        Serial.print(full_path);
        Serial.println(": not found or not accessible.");
    }
    free(full_path);
}

void QuackSd::mkdir(const char *path) {
    if (SD.mkdir(path)) {
        Serial.println("Directory created.");
    } else {
        Serial.println("Error creating directory.");
    }
}

bool QuackSd::is_exist(const char *path) {
    if (SD.exists(path)) {
        return true;
    } else {
        return false;
    }
}

std::vector<char*> QuackSd::ls(const char *path, int *nb_f) {
    File dir = SD.open(path);
    int nb_files = 0;
    std::vector<char*> files;

    while (true) {
        File entry = dir.openNextFile();
        if (!entry) {
            break;
        }
        files.push_back(strdup(entry.name()));
        nb_files++;
        entry.close();
    }
    if (nb_f != NULL) {
        *nb_f = nb_files;
    }
    dir.close();
    return files;
}

int QuackSd::parse_cmd(char *tmp_line) {
    char **line = space_split(tmp_line);

    for (int index = 0; QUACK_CMD[index].key != NULL; index++) {
        if (strcmp(line[0], QUACK_CMD[index].key) == 0 && QUACK_CMD[index].func != NULL) {
            QUACK_CMD[index].func(this->engine, line);
            return 0;
        }
    }

    for (int index = 0; QUACK_KEYS[index].key_str != NULL; index++) {
        if (strcmp(line[0], QUACK_KEYS[index].key_str) == 0) {
            quack_key(this->engine, line);
            return 0;
        }
    }
    return 1;
}