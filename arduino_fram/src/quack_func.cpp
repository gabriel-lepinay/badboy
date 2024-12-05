#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "engine.hpp"

void quack_key(EngineManager &engine, char **line, int start_i) {
    if (line[start_i + 1] == NULL) {
        Serial.print("Typing key: ");
        Serial.println(line[start_i]);
        // engine.Keyboard.press();
        // engine.Keyboard.releaseAll();
        Serial.println("Release combo");
        return;
    }

    Serial.print("Typing key: ");
    Serial.println(line[start_i]);
    // engine.Keyboard.press();
    quack_key(engine, line, start_i + 1);
}

void delay(EngineManager &engine, char **line) {
    int delay_time = atoi(line[1]);

    if (delay_time < 0) {
        Serial.println("Delay time must be positive");
        return;
    }
    Serial.print("Delaying for ");
    Serial.print(delay_time);
    // delay(delay_time);
}

void string(EngineManager &engine, char **line) {
    Serial.print("Typing string: ");
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            Serial.print(line[i]);
            // engine.Keyboard.print(line[i]);
            break;
        }
        // engine.Keyboard.print(line[i]);
        Serial.print(line[i]);
    }
}

void stringln(EngineManager &engine, char **line) {
    Serial.print("Typing string: ");
    for (int i = 1; line[i] != NULL; i++) {
        if (line[i + 1] == NULL) {
            Serial.print(line[i]);
            // engine.Keyboard.print(line[i]);
            break;
        }
        // engine.Keyboard.print(line[i]);
        Serial.print(line[i]);    
    }
    Serial.print("\n"); 
    // engine.Keyboard.print(line[i]);
}


// TODO To implement
void wait_for_button(EngineManager &engine, char **line) {
    int gpio = atoi(line[1]);

    // while (digitalRead(gpio) == LOW) {
    //     wait
    // }
    Serial.println("Waiting for button press");
}
// TODO To implement
void led(EngineManager &engine, char **line) {
    if (strcmp(line[1], "ON")) {
        Serial.println("LED ON");
    } else if (strcmp(line[1], "OFF")) {
        Serial.println("LED OFF");
    } else {
        Serial.println("Invalid argument");
    }
}

