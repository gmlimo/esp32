#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <driver/gpio.h>


void app_main() {

  //Asignación de pines
  int x = 0;
  int y = 1;
  int a = 2;
  int b = 3;

  //Variables del programa
  int A = 0;
  int B = 0;
  int X = 0;

  char *ourTaskName = pcTaskGetName(NULL);
  ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

  //Configuración de pines
  gpio_reset_pin(x);
  gpio_reset_pin(y);
  gpio_reset_pin(a);
  gpio_reset_pin(b);
  gpio_set_direction(x, GPIO_MODE_OUTPUT);
  gpio_set_direction(y, GPIO_MODE_OUTPUT);
  gpio_set_direction(a, GPIO_MODE_INPUT);
  gpio_set_pull_mode(a, GPIO_PULLUP_ENABLE);
  gpio_set_direction(b, GPIO_MODE_INPUT);
  gpio_set_pull_mode(b, GPIO_PULLUP_ENABLE);

  while(1)
  {
    //Lectura de entrada pasada a variables
    A = gpio_get_level(a);
    B = gpio_get_level(b);

    X = !(A|B);

    //Operación booleana
    if(X){
      gpio_set_level(x, 1);
      printf("Operación NOR en 1 \n");
      vTaskDelay(500/portTICK_PERIOD_MS);
    }
    else{
      gpio_set_level(x, 0);
      printf("Operación NOR en 0 \n");
      vTaskDelay(500/portTICK_PERIOD_MS);
    }

    
  }
}