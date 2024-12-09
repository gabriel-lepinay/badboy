#ifndef QUACKLED_HPP
    #define QUACKLED_HPP
    #include <Arduino.h>

    typedef struct rgb_s {
        int r;
        int g;
        int b;
    } rgb_t;


    class QuackLed {
        private:
            const uint8_t r_pin;
            const uint8_t g_pin;
            const uint8_t b_pin;

            rgb_t curr_color = {0, 0, 0};
            rgb_t last_color = {0, 0, 0};

        public:
            int status = 0;
            
            QuackLed(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin);

            void set_color(int r, int g, int b);
            void on();
            void off();
            void set_last_color();
    };

#endif