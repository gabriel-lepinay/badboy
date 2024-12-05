#include <Arduino.h>
#include "engine.hpp"

EngineManager engine;

void setup() {
  Serial.println("Setup starting..");
  Serial.begin(115200);
  
  // debuging
  while (!Serial) { 
    delay(10);
  }

  engine.init();

  Serial.println("Setup complete");
}


void loop() {
  engine.ButtonOk.listen();
  delay(50);
}