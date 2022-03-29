#include <unity.h>
#include "../led_driver.h" 

void setUp(void) {}
void tearDown(void) {}

void ledsOffAfterCreate(void) {
    uint16_t leds = 0xFFFF;
    leddriver_create(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterCreate);
    return UNITY_END();
}
