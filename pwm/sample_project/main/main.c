#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/ledc.h"

#define LED 2

ledc_channel_config_t pwm;

void configPWM(void);

void app_main(void)
{
    char *ourTaskName = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskName, "Hello, starting up!!\n");

    configPWM();
    while (1)
    {
        ledc_set_duty(pwm.speed_mode, pwm.channel, 1500);
        ledc_update_duty(pwm.speed_mode, pwm.channel);
    }
}

void configPWM(void)
{
    
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
