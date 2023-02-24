#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <driver/gpio.h>

#define LED 2 // LED on the GPIO2
#define S1 4 //Set button on the GPIO4
#define S2 5 //Reset button on the GPIO5

void app_main(void)
{
  int x = 0;
  int y = 0;  
  char *ourTaskName = pcTaskGetName(NULL);
  ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

  gpio_reset_pin(LED); //Resets the pins previous configurations
  gpio_reset_pin(S1);
  gpio_reset_pin(S2);
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); //LED as an output
  gpio_set_direction(S1, GPIO_MODE_INPUT); // Set pin as an input
  gpio_set_pull_mode(S1, GPIO_PULLUP_ENABLE);
  gpio_set_direction(S2, GPIO_MODE_INPUT); // Reset pin as an input
  gpio_set_pull_mode(S2, GPIO_PULLUP_ENABLE);

  while(1)
  {
    x = gpio_get_level(S1); //Reads the set button
    y = gpio_get_level(S2); //Reads the reset button

    if(x==1) //If set is activated then...
    {
     while(y==0) //While the reset is inactive do this...
     {
        gpio_set_level(LED, 1); //Sets the LED on
        ESP_LOGI(ourTaskName, "Inside the while!!\n");
        y = gpio_get_level(S2); //Update the while condition, in this case the reset button
        vTaskDelay(500/portTICK_PERIOD_MS);
     }
     
    }
    else
    {
        gpio_set_level(LED, 0); //Resets the LED (turn it off)
        ESP_LOGI(ourTaskName, "Outside the while!\n");
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
  }
     
}

