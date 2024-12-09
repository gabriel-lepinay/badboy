#include <Arduino.h>
#include "engine.hpp"

EngineManager engine;

void setup() {
  // For debugging
  // Serial.begin(115200);
  // while (!Serial) { 
  //   delay(10);
  // }

  engine.init();
}

void loop() {
  engine.ButtonOk.listen();
  engine.ButtonDown.listen();
  engine.ButtonUp.listen();
  delay(10);
}