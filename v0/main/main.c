

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
    vTaskDelay(pdMS_TO_TICKS(2000)); // Delay to ensure all systems are initialized

    
    while (1)
    {
        _forward();
        vTaskDelay(pdMS_TO_TICKS(50)); // Delay between movements
    }
    

    
}
