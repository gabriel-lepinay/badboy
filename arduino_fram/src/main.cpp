#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>
#include "button.hpp"
#include "layout_manager.hpp"
#include <SPI.h>
#include <SD.h>

#define BUTTON_PIN 9
#define SD_CS 34
#define LED_R 10
#define LED_G 11
#define LED_B 12

button_t *button1;
File script;
USBHIDKeyboard Keyboard;

void rgb_led_setup(int r, int g, int b) {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void rgb_led_setcolor(int r, int g, int b) {
  analogWrite(LED_R, 255 - r);
  analogWrite(LED_G, 255 - g);
  analogWrite(LED_B, 255 - b);
}

void open_term_lin() {
  rgb_led_setcolor(0, 0, 255);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  rgb_led_setcolor(0, 255, 0);
}

void open_term_win() { 
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("cmd");
  delay(100);
  Keyboard.press(KEY_RETURN);
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
  rgb_led_setup(LED_R, LED_G, LED_B);
  rgb_led_setcolor(255, 0, 0);

  if (!USB.begin()) {
    Serial.println("Failed to initialize USB!");
    init_failed();
  }
  Keyboard.begin();
  SPI.begin(36, 37, 35, SD_CS);
  if (!SD.begin(SD_CS, SPI)) {
    Serial.println("SD card initialization failed: SD card not found or not accessible.");
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
  delay(1000);
  rgb_led_setcolor(0, 255, 0);
}

void loop() {
  debounce_button(button1, open_term_lin, NULL);
  delay(50);
}