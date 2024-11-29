#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>

#define BUTTON_PIN 10

// Create a keyboard instance
USBHIDKeyboard Keyboard;
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    USB.begin();
    Keyboard.begin();
    delay(1000);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        digitalWrite(LED_BUILTIN, HIGH);
        Keyboard.print("Hello World!");
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
  }

  lastButtonState = reading;
}