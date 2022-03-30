#include <unity.h>
#include "../led_driver.h" 

static uint16_t virtualLEDs;
void setUp(void) {
    leddriver_create(&virtualLEDs);
}
void tearDown(void) {}

void ledsOffAfterCreate(void) {
    uint16_t virtualLEDs = 0xFFFF;
    leddriver_create(&virtualLEDs);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLEDs);
}

void turnOnLedOne(void) {
    leddriver_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(0x1, virtualLEDs);
}

void turnOffLedOne(void) {
    leddriver_turn_on(1);
    leddriver_turn_off(1);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtualLEDs);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterCreate);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOffLedOne);
    return UNITY_END();
}
