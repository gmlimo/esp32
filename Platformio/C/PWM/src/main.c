#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/ledc.h" //Librería para el PWM

int LED = 1; //Pin de salida del PWM

ledc_channel_config_t pwm; //Declaro instancia global para configurar el PWM

void configPWM(void); //Declaro función para configurar el PWM

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

    configPWM(); //Configuro el PWM
    while (1)
    {
        ledc_set_duty(pwm.speed_mode, pwm.channel, 3200); //Aquí escribo la cantidad que cambia el ancho de pulso 
        ledc_update_duty(pwm.speed_mode, pwm.channel); //El número debe ser entre 0 - 4095
    }
}

//Función que configura el PWM
void configPWM(void)
{
    //Aquí se configura el canal del PWM y el pin a utilizar
        pwm.channel = LEDC_CHANNEL_0,
        pwm.gpio_num = LED, //Pin de salida del PWM 
        pwm.hpoint = 0,
        pwm.timer_sel = LEDC_TIMER_0,
        pwm.speed_mode = LEDC_LOW_SPEED_MODE;

        ledc_channel_config(&pwm);

    //Aquí se configura resolución del PWM y la frecuencia.    
    ledc_timer_config_t timer = {
        .duty_resolution = LEDC_TIMER_12_BIT, //Resolución (duty cycle varía entre 0 - 4095)
        .freq_hz = 1000, //Frecuencia de la señal (periodo de 1 ms)
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&timer);
}