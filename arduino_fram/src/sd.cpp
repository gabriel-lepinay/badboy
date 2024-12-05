#include "utils.hpp"
#include "sd.hpp"

QuackSd::QuackSd(uint8_t SCK_GPIO, uint8_t MISO_GPIO, uint8_t MOSI_GPIO, uint8_t CS_GPIO) : 
                    SCK_GPIO(SCK_GPIO), MISO_GPIO(MISO_GPIO), MOSI_GPIO(MOSI_GPIO), CS_GPIO(CS_GPIO) {
    SPI.begin(SCK_GPIO, MISO_GPIO, MOSI_GPIO, CS_GPIO);
    if (!SD.begin(CS_GPIO, SPI)) {
        Serial.println("SD card initialization failed: SD card not found or not accessible.");
    }
}


void QuackSd::exec_script(const char *path) {
    this->file = SD.open(path);

    if (this->file) {
        while (this->file.available()) {
            this->file.readBytesUntil('\n', this->buffer, sizeof(this->buffer));
            Serial.println(this->buffer);
            clear_buffer(this->buffer, sizeof(this->buffer));
        }
        this->file.close();
    } else {
        Serial.println("Error opening file: not found or not accessible.");
    }
}