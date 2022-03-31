#include "led_driver.h"

static uint16_t *leds_address;
static uint16_t leds_image;

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON 
};

static int16_t ledNumberToBit(uint8_t led_number) {
    return (1 << (led_number - 1));
}

void leddriver_create (uint16_t *leds)
{
    leds_address = leds;
    leds_image = ALL_LEDS_OFF;
    *leds_address = leds_image;
}

void leddriver_turn_on(uint8_t led_number)
{
    leds_image |= ledNumberToBit(led_number);
    *leds_address = leds_image;
}

void leddriver_turn_off(uint8_t led_number)
{
    leds_image &= ~(ledNumberToBit(led_number));
    *leds_address = leds_image;
}

void leddriver_turn_all_on(void)
{
    leds_image = ALL_LEDS_ON;
    *leds_address = leds_image;
}
