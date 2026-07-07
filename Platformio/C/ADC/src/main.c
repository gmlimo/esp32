#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h" //Librerías para el ADC
#include "hal/adc_types.h"


int val_pot = 0; //Declaro e inicializo las variables de lectura para el ADC
int pot_out = 0;

void app_main(void)

{
    //Create unit handle
    adc_oneshot_unit_handle_t adc1_handle = NULL;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    //Configure ADC Channel
    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_3, &config));

    //ADC calibration
    adc_cali_handle_t cali_handle = NULL;
    adc_cali_curve_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_1,
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_12,
    };
    ESP_ERROR_CHECK(adc_cali_create_scheme_curve_fitting(&cali_config, &cali_handle));

    while(1)
    {
        //Read raw channel
        ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ADC_CHANNEL_3, &val_pot));
        printf("ADC_CHANNEL_3 (GPIO 3) reads: %d \n", val_pot);
        adc_cali_raw_to_voltage(cali_handle, val_pot, &pot_out);
        printf("Milivolt output after calibration: %d \n", pot_out);  
        vTaskDelay(200);   
    }
    adc_oneshot_del_unit(adc1_handle);
    adc_cali_delete_scheme_curve_fitting(cali_handle);
}

