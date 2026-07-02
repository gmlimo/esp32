#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h" //Para mostrar mensajes
#include "driver/gpio.h" //Para usar los GPIO pins

#define LED 0 //GPIO0 corresponds to pin 0

void app_main() {
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Iniciando el programa de parpadeo de led... \n");

    gpio_reset_pin(LED); //Inicializo el pin a utilizar
    gpio_set_direction(LED, GPIO_MODE_OUTPUT); //Configuro el pin como salida

    while(1)
    {
        gpio_set_level(LED, 1); //Activo el LED
        printf("LED prendido \n");
        vTaskDelay(1000/portTICK_PERIOD_MS); //Espero 1s
        gpio_set_level(LED, 0); //Apago el LED
        printf("LED apagado \n");
        vTaskDelay(1000/portTICK_PERIOD_MS); //Espero 1s
    }

};