#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>
#include "button.hpp"
#include "layout_manager.hpp"
#include <SPI.h>
#include <SD.h>

#define BUTTON_PIN 10
#define LED 9
#define SD_CS 34

button_t *button1;
File script;
USBHIDKeyboard Keyboard;


void open_term_lin() {
  digitalWrite(LED, HIGH);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(LED, LOW);
}

void open_term_win() { 
  digitalWrite(LED, HIGH);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("cmd");
  delay(100);
  Keyboard.press(KEY_RETURN);
  digitalWrite(LED, LOW);
}

void init_failed() {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void setup() {
  Serial.println("Setup starting..");
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);

  if (!USB.begin()) {
    Serial.println("Failed to initialize USB!");
    init_failed();
  }
  Keyboard.begin();
  SPI.begin(36, 37, 35, SD_CS);
  if (!SD.begin(SD_CS, SPI)) {
    Serial.println("SD card initialization failed!");
    init_failed();
  }

  script = SD.open("/scripts/open_term.ducky", FILE_WRITE);

  if (!script) {
    Serial.println("Error opening script file: Script not found or not accessible.");
  }
  
  while (script.available()) {
    Serial.println(script.read());
  }
  
  script.close();

  button1 = init_button(BUTTON_PIN);

  if (button1 == NULL) {
    Serial.println("Button initialization failed!");
    init_failed();
  }
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Setup complete");
}

void loop() {
  debounce_button(button1, open_term_lin, NULL);

  delay(50);
}