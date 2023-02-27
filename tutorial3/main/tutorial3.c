#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define LED1 2
#define LED2 3
#define SW1 0

void app_main(void)
{
    int x = 0;
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

    gpio_reset_pin(LED1);
    gpio_reset_pin(LED2);
    gpio_reset_pin(SW1);
    gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
    gpio_set_direction(SW1, GPIO_MODE_INPUT);
    gpio_set_pull_mode(SW1, GPIO_PULLUP_ENABLE);

    while(1)
    {
        x = gpio_get_level(SW1);

        if(x==1)
        {
            gpio_set_level(LED1, 1);
            gpio_set_level(LED2, 0);
            ESP_LOGI(ourTaskName, "LED1 esta prendido y LED2 esta apagado\n");
            vTaskDelay(500/portTICK_PERIOD_MS);
        }
        else
        {
            gpio_set_level(LED1, 0);
            gpio_set_level(LED2, 1);
            printf("LED1 esta apagado y LED2 esta prendido \n");
            vTaskDelay(500/portTICK_PERIOD_MS);   
        }
    }
}
