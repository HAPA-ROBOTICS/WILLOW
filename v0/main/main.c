

#include "globalVar.h"



void app_main(void)
{

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);


    printf("Initializing HAPA Systems...\n");
    if(hapa_systems_init() != HAPA_OK){
        printf("Failed to initialize systems\n");
        return;
    }
    vTaskDelay(pdMS_TO_TICKS(500));
    init_beep();
    
    vTaskDelay(pdMS_TO_TICKS(1500)); 

    
    while (1)
    {
        _drone();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _superman();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _crab_up();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _crab_down();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _crab_up();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _crab_down();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _drone();
        vTaskDelay(pdMS_TO_TICKS(2000));
        _crab_up();
        vTaskDelay(pdMS_TO_TICKS(2000));

        for(int i = 0; i < 20; i++){
            _forward_walk();
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        vTaskDelay(pdMS_TO_TICKS(100));

    }
       

    
}
