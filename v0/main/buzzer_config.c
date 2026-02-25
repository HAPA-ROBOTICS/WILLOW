#include "globalVar.h"



hapa_err_t buzzer_init(void) {
    ledc_timer_config_t timer = {
        .speed_mode      = BUZZER_SPEED_MODE,
        .timer_num       = BUZZER_TIMER,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .freq_hz         = 2000,
        .clk_cfg         = LEDC_AUTO_CLK
    };
    if (ledc_timer_config(&timer) != ESP_OK) return HAPA_ERR;

    ledc_channel_config_t channel = {
        .speed_mode = BUZZER_SPEED_MODE,
        .channel    = BUZZER_CHANNEL,
        .timer_sel  = BUZZER_TIMER,
        .gpio_num   = BUZZER_PIN,
        .duty       = 0,
        .hpoint     = 0
    };
    if (ledc_channel_config(&channel) != ESP_OK) return HAPA_ERR;

    return HAPA_OK;
}

static void _beep(uint32_t frqz, uint32_t time){
    ledc_set_freq(BUZZER_SPEED_MODE, BUZZER_TIMER, frqz);
    ledc_set_duty(BUZZER_SPEED_MODE, BUZZER_CHANNEL, 512); // 50% duty
    ledc_update_duty(BUZZER_SPEED_MODE, BUZZER_CHANNEL);
    vTaskDelay(pdMS_TO_TICKS(time));
    ledc_set_duty(BUZZER_SPEED_MODE, BUZZER_CHANNEL, 0);   // off
    ledc_update_duty(BUZZER_SPEED_MODE, BUZZER_CHANNEL);
}

void init_beep(void){
  _beep(5000, 250);
  vTaskDelay(pdMS_TO_TICKS(50));
  _beep(5000, 750);
  vTaskDelay(pdMS_TO_TICKS(50));

}
