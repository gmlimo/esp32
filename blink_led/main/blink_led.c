#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Hello, starting up!!\n" );

    while(1)
    {
        printf("Hello World \n");
        vTaskDelay(200/portTICK_PERIOD_MS);
    }
}
