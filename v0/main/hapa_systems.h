#ifndef HAPA_SYSTEMS_H
#define HAPA_SYSTEMS_H

#include "globalVar.h"

typedef enum{
    HAPA_OK = 0,
    HAPA_ERR = !HAPA_OK
}hapa_err_t;

//initialize hapa systems
hapa_err_t hapa_systems_init(void);
hapa_err_t hapa_systems_spiffs_init(void);



//SERVO CONFIG
#define _GAIT_STEPS 11
#define _GAIT_COLS  9
#define _TRAVEL_SPEED 0.5f

static const float _forward_gait[_GAIT_STEPS][_GAIT_COLS] = {
    {180, 140, 60, 180, 00, 60, 120, 00,  200}, // standby
    {160, 140, 60, 180, 00, 60, 120, 20,  200}, // FR_paw + BL_paw raise
    {160, 170, 60, 180, 00, 60, 90,  00,  200}, // FR_arm + BL_arm forward
    {180, 170, 60, 180, 00, 60, 90,  20,  200}, // FR_paw + BL_paw drop
    {180, 170, 60, 160, 20, 60, 90,  00,  200}, // FL_paw + BR_paw raise
    {180, 140, 60, 160, 20, 60, 120, 20,  200}, // FR_arm + BL_arm back
    {180, 140, 90, 160, 20, 30, 120, 20,  200}, // FL_arm + BR_arm forward
    {180, 140, 90, 180, 00, 30, 120, 00,  200}, // FL_paw + BR_paw drop
    {160, 140, 90, 180, 00, 30, 120, 20,  200}, // FR_paw + BL_paw raise
    {160, 140, 60, 180, 00, 60, 120, 20,  200}, // FL_arm + BR_arm back
    {180, 140, 60, 180, 00, 60, 120, 00,  255}, // FR_paw + BL_paw drop
};

static const float _backward_gait[_GAIT_STEPS][_GAIT_COLS] = {
    {180, 140, 120, 180, 00, 60, 60,  00,  200}, // standby
    {160, 140, 120, 180, 00, 60, 60,  20,  200}, // FR_paw + BL_paw raise
    {160, 110, 120, 180, 00, 60, 90,  00,  200}, // FR_arm + BL_arm back
    {180, 110, 120, 180, 00, 60, 90,  20,  200}, // FR_paw + BL_paw drop
    {180, 110, 120, 160, 20, 60, 90,  00,  200}, // FL_paw + BR_paw raise
    {180, 140, 120, 160, 20, 60, 60,  20,  200}, // FR_arm + BL_arm forward
    {180, 140, 90,  160, 20, 90, 60,  20,  200}, // FL_arm + BR_arm back
    {180, 140, 90,  180, 00, 90, 60,  00,  200}, // FL_paw + BR_paw drop
    {160, 140, 90,  180, 00, 90, 60,  20,  200}, // FR_paw + BL_paw raise
    {160, 140, 120, 180, 00, 60, 60,  20,  200}, // FL_arm + BR_arm forward
    {180, 140, 120, 180, 00, 60, 60,  00,  255}, // FR_paw + BL_paw drop
};

#define SERVO_ANGLE_S1_FRONT_RT_STAND         (float)140
#define SERVO_ANGLE_S1_FRONT_LT_STAND         (float)40
#define SERVO_ANGLE_S1_BACK_RT_STAND          (float)60
#define SERVO_ANGLE_S1_BACK_LT_STAND          (float)120



#define SERVO_TIMER         LEDC_TIMER_0

#define S1_CHAN_SPEED       LEDC_LOW_SPEED_MODE
#define S2_CHAN_SPEED       LEDC_HIGH_SPEED_MODE

#define FRONT_RT_CHAN       LEDC_CHANNEL_1
#define FRONT_LT_CHAN       LEDC_CHANNEL_2
#define BACK_RT_CHAN        LEDC_CHANNEL_3
#define BACK_LT_CHAN        LEDC_CHANNEL_4


#define BACK_RT_S1           GPIO_NUM_32
#define BACK_RT_S2           GPIO_NUM_33
#define FRONT_RT_S1          GPIO_NUM_25
#define FRONT_RT_S2          GPIO_NUM_26

#define BACK_LT_S1           GPIO_NUM_27
#define BACK_LT_S2           GPIO_NUM_14
#define FRONT_LT_S1          GPIO_NUM_12
#define FRONT_LT_S2          GPIO_NUM_13

hapa_err_t rotor_init(void);
void _forward(void);
void _backward(void);

#endif // HAPA_SYSTEMS_H