#include <stdio.h>
#include <string.h>
#include <unity.h>

static char output[5];
void setUp(void) {
    memset(output, 0, sizeof(output));
}

void tearDown(void) {
}

void NoFormatOperation (void)
{
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(NoFormatOperation);
    return UNITY_END();
}
