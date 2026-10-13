#pragma once

#include <Arduino.h>
#include <WiFiClient.h>

#include "LedController.h"

class TcpActuatorClient {
public:
    TcpActuatorClient(
        const char* ip,
        uint16_t port,
        LedController& leds,
        unsigned long retryMs,
        unsigned long connectTimeoutMs
    );

    void update(
        unsigned long now,
        bool wifiConnected
    );

private:
    void disconnect(unsigned long now);

    void processLine(
        const char* line,
        unsigned long now
    );

    bool sendLine(const char* line);

    const char* ip_;
    uint16_t port_;

    LedController& leds_;

    unsigned long retryMs_;
    unsigned long timeoutMs_;

    unsigned long lastAttempt_ = 0;
    unsigned long lastCommand_ = 0;

    bool registered_ = false;
    bool waitingOk_ = false;
    bool discarding_ = false;

    char buffer_[129]{};
    size_t length_ = 0;

    WiFiClient client_;
};