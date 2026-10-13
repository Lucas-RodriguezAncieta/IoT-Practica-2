#include <Arduino.h>

#include "LedController.h"
#include "WiFiConnection.h"
#include "TcpActuatorClient.h"

// Pines de LEDs
constexpr uint8_t RED_PIN = 25;
constexpr uint8_t YELLOW_PIN = 26;
constexpr uint8_t GREEN_PIN = 27;

// Credenciales WiFi
const char* WIFI_SSID = "TU_WIFI";
const char* WIFI_PASSWORD = "TU_PASSWORD";

// Servidor TCP
const char* SERVER_IP = "192.168.1.50";
constexpr uint16_t SERVER_PORT = 5000;

LedController ledController(
    RED_PIN,
    YELLOW_PIN,
    GREEN_PIN
);

WiFiConnection wifiConnection(
    WIFI_SSID,
    WIFI_PASSWORD
);

TcpActuatorClient tcpClient(
    SERVER_IP,
    SERVER_PORT,
    ledController
);

void setup() {
    Serial.begin(115200);

    ledController.begin();
    wifiConnection.begin();
    tcpClient.begin();

    Serial.println("Actuator client started");
}

void loop() {
    wifiConnection.update();

    if (wifiConnection.isConnected()) {
        tcpClient.update();
    }

    ledController.update();
}