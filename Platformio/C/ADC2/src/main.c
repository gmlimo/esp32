#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h" //Librería de los pine E/S
#include "esp_adc/adc_oneshot.h" //Librerías para el ADC
#include "hal/adc_types.h"

int val_pot = 0; //Declaro e inicializo la variable de lectura para el ADC
int LED = 1; //Declaro el pin del LED

void app_main() {
    //Crea la manejadora del ADC (unit handle)
    adc_oneshot_unit_handle_t adc1_handle = NULL;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    //Configuración del canal del ADC
    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_3, &config));

    //Configuración del LED como salida
    gpio_reset_pin(LED); //Inicializo el pin a utilizar
    gpio_set_direction(LED, GPIO_MODE_OUTPUT); //Configuro el pin como salida

     while(1)
    {
        //Lectura directa del ADC
        ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ADC_CHANNEL_3, &val_pot));
        //Control del LED
        gpio_set_level(LED, 1); //Activo el LED
        vTaskDelay(val_pot/portTICK_PERIOD_MS); //Espero val_pot
        gpio_set_level(LED, 0); //Apago el LED
        vTaskDelay(val_pot/portTICK_PERIOD_MS); //Espero val_pot
          
    }
    adc_oneshot_del_unit(adc1_handle);


}