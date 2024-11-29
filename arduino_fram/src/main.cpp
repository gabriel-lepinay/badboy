#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>
#include "button.hpp"

#define BUTTON_PIN 10
#define BUTTON_PIN2 11
#define LED 9

button_t *button1;
button_t *button2;

USBHIDKeyboard Keyboard;

void printHelloWorld() {
  Keyboard.print("Hello World!");
}

void printNimp() {
  Keyboard.print("azertyuiop");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
  USB.begin();
  Keyboard.begin();
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Setup complete");
  Serial.println("Button initalisation...");

  button1 = init_button(BUTTON_PIN);
  button2 = init_button(BUTTON_PIN2);

  if (button1 == NULL || button2 == NULL) {
    while (1) {
      digitalWrite(BUILTIN_LED, HIGH);
      delay(1000);
      digitalWrite(BUILTIN_LED, LOW);
      delay(1000);
    }
  }
}

void loop() {
  debounce_button(button1, printHelloWorld, NULL);
  debounce_button(button2, printNimp, NULL);
  delay(50);
}