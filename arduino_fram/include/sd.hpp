#ifndef QUACKSD_HPP
  #define QUACKSD_HPP 
  #include <stdlib.h>
  #include <SPI.h>
  #include <SD.h>

class QuackSd {
  private:
    const uint8_t SCK_GPIO;
    const uint8_t MISO_GPIO;
    const uint8_t MOSI_GPIO;
    const uint8_t CS_GPIO;
    
    File file;
    char buffer[128];

  public:
    QuackSd(uint8_t SCK_GPIO, uint8_t MISO_GPIO, uint8_t MOSI_GPIO, uint8_t CS_GPIO);

    void exec_script(const char *path);

};



#endif