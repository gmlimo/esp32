#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/adc.h"
#include "driver/ledc.h"

#define LED 2

adc1_channel_t adc_pot = ADC1_CHANNEL_4; //declaración del canal ADC a utilizar

ledc_channel_config_t pwm;

void configHW(void);

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

    int val_pot = 0;
    configHW();
    
    while(1)
    {
        val_pot = adc1_get_raw(adc_pot); //Lectura del ADC
        printf("ADC reading = %i\n", val_pot);

        ledc_set_duty(pwm.speed_mode, pwm.channel, val_pot);
        ledc_update_duty(pwm.speed_mode, pwm.channel);
        vTaskDelay(300/portTICK_PERIOD_MS);
    }

}

void configHW(void)
{
    //Configuración del ADC
    adc1_config_channel_atten(adc_pot, ADC_ATTEN_DB_11); 
    adc1_config_width(ADC_WIDTH_BIT_12);                
    
    //Configuración del PWM
        pwm.channel = LEDC_CHANNEL_0,
        pwm.gpio_num = LED,
        pwm.hpoint = 0,
        pwm.timer_sel = LEDC_TIMER_0,
        pwm.speed_mode = LEDC_LOW_SPEED_MODE;

        ledc_channel_config(&pwm);

    ledc_timer_config_t timer = {
        .duty_resolution = LEDC_TIMER_12_BIT,
        .freq_hz = 1000,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&timer);
}


