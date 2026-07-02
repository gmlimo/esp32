#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <driver/gpio.h>


void app_main() {

    //Asignación de pines
    int LED1 = 0;
    int LED2 = 1;
    int SW = 3;

    int x = 0;  //Declaro e inicializo variable
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "¡Hola! Iniciando...\n"); //Muestro mensaje en los registros

    //Configuración de pines
    gpio_reset_pin(LED1); //Inicializo pines de la tarjeta
    gpio_reset_pin(LED2);
    gpio_reset_pin(SW);
    gpio_set_direction(LED1, GPIO_MODE_OUTPUT); //Declaro salidas
    gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
    gpio_set_direction(SW, GPIO_MODE_INPUT); //Declaro mi entrada
    gpio_set_pull_mode(SW, GPIO_PULLDOWN_ENABLE);

    while(1)
  {
    x = gpio_get_level(SW); //Leo el pin 3

    if(x==1){
      gpio_set_level(LED1, 1);
      gpio_set_level(LED2, 0);
      printf("LED1 en el pin 0 esta activado y el LED2 en el pin 1 esta desactivado \n");
      vTaskDelay(500/portTICK_PERIOD_MS);
    }
    else{
      gpio_set_level(LED1, 0);
      gpio_set_level(LED2, 1);
      printf("LED1 en el pin 0 esta desactivado y el LED2 en el pin 1 esta activado \n");
      vTaskDelay(500/portTICK_PERIOD_MS);
    }
    
    
  }


}