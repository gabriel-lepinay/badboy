#ifndef BAD_SCRIPT_HPP
    # define BAD_SCRIPT_HPP
    #include <stdlib.h>
    #include <USBHIDKeyboard.h>

    typedef struct quack_binder_s {
        const char *key;
        void (*func)(char **);
    } quack_binder_t;

    typedef struct quack_keys_s {
        const char *key_str;
        int key_int;
    } quack_keys_t;


    void delay(char **line);
    void string(char **line);
    void stringln(char **line);
    void wait_for_button(char **line);
    void led(char **line);

    quack_keys_t const QUACK_KEYS[] = {
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
        {NULL, 0}
    };

    quack_binder_t const QUACK_BINDS[] = {
        {"REM", NULL},
        {"DELAY", delay},
        {"STRING", string},
        {"STRINGLN", stringln},
        {"WAIT_BUT", wait_for_button},
        {"LED", led},
        {NULL, NULL}
    };


    class ScriptManager {
        private:

        public:
            ScriptManager();
            int parse_cmd(char *line);
    };

#endif