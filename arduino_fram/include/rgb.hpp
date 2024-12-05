#ifndef QUACKLED_HPP
    #define QUACKLED_HPP
    #include <Arduino.h>

    class QuackLed {
        private:
            const uint8_t r_pin;
            const uint8_t g_pin;
            const uint8_t b_pin;

        public:
            int status = 0;
            
            QuackLed(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin);

            void set_color(int r, int g, int b);
            void on();
            void off();
    };

#endif