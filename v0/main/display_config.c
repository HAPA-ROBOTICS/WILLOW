#include "globalVar.h"

u8g2_t display;

hapa_err_t display_init(void)
{
    u8g2_esp32_hal_t hal = U8G2_ESP32_HAL_DEFAULT;
    hal.bus.i2c.sda       = OLED_SDA_GPIO;
    hal.bus.i2c.scl       = OLED_SCL_GPIO;
   // hal.bus.i2c.clk_speed = 400000;  // 400kHz
    u8g2_esp32_hal_init(hal);

    // Changed to SSD1306!
    u8g2_Setup_ssd1306_i2c_128x64_noname_f(
        &display,
        U8G2_R0,
        u8g2_esp32_i2c_byte_cb,
        u8g2_esp32_gpio_and_delay_cb
    );

    u8g2_SetI2CAddress(&display, (OLED_I2C_ADDR << 1));
    u8g2_InitDisplay(&display);
    u8g2_SetPowerSave(&display, 0);  // Wake display up!

    return HAPA_OK;
}

// Call this any time you want to update the screen
void display_update(const char *line1, const char *line2)
{
    u8g2_ClearBuffer(&display);
    u8g2_SetFont(&display, u8g2_font_ncenB12_tr);
    u8g2_DrawStr(&display, 0, 12, line1);
    if (line2 != NULL) {
        u8g2_DrawStr(&display, 0, 28, line2);
    }
    u8g2_SendBuffer(&display);  // This is your display.display() equivalent!
}

void face_smile(void)
{
    u8g2_ClearBuffer(&display);
    
    // Outline
    u8g2_DrawCircle(&display, 64, 32, 30, U8G2_DRAW_ALL);
    
    // Eyes
    u8g2_DrawFilledEllipse(&display, 50, 24, 4, 4, U8G2_DRAW_ALL); // Left eye
    u8g2_DrawFilledEllipse(&display, 78, 24, 4, 4, U8G2_DRAW_ALL); // Right eye
    
    // Smile
    u8g2_DrawEllipse(&display, 64, 36, 14, 10, U8G2_DRAW_LOWER_RIGHT);
    u8g2_DrawEllipse(&display, 64, 36, 14, 10, U8G2_DRAW_LOWER_LEFT);

    u8g2_SendBuffer(&display);
}

void face_sad(void)
{
    u8g2_ClearBuffer(&display);
    
    // Outline
    u8g2_DrawCircle(&display, 64, 32, 30, U8G2_DRAW_ALL);
    
    // Eyes
    u8g2_DrawFilledEllipse(&display, 50, 24, 4, 4, U8G2_DRAW_ALL); // Left eye
    u8g2_DrawFilledEllipse(&display, 78, 24, 4, 4, U8G2_DRAW_ALL); // Right eye
    
    // Sad mouth
    u8g2_DrawEllipse(&display, 64, 48, 14, 10, U8G2_DRAW_UPPER_RIGHT);
    u8g2_DrawEllipse(&display, 64, 48, 14, 10, U8G2_DRAW_UPPER_LEFT);

    u8g2_SendBuffer(&display);
}

void face_normal(void)
{
    u8g2_ClearBuffer(&display);
    
    // Outline
    u8g2_DrawCircle(&display, 64, 32, 30, U8G2_DRAW_ALL);
    
    // Eyes
    u8g2_DrawFilledEllipse(&display, 50, 24, 4, 4, U8G2_DRAW_ALL); // Left eye
    u8g2_DrawFilledEllipse(&display, 78, 24, 4, 4, U8G2_DRAW_ALL); // Right eye
    
    // Flat mouth
    u8g2_DrawLine(&display, 52, 42, 76, 42);

    u8g2_SendBuffer(&display);
}

void _crab_display(void){
    u8g2_ClearBuffer(&display);

    // Body - wide ellipse
    u8g2_DrawEllipse(&display, 64, 35, 28, 18, U8G2_DRAW_ALL);

    // Shell lines on body
    u8g2_DrawLine(&display, 64, 17, 64, 53); // center line
    u8g2_DrawLine(&display, 50, 20, 50, 50); // left line
    u8g2_DrawLine(&display, 78, 20, 78, 50); // right line

    // Eyes on stalks
    u8g2_DrawLine(&display, 54, 17, 50, 10); // left stalk
    u8g2_DrawLine(&display, 74, 17, 78, 10); // right stalk
    u8g2_DrawFilledEllipse(&display, 50, 8, 4, 4, U8G2_DRAW_ALL); // left eye
    u8g2_DrawFilledEllipse(&display, 78, 8, 4, 4, U8G2_DRAW_ALL); // right eye

    // Left legs - 2 legs, thick (double lines)
    u8g2_DrawLine(&display, 36, 28, 16, 18); // leg 1
    u8g2_DrawLine(&display, 36, 29, 16, 19); // leg 1 thick

    u8g2_DrawLine(&display, 36, 40, 16, 50); // leg 2
    u8g2_DrawLine(&display, 36, 41, 16, 51); // leg 2 thick

    // Right legs - 2 legs, thick (double lines)
    u8g2_DrawLine(&display, 92, 28, 112, 18); // leg 1
    u8g2_DrawLine(&display, 92, 29, 112, 19); // leg 1 thick

    u8g2_DrawLine(&display, 92, 40, 112, 50); // leg 2
    u8g2_DrawLine(&display, 92, 41, 112, 51); // leg 2 thick

    // Left claw
    u8g2_DrawLine(&display, 36, 25, 18, 10);  // arm
    u8g2_DrawLine(&display, 37, 25, 19, 10);  // arm thick
    u8g2_DrawLine(&display, 18, 10, 10, 4);   // claw top
    u8g2_DrawLine(&display, 18, 10, 12, 18);  // claw bottom

    // Right claw
    u8g2_DrawLine(&display, 92, 25, 110, 10); // arm
    u8g2_DrawLine(&display, 91, 25, 109, 10); // arm thick
    u8g2_DrawLine(&display, 110, 10, 118, 4); // claw top
    u8g2_DrawLine(&display, 110, 10, 116, 18);// claw bottom

    u8g2_SendBuffer(&display);
}