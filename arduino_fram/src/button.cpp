#include "button.hpp"
#include <stdlib.h>
#include <Arduino.h>

button_t *init_button(int button_pin) {
  button_t *button = (button_t *) malloc(sizeof(button_t));

  if (button == NULL) {
    Serial.println("Memory allocation failed!");
    return NULL;
  }

  button->button_pin = button_pin;
  button->buttonState = 0;
  button->lastButtonState = 0;
  button->lastDebounceTime = 0;
  button->debounceDelay = 50;

  pinMode(button_pin, INPUT);
  return button;
}

void debounce_button(button_t *button, button_action action, button_action else_action) {
    int reading = digitalRead(button->button_pin);

    if (reading != button->lastButtonState) {
        button->lastDebounceTime = millis();
    }

    if ((millis() - button->lastDebounceTime) > button->debounceDelay) {
        if (reading != button->buttonState) {
            button->buttonState = reading;
            if (button->buttonState == HIGH) {
              if (action != NULL) {
                action();
              }
            } else {
              if (else_action != NULL) {
                else_action();
              }
            }
        }
    }
    button->lastButtonState = reading;
}