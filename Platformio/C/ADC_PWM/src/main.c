#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h" //Librerías para el ADC
#include "hal/adc_types.h"
#include "driver/ledc.h" //Librería para el PWM


int val_pot = 0; //Declaro e inicializo la variable de lectura para el ADC
int LED = 1; //Salida del PWM

adc_oneshot_unit_handle_t adc1_handle; //Declaro instancia global para configurar el ADC
void configADC(void); //Declaro función para configurar el ADC

ledc_channel_config_t pwm; //Declaro instancia global para configurar el PWM
void configPWM(void); //Declaro función para configurar el PWM


void app_main(void)
{
    configADC(); //Configuro ADC
    configPWM(); //Configuro el PWM

    while(1)
    {
        //Lectura del ADC
        ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ADC_CHANNEL_3, &val_pot));
        printf("ADC_CHANNEL_3 (GPIO 3) reads: %d \n", val_pot);
        ledc_set_duty(pwm.speed_mode, pwm.channel, val_pot); //Aquí escribo la cantidad que cambia el ancho de pulso 
        ledc_update_duty(pwm.speed_mode, pwm.channel); //A través de la variable val_pot que tiene el ADC
        vTaskDelay(200);   
    }
    //Elimina recursos para liberar memoria
    adc_oneshot_del_unit(adc1_handle);
}

//Función que configura el ADC
void configADC(void) 
{
 //Crea la unidad manejadora
    adc1_handle = NULL;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    //Configura el canal del ADC 
    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_3, &config));
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
