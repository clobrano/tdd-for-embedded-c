#include <unity.h>
#include "../led_driver.h" 

void setUp(void) {}
void tearDown(void) {}

void ledsOffAfterCreate(void) {
    uint16_t leds = 0xFFFF;
    leddriver_create(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

void turnOnLedOne(void) {
    uint16_t leds;
    leddriver_create(&leds);
    leddriver_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(0x1, leds);
}

void turnOffLedOne(void) {
    uint16_t leds;
    leddriver_create(&leds);
    leddriver_turn_off(1);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterCreate);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOffLedOne);
    return UNITY_END();
}
