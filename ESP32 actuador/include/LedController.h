#pragma once

#include <Arduino.h>

enum class LedState {
    INVALID,
    DANGER,
    WARNING,
    SAFE
};

class LedController {
public:
    LedController(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin);

    void begin();
    void setState(LedState newState);
    void update();

private:
    uint8_t redPin;
    uint8_t yellowPin;
    uint8_t greenPin;

    LedState currentState;

    unsigned long lastBlinkTime;
    bool blinkState;

    void turnAllOff();
    void writeOutputs();
};