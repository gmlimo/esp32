#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"

#define ADC1_CH4    ADC1_CHANNEL_4

//Subrutina de configuración
void configADC(void);

//Variable para la lectura del ADC
int val_pot = 0;

void app_main(void)
{
    while (1)
    {
        val_pot = adc1_get_raw(ADC1_CH4);
        printf("El ADC lee: %i\n", val_pot);
        vTaskDelay(300/portTICK_PERIOD_MS);
    }

}

void configADC(void)
{
    adc1_config_channel_atten(ADC1_CH4, ADC_ATTEN_DB_11); //Atenuación del canal
    adc1_config_width(ADC_WIDTH_BIT_12); //Resolución del ADC
}