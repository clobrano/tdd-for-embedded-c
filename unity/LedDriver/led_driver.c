#include "led_driver.h"

static uint16_t *leds_address;

static int16_t ledNumberToBit(uint8_t led_number) {
    return (1 << (led_number - 1));
}

void leddriver_create (uint16_t *leds)
{
    leds_address = leds;
    *leds_address = 0x0;
}

void leddriver_turn_on(uint8_t led_number)
{
    *leds_address |= ledNumberToBit(led_number);
}

void leddriver_turn_off(uint8_t led_number)
{
    *leds_address = 0;
}

void leddriver_turn_all_on(void)
{
    *leds_address = 0xFFFF;
}
