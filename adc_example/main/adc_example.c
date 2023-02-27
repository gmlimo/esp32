#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h" //Librería para el ADC

#define ADC1_CH4 ADC1_CHANNEL_4

void configADC(void); //Declaro subrutina de configuración del ADC

int val_pot = 0; //Declaro e inicializo la variable de lectura para el ADC
int samples = 32;
int smooth_val = 0;

void app_main(void)

{
    while(1)
    {
        for(int i=0; i<samples; i++)
        {
            smooth_val += val_pot = adc1_get_raw(ADC1_CH4); //Instrucción para leer el canal del ADC
        }
        smooth_val /= samples;
        printf("ADC reading = %i\n", smooth_val); //Imprimo el resultado
        vTaskDelay(300/portTICK_PERIOD_MS); //Retardo de 300 ms al mostrar los mensajes
    }

}

void configADC(void){
    adc1_config_channel_atten(ADC1_CH4, ADC_ATTEN_DB_11); //Atenuación del canal
    adc1_config_width(ADC_WIDTH_BIT_12);                //Resolución del ADC
}

