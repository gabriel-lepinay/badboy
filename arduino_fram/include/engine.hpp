#ifndef ENGINE_HPP
    #define ENGINE_HPP
    #include <USBHIDKeyboard.h>
    #include <LiquidCrystal_I2C.h>
    #include "button.hpp"
    #include "rgb.hpp"
    #include "sd.hpp"

    // Buttons
    #define BUTTON_OK 9
    // RGB LED
    #define LED_R 10
    #define LED_G 11
    #define LED_B 12
    // LCD screen
    #define LCD_SDA 4
    #define LCD_SCL 5
    // SD card
    #define SD_SCK 36
    #define SD_MISO 37
    #define SD_MOSI 35
    #define SD_CS 34

    class EngineManager {
        public:
            USBHIDKeyboard Keyboard;
            LiquidCrystal_I2C Screen;
            // QuackButton ButtonUp;
            // QuackButton ButtonDown;
            QuackLed Led;
            QuackSd Sd;
            QuackButton ButtonOk;
            
            EngineManager();
            void init();
    };

#endif