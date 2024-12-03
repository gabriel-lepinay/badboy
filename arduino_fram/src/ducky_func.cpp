#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>

void ducky_key(char **line, int start_i = 0) {
    if (line[start_i + 1] == NULL) {
        printf("No key combo or end of combo, press+relALL: %s\n", line[start_i]);
        return;
    }

    printf("Pressing key: %s\n", line[start_i]);
    ducky_key(line, start_i + 1);
}

void delay(char **line) {
    int delay_time = atoi(line[1]);

    printf("Delaying for %i\n", delay_time);
}

void string(char **line) {
    printf("Typing string: ");
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            printf("%s", line[i]);
            break;
        }
        printf("%s ", line[i]);
    }
}

void stringln(char **line) {
    printf("Typing string: ");
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            printf("%s", line[i]);
            break;
        }
        printf("%s ", line[i]);
    }
    printf("\n");
}

void wait_for_button(char **line) {
    int gpio = atoi(line[1]);

    // while (digitalRead(gpio) == LOW) {
    //     wait
    // }
    printf("Waiting for button press\n");
}

void led(char **line) {
    line[1] == "ON" ? printf("Turning on LED\n") : printf("Turning off LED\n");
}

