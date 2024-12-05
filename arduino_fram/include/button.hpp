#ifndef QUACKBUTTON_HPP
  #define QUACKBUTTON_HPP 
  #include <stdlib.h>

class EngineManager;

typedef void (*button_action)(EngineManager &engine);

class QuackButton {
  private:
    const uint8_t button_pin;
    int buttonState = 0;
    int lastButtonState = 0;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;

    EngineManager &engine;
    button_action action = NULL;

  public:
    QuackButton(uint8_t button_pin, unsigned long debounceDelay, EngineManager &engine);
    bool set_action(button_action action);
    bool del_action();
    bool execute_action();
    void listen();
};



#endif