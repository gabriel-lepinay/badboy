#ifndef BUTTON_HPP
#define BUTTON_HPP 

typedef struct button_s {
  int button_pin = button_pin;
  int buttonState = 0;
  int lastButtonState = 0;
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 50;
} button_t;

typedef void (*button_action)();

button_t *init_button(int button_pin);
void debounce_button(button_t *button, button_action action, button_action else_action);

#endif