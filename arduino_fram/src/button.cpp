#include "button.hpp"
#include <stdlib.h>
#include <Arduino.h>
#include "engine.hpp"

QuackButton::QuackButton(uint8_t button_pin, unsigned long debounceDelay, EngineManager &engine) : 
              button_pin(button_pin), engine(engine) {
  this->debounceDelay = debounceDelay;
  pinMode(button_pin, INPUT);

}

bool QuackButton::set_action(button_action action) {
  this->action = action;
  return true;
}

bool QuackButton::del_action() {
  this->action = NULL;
  return true;
}

bool QuackButton::execute_action() {
  if (this->action != NULL) {
    this->action(this->engine);
    return true;
  }
  return false;
}

void QuackButton::listen() {
  int reading = digitalRead(this->button_pin);

  if (reading != this->lastButtonState) {
    this->lastDebounceTime = millis();
  }

  if ((millis() - this->lastDebounceTime) > this->debounceDelay) {
    if (reading != this->buttonState) {
      this->buttonState = reading;
      if (this->buttonState == HIGH) {
        this->execute_action();
      }
    }
  }
  this->lastButtonState = reading;
}

