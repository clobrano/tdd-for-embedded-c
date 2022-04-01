#ifndef  __LED_DRIVER__
#define  __LED_DRIVER__
#include <stdint.h>

void leddriver_create (uint16_t *leds);
void leddriver_turn_on(int led);
void leddriver_turn_off(int led);
void leddriver_turn_all_on(void);

#endif  /*__LED_DRIVER__*/
