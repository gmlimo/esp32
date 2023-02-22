#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <driver/gpio.h>

#define LED 2
#define S1 4
#define S2 5

void app_main(void)
{
  int x = 0;
  int y = 0;  
  char *ourTaskName = pcTaskGetName(NULL);
  ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

  gpio_reset_pin(LED);
  gpio_reset_pin(S1);
  gpio_reset_pin(S2);
  gpio_set_direction(LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(S1, GPIO_MODE_INPUT);
  gpio_set_pull_mode(S1, GPIO_PULLUP_ENABLE);
  gpio_set_direction(S2, GPIO_MODE_INPUT);
  gpio_set_pull_mode(S2, GPIO_PULLUP_ENABLE);

  while(1)
  {
    x = gpio_get_level(S1);
    y = gpio_get_level(S2);

    if(x==1)
    {
     while(y==0)
     {
        gpio_set_level(LED, 1);
        ESP_LOGI(ourTaskName, "Inside the while!!\n");
        y = gpio_get_level(S2);
        vTaskDelay(500/portTICK_PERIOD_MS);
     }
     
    }
    else
    {
        gpio_set_level(LED, 0);
        ESP_LOGI(ourTaskName, "Outside the while!\n");
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
  }
     
}

