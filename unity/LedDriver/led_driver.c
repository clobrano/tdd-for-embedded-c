#include <stdbool.h>
#include "led_driver.h"

static uint16_t *leds_address;
static uint16_t leds_image;

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON 
};

const static uint8_t FIRST_LED = 1;
const static uint8_t LAST_LED = 16;

static int16_t ledNumberToBit(uint8_t led_number) {
    return (1 << (led_number - 1));
}

static void updateHardware() {
    *leds_address = leds_image;
}

static bool isLedNUmberOutOfBound(uint8_t led_number) {
    return (led_number < FIRST_LED || led_number > LAST_LED);
}

void leddriver_create (uint16_t *leds)
{
    leds_address = leds;
    leds_image = ALL_LEDS_OFF;
    updateHardware();
}

void leddriver_turn_on(uint8_t led_number)
{
    if (isLedNUmberOutOfBound(led_number))
        return;
    leds_image |= ledNumberToBit(led_number);
    updateHardware();
}

void leddriver_turn_off(uint8_t led_number)
{
    if (isLedNUmberOutOfBound(led_number))
        return;
    leds_image &= ~(ledNumberToBit(led_number));
    updateHardware();
}

void leddriver_turn_all_on(void)
{
    leds_image = ALL_LEDS_ON;
    updateHardware();
}
