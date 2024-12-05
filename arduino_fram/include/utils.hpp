#ifndef UTILS_HPP
    #define UTILS_HPP
    #include <Arduino.h>

    int count_c(char *line, char c);
    void display_tab(char **tab);
    char **space_split(char *line);
    void free_tab(char **tab);
    void clear_buffer(char *buffer, int size);
    void init_failed(int debug_led = LED_BUILTIN);
    
#endif