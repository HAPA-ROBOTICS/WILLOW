#include "globalVar.h"



static void _set_all_servo_int_position(void){
    iot_servo_write_angle(S1_CHAN_SPEED, FRONT_RT_CHAN, SERVO_ANGLE_S1_FRONT_RT_STAND);
    vTaskDelay(pdMS_TO_TICKS(25)); 

    iot_servo_write_angle(S2_CHAN_SPEED, FRONT_RT_CHAN, 180);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S1_CHAN_SPEED, FRONT_LT_CHAN, SERVO_ANGLE_S1_FRONT_LT_STAND);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S2_CHAN_SPEED, FRONT_LT_CHAN, 0);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S1_CHAN_SPEED, BACK_RT_CHAN, SERVO_ANGLE_S1_BACK_RT_STAND);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S2_CHAN_SPEED, BACK_RT_CHAN, 180);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S1_CHAN_SPEED, BACK_LT_CHAN, SERVO_ANGLE_S1_BACK_LT_STAND);
    vTaskDelay(pdMS_TO_TICKS(25)); 
    
    iot_servo_write_angle(S2_CHAN_SPEED, BACK_LT_CHAN, 0);
    vTaskDelay(pdMS_TO_TICKS(25)); 
}

void _forward(void) {
    for (int i = 0; i < _GAIT_STEPS; i++) {
        iot_servo_write_angle(S2_CHAN_SPEED, FRONT_RT_CHAN, _forward_gait[i][0]);
        iot_servo_write_angle(S1_CHAN_SPEED, FRONT_RT_CHAN, _forward_gait[i][1]);
        iot_servo_write_angle(S1_CHAN_SPEED, BACK_RT_CHAN,  _forward_gait[i][2]);
        iot_servo_write_angle(S2_CHAN_SPEED, BACK_RT_CHAN,  _forward_gait[i][3]);
        iot_servo_write_angle(S2_CHAN_SPEED, FRONT_LT_CHAN, _forward_gait[i][4]);
        iot_servo_write_angle(S1_CHAN_SPEED, FRONT_LT_CHAN, _forward_gait[i][5]);
        iot_servo_write_angle(S1_CHAN_SPEED, BACK_LT_CHAN,  _forward_gait[i][6]);
        iot_servo_write_angle(S2_CHAN_SPEED, BACK_LT_CHAN,  _forward_gait[i][7]);
        vTaskDelay(pdMS_TO_TICKS((int)(_forward_gait[i][8] * _TRAVEL_SPEED)));
    }
}

void _backward(void) {
    for (int i = 0; i < _GAIT_STEPS; i++) {
        iot_servo_write_angle(S2_CHAN_SPEED, FRONT_RT_CHAN, _backward_gait[i][0]);
        iot_servo_write_angle(S1_CHAN_SPEED, FRONT_RT_CHAN, _backward_gait[i][1]);
        iot_servo_write_angle(S1_CHAN_SPEED, BACK_RT_CHAN,  _backward_gait[i][2]);
        iot_servo_write_angle(S2_CHAN_SPEED, BACK_RT_CHAN,  _backward_gait[i][3]);
        iot_servo_write_angle(S2_CHAN_SPEED, FRONT_LT_CHAN, _backward_gait[i][4]);
        iot_servo_write_angle(S1_CHAN_SPEED, FRONT_LT_CHAN, _backward_gait[i][5]);
        iot_servo_write_angle(S1_CHAN_SPEED, BACK_LT_CHAN,  _backward_gait[i][6]);
        iot_servo_write_angle(S2_CHAN_SPEED, BACK_LT_CHAN,  _backward_gait[i][7]);
        vTaskDelay(pdMS_TO_TICKS((int)(_backward_gait[i][8] * _TRAVEL_SPEED)));
        
    }
}


hapa_err_t rotor_init(void){

    servo_config_t front_rt_s1 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { FRONT_RT_S1, },
            .ch = { FRONT_RT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t front_rt_s2 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { FRONT_RT_S2, },
            .ch = { FRONT_RT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t front_lt_s1 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { FRONT_LT_S1, },
            .ch = { FRONT_LT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t front_lt_s2 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { FRONT_LT_S2, },
            .ch = { FRONT_LT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t back_rt_s1 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { BACK_RT_S1, },
            .ch = { BACK_RT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t back_rt_s2 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { BACK_RT_S2, },
            .ch = { BACK_RT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t back_lt_s1 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { BACK_LT_S1, },
            .ch = { BACK_LT_CHAN, },
        },
        .channel_number = 1,
    };

    servo_config_t back_lt_s2 = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = SERVO_TIMER,
        .channels = {
            .servo_pin = { BACK_LT_S2, },
            .ch = { BACK_LT_CHAN, },
        },
        .channel_number = 1,
    };

    if(iot_servo_init(S1_CHAN_SPEED, &front_rt_s1) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S2_CHAN_SPEED, &front_rt_s2) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S1_CHAN_SPEED, &front_lt_s1) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S2_CHAN_SPEED, &front_lt_s2) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S1_CHAN_SPEED, &back_rt_s1) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S2_CHAN_SPEED, &back_rt_s2) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S1_CHAN_SPEED, &back_lt_s1) != HAPA_OK) return HAPA_ERR;
    if(iot_servo_init(S2_CHAN_SPEED, &back_lt_s2) != HAPA_OK) return HAPA_ERR;

    _set_all_servo_int_position(); // Set all servos to degrees -- init position


    return HAPA_OK;

}