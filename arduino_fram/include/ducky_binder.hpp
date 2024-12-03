#ifndef DUCKY_BINDER_HPP
    #define DUCKY_BINDER_HPP
    #include "ducky_func.hpp"
    #include <stdio.h>
    #include <USBHIDKeyboard.h>
    
    typedef struct ducky_binder_s {
        const char *key;
        void (*func)(char **);
    } ducky_binder_t;

    typedef struct ducky_keys_s {
        char *key_str;
        int key_int;
    } ducky_keys_t;

    ducky_keys_t DUCKY_KEYS[] = {
        // Cursor keys
        {"UP", KEY_UP_ARROW},
        {"DOWN", KEY_DOWN_ARROW},
        {"LEFT", KEY_LEFT_ARROW},
        {"RIGHT", KEY_RIGHT_ARROW},
        {"PAGE_UP", KEY_PAGE_UP},
        {"PAGE_DOWN", KEY_PAGE_DOWN},
        {"HOME", KEY_HOME},
        {"END", KEY_END},
        {"INSERT", KEY_INSERT},
        {"DELETE", KEY_DELETE},
        {"BACKSPACE", KEY_BACKSPACE},
        {"TAB", KEY_TAB},
        // System keys
        {"ENTER", KEY_RETURN},
        {"ESCAPE", KEY_ESC},
        // Basic modifier keys
        {"CTRL", KEY_LEFT_CTRL},
        {"SHIFT", KEY_LEFT_SHIFT},
        {"ALT", KEY_LEFT_ALT},
        {"GUI", KEY_LEFT_GUI},
        {NULL, NULL}
    };



    ducky_binder_t ducky_binder[] = {
        {"REM", NULL},
        {"DELAY", delay},
        {"STRING", string},
        {"STRINGLN", stringln},
        {"WAIT_BUT", wait_for_button},
        {"LED", led},
        {NULL, NULL}
    };

#endif