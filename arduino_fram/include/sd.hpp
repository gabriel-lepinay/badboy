#ifndef QUACKSD_HPP
  #define QUACKSD_HPP 
  #include <stdlib.h>
  #include <SPI.h>
  #include <SD.h>
  #include <vector>
  #include <USBHIDKeyboard.h>

  class EngineManager;

  typedef struct quack_binder_s {
    const char *key;
    void (*func)(EngineManager &engine, char **);
  } quack_binder_t;

  typedef struct quack_keys_s {
    const char *key_str;
    int key_int;
  } quack_keys_t;

  void quack_key(EngineManager &engine, char **line, int start_i = 0);

  void delay(EngineManager &engine, char **line);
  void string(EngineManager &engine, char **line);
  void stringln(EngineManager &engine, char **line);
  void wait_for_button(EngineManager &engine, char **line);
  void led(EngineManager &engine, char **line);

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

  quack_binder_t const QUACK_CMD[] = { 
    {"REM", NULL},
    {"DELAY", delay},
    {"STRING", string},
    {"STRINGLN", stringln},
    {"WAIT_BUT", wait_for_button},
    {"LED", led}, // Maybe add color for led debug color
    {NULL, NULL}
  };

  class QuackSd {
    private:
      const uint8_t SCK_GPIO;
      const uint8_t MISO_GPIO;
      const uint8_t MOSI_GPIO;
      const uint8_t CS_GPIO;
      File file;
      char buffer[128];

      EngineManager &engine;

    public:
      QuackSd(uint8_t SCK_GPIO, uint8_t MISO_GPIO, uint8_t MOSI_GPIO, uint8_t CS_GPIO, EngineManager &engine);

      void exec_script(const char *path);
      void mkdir(const char *path);
      bool is_exist(const char *path);
      std::vector<char*> ls(const char *path, int *nb_f = NULL);
      int parse_cmd(char *tmp_line);

  };

#endif