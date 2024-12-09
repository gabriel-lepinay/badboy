#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "sd.hpp"

int count_c(char *line, char c) {
    int count = 0;

    for (int index = 0; line[index] != '\0'; index++) {
        if (line[index] == c) {
            count++;
        }
    }
    return count;
}

void display_tab(char **tab) {
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }
}

char **space_split(char *line) {
    char *tmp_line = strdup(line);
    int nb_word = count_c(tmp_line, ' ') + 1;
    char **word_array = (char**) malloc(sizeof(char *) * (nb_word + 1));

    char *words = strtok(tmp_line, " ");
    int i = 0;

    while (words) {
        word_array[i] = strdup(words);
        words = strtok(NULL, " ");
        i++;
    }
    word_array[i] = NULL;
    free(tmp_line);
    return word_array;
}

void free_tab(char **tab) {
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

void clear_buffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}