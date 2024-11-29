#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    int cur_state = 0;
    int old_state = 0;
    int debounce_delay = 50; // in ms
    int led_status = 0;
    gpio_set_direction(GPIO_NUM_9, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_15, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_10, GPIO_MODE_INPUT);
    // gpio_set_direction(GPIO_NUM_11, GPIO_MODE_INPUT);
    
    gpio_set_level(GPIO_NUM_15, 1);

    while (1) {
        cur_state = gpio_get_level(GPIO_NUM_10);

        if (cur_state != old_state) {
            vTaskDelay(debounce_delay / portTICK_PERIOD_MS);
            if (gpio_get_level(GPIO_NUM_10)) {
                led_status = !led_status;
            }
            old_state = cur_state;
        }
        gpio_set_level(GPIO_NUM_9, led_status);
        
        vTaskDelay(10);
    }
}
