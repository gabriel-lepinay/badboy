#include "engine.hpp"
#include "button_actions.hpp"
#include <vector>

EngineManager::EngineManager()
    :   Keyboard(),
        Screen(0x27, 16, 2),
        Sd(SD_SCK, SD_MISO, SD_MOSI, SD_CS, *this),
        Led(LED_R, LED_G, LED_B),
        ButtonUp(BUTTON_UP, 10, *this),
        ButtonOk(BUTTON_OK, 10, *this),
        ButtonDown(BUTTON_DOWN, 10, *this)
        {}

void EngineManager::init() {
    Led.set_color(255, 0, 0);
    Keyboard.begin();

    if (!Sd.is_exist("/scripts")) {
        Serial.println("Scripts directory doesn't exist. Creating one...");
        Sd.mkdir("/scripts");
    }

    ButtonDown.set_action(go_down);
    ButtonOk.set_action(select_script);
    ButtonUp.set_action(go_up);

    Wire.begin(LCD_SDA, LCD_SCL);
    Screen.init();
    Screen.backlight();

    int nb_files;
    this->scripts = Sd.ls("/scripts", &nb_files);
    this->display_scripts();

    Led.set_color(0, 255, 0);
    Serial.println("Engine initialized");
}

void EngineManager::display_scripts() {
    Screen.clear();
    
    Screen.setCursor(0, 0);
    Screen.print('>');
    Screen.setCursor(1, 0);
    Screen.print(this->scripts[this->cur_i]);

    if (this->cur_i < this->scripts.size() - 1) {
        Screen.setCursor(1, 1);
        Screen.print(this->scripts[this->cur_i + 1]);
    }
}