#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h" //Logs messages
#include "driver/gpio.h" //For use of the GPIO (General Purpose Input-Output)

#define LED 9 //GPIO9 corresponds to pin 9

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Starting blink led program... \n");

    gpio_reset_pin(LED); //To reset any previous configuration
    gpio_set_direction(LED, GPIO_MODE_OUTPUT); //To configure LED pin to output

    while(1)
    {
        gpio_set_level(LED, 1); //Turns the LED on
        vTaskDelay(1000/portTICK_PERIOD_MS); //Wait 1s
        gpio_set_level(LED, 0); //Turns the LED off
        vTaskDelay(1000/portTICK_PERIOD_MS); //Wait 1s
    }
}
