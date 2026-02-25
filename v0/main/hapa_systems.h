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


//DISPLAY
#define OLED_SDA_GPIO    GPIO_NUM_21
#define OLED_SCL_GPIO    GPIO_NUM_22
#define OLED_I2C_ADDR    0x3C        // Try 0x3D if nothing shows
hapa_err_t display_init(void);
void display_update(const char *line1, const char *line2);
void face_smile(void);
void face_sad(void);
void face_normal(void);
void _crab_display(void);

//BUZZER
#define BUZZER_PIN          GPIO_NUM_23
#define BUZZER_CHANNEL      LEDC_CHANNEL_0
#define BUZZER_TIMER        LEDC_TIMER_1
#define BUZZER_SPEED_MODE   LEDC_LOW_SPEED_MODE
hapa_err_t buzzer_init(void);
void init_beep(void);
//SERVO CONFIG
#define _GAIT_STEPS 11
#define _GAIT_COLS  9
#define _TRAVEL_SPEED 0.25f

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

static const float _forward_gait_test[_GAIT_STEPS][_GAIT_COLS] = {
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
//    0    1    2    3   4    5  6     7
    {180, 140, 120, 180, 00, 60, 60,  00,  200}, // standby
    {160, 140, 120, 160, 00, 60, 60,  20,  200}, // FR_paw + BL_paw raise
    {160, 110, 90, 180, 00, 60, 90,  00,  200}, // FR_arm + BL_arm back
    {180, 110, 120, 180, 00, 60, 90,  20,  200}, // FR_paw + BL_paw drop
    {180, 110, 120, 160, 20, 60, 90,  00,  200}, // FL_paw + BR_paw raise
    {180, 140, 120, 160, 20, 60, 60,  20,  200}, // FR_arm + BL_arm forward
    {180, 140, 90,  160, 20, 90, 60,  20,  200}, // FL_arm + BR_arm back
    {180, 140, 90,  180, 00, 90, 60,  00,  200}, // FL_paw + BR_paw drop
    {160, 140, 90,  180, 00, 90, 60,  20,  200}, // FR_paw + BL_paw raise
    {160, 140, 120, 180, 00, 60, 60,  20,  200}, // FL_arm + BR_arm forward
    {180, 140, 120, 180, 00, 60, 60,  00,  255}, // FR_paw + BL_paw drop
};

static const float _superman_gait[_GAIT_COLS] = {90, 180, 0, 90, 90, 0, 180,  90,  200};
static const float _drone_gait[_GAIT_COLS] = {90, 140, 40, 90, 90, 40, 140,  90,  200};
static const float _crab_up_gait[_GAIT_COLS] = {180, 140, 40, 180, 0, 40, 140,  0,  200};
static const float _crab_down_gait[_GAIT_COLS] = {110, 140, 40, 110, 70, 40, 140,  70,  200};

hapa_err_t servo_init(void);
void _forward_walk(void);
void _forward_walk_slow(void);
void _backward_walk(void);
void _superman(void);
void _drone(void);
void _crab_up(void);
void _crab_down(void);

#endif // HAPA_SYSTEMS_H