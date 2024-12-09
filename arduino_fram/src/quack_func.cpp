#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "engine.hpp"

void type_quack_key(EngineManager &engine, char *key) {
    int cur_key = engine.translate_key(key);

    if (cur_key == -1) {
        engine.Keyboard.press(key[0]);
    } else {
        engine.Keyboard.press(cur_key);
    }
}

void quack_key(EngineManager &engine, char **line, int start_i) {
    
    if (line[start_i + 1] == NULL) {
        type_quack_key(engine, line[start_i]);
        engine.Keyboard.releaseAll();
        return;
    }

    type_quack_key(engine, line[start_i]);
    quack_key(engine, line, start_i + 1);
}

void delay(EngineManager &engine, char **line) {
    int delay_time = atoi(line[1]);

    if (delay_time < 0) {
        Serial.println("Delay time must be positive");
        return;
    }
    delay(delay_time);
}

void string(EngineManager &engine, char **line) {
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            engine.Keyboard.print(line[i]);
            break;
        }
        engine.Keyboard.print(line[i]);
        engine.Keyboard.print(' ');
    }
}

void stringln(EngineManager &engine, char **line) {
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            engine.Keyboard.print(line[i]);
            break;
        }
        engine.Keyboard.print(line[i]);
        engine.Keyboard.print(' ');
    }
    engine.Keyboard.print('\n');
}

void wait_for_button(EngineManager &engine, char **line) {
    engine.ButtonOk.wait_for_press(engine);
}

void led(EngineManager &engine, char **line) {
    if (strcmp(line[1], "ON")) {
        engine.Led.on();
    } else if (strcmp(line[1], "OFF")) {
        engine.Led.on();
    } else {
        Serial.println("Invalid argument");
    }
}

