#include "globalVar.h"
#include "hapa_systems.h"  



hapa_err_t hapa_systems_init(void){

    
    if(servo_init() != HAPA_OK) return HAPA_ERR;
    if(buzzer_init() != HAPA_OK) return HAPA_ERR;
    //if(display_init() != HAPA_OK) return HAPA_ERR;
    return HAPA_OK;
}
