#pragma once

#include <Arduino.h>
#include <WiFi.h>

class WiFiConnection {
public:
    WiFiConnection(const char* ssid, const char* password);

    void begin();
    void update();

    bool isConnected() const;

private:
    const char* ssid;
    const char* password;

    unsigned long lastReconnectAttempt;

    void connect();
};