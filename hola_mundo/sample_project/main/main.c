#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void app_main(void)
{
   char *ourTaskName = pcTaskGetName(NULL);
   ESP_LOGI(ourTaskName, "¡Hola! ¿Cómo estas?... ");

   while (1)
   {
      printf("Hola Mundo \n");
      vTaskDelay(500 / portTICK_PERIOD_MS);
   }

}
