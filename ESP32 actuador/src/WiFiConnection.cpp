#include "WiFiConnection.h"

WiFiConnection::WiFiConnection(
    const char* ssid,
    const char* password
)
    : ssid(ssid),
      password(password),
      lastReconnectAttempt(0) {
}

void WiFiConnection::begin() {
    WiFi.mode(WIFI_STA);
    connect();
}

void WiFiConnection::connect() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
}

void WiFiConnection::update() {
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    unsigned long now = millis();

    if (now - lastReconnectAttempt >= 2000) {
        lastReconnectAttempt = now;
        connect();
    }
}

bool WiFiConnection::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}