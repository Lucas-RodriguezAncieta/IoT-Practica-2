#include <Arduino.h>
#include <unity.h>

#include "LedController.h"

namespace {

LedController leds(25, 26, 27);

void test_initial_and_transitions() {
    TEST_ASSERT_EQUAL_INT(
        static_cast<int>(LedState::INVALID),
        static_cast<int>(leds.state())
    );

    leds.setState(LedState::DANGER, 0);

    TEST_ASSERT_EQUAL_INT(
        static_cast<int>(LedState::DANGER),
        static_cast<int>(leds.state())
    );

    leds.setState(LedState::SAFE, 200);

    TEST_ASSERT_EQUAL_INT(
        static_cast<int>(LedState::SAFE),
        static_cast<int>(leds.state())
    );

    leds.setState(LedState::INVALID, 300);

    TEST_ASSERT_EQUAL_INT(
        static_cast<int>(LedState::INVALID),
        static_cast<int>(leds.state())
    );
}

}

void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_initial_and_transitions);

    UNITY_END();
}

void loop() {
}