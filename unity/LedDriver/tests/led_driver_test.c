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

void turnOnMultipleLeds(void) {
    leddriver_turn_on(9);
    leddriver_turn_on(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLEDs);
}

void turnOffAnyLed(void) {
    leddriver_turn_all_on();
    leddriver_turn_off(8);
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLEDs);
}

void turnOnAllLeds(void) {
    leddriver_turn_all_on();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLEDs);
}

void ledMemoryIsNotReadable(void) {
    virtualLEDs = 0xffff;
    leddriver_turn_on(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLEDs);
}

void upperAndLowerBounds(void) {
    leddriver_turn_on(1);
    leddriver_turn_on(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLEDs);
}

void outOfBoundsTurnOnChangesNothing(void) {
    leddriver_turn_on(-1);
    leddriver_turn_on(0);
    leddriver_turn_on(17);
    leddriver_turn_on(3141);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtualLEDs);
}

void outOfBoundsTurnOffChangesNothing(void) {
    leddriver_turn_all_on();
    leddriver_turn_off(-1);
    leddriver_turn_off(0);
    leddriver_turn_off(17);
    leddriver_turn_off(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLEDs);
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterCreate);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOffLedOne);
    RUN_TEST(turnOnMultipleLeds);
    RUN_TEST(turnOnAllLeds);
    RUN_TEST(ledMemoryIsNotReadable);
    RUN_TEST(turnOffAnyLed);
    RUN_TEST(upperAndLowerBounds);
    RUN_TEST(outOfBoundsTurnOnChangesNothing);
    RUN_TEST(outOfBoundsTurnOffChangesNothing);
    return UNITY_END();
}
