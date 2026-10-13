#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include "LedController.h"

class TcpActuatorClient {
public:
    TcpActuatorClient(
        const char* serverIp,
        uint16_t serverPort,
        LedController& ledController
    );

    void begin();
    void update();

    bool isConnected() const;

private:
    WiFiClient client;

    const char* serverIp;
    uint16_t serverPort;

    LedController& ledController;

    unsigned long lastReconnectAttempt;

    void connect();
    void registerActuator();

    void processIncomingMessages();
    void processMessage(const String& message);

    void sendAck(const char* stateName);
};