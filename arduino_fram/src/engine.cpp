#include "engine.hpp"

void toggleLed(EngineManager &engine) {
    if (engine.Led.status == 0) {
        Serial.println("Led on");
        engine.Led.on();
        engine.Led.status = 1;
    } else {
        Serial.println("Led off");
        engine.Led.off();
        engine.Led.status = 0;
    }
}

EngineManager::EngineManager()
    :   ButtonOk(BUTTON_OK, 50, *this),
        Led(LED_R, LED_G, LED_B),
        Sd(SD_SCK, SD_MISO, SD_MOSI, SD_CS),
        Screen(0x27, 16, 2),
        Keyboard()
        {}

void EngineManager::init() {
    ButtonOk.set_action(toggleLed);
    Led.set_color(0, 0, 255);
    Sd.exec_script("/scripts/lin_yes.ds");
    Wire.begin(LCD_SDA, LCD_SCL);
    Screen.init();
    Screen.backlight();
    Screen.setCursor(0,0);
    Screen.print("Hello, world!");
    Serial.println("Engine initialized");
}