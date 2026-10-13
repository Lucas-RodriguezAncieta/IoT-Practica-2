#include "LedController.h"

LedController::LedController(
    uint8_t redPin,
    uint8_t yellowPin,
    uint8_t greenPin
)
    : redPin(redPin),
      yellowPin(yellowPin),
      greenPin(greenPin),
      currentState(LedState::INVALID),
      lastBlinkTime(0),
      blinkState(false) {
}

void LedController::begin() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);

    turnAllOff();
}

void LedController::setState(LedState newState) {
    if (currentState == newState) {
        return;
    }

    currentState = newState;
    blinkState = false;
    lastBlinkTime = millis();

    writeOutputs();
}

void LedController::update() {
    unsigned long now = millis();

    if (currentState == LedState::DANGER) {
        if (now - lastBlinkTime >= 150) {
            lastBlinkTime = now;
            blinkState = !blinkState;
            writeOutputs();
        }
    }

    if (currentState == LedState::WARNING) {
        if (now - lastBlinkTime >= 500) {
            lastBlinkTime = now;
            blinkState = !blinkState;
            writeOutputs();
        }
    }
}

void LedController::turnAllOff() {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
}

void LedController::writeOutputs() {
    turnAllOff();

    switch (currentState) {
        case LedState::DANGER:
            digitalWrite(redPin, blinkState ? HIGH : LOW);
            break;

        case LedState::WARNING:
            digitalWrite(yellowPin, blinkState ? HIGH : LOW);
            break;

        case LedState::SAFE:
            digitalWrite(greenPin, HIGH);
            break;

        case LedState::INVALID:
            break;
    }
}