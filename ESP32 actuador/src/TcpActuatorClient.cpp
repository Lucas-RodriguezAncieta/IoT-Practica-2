#include "TcpActuatorClient.h"

TcpActuatorClient::TcpActuatorClient(
    const char* serverIp,
    uint16_t serverPort,
    LedController& ledController
)
    : serverIp(serverIp),
      serverPort(serverPort),
      ledController(ledController),
      lastReconnectAttempt(0) {
}

void TcpActuatorClient::begin() {
    connect();
}

void TcpActuatorClient::connect() {
    if (WiFi.status() != WL_CONNECTED) {
        return;
    }

    Serial.println("Connecting to TCP server...");

    if (client.connect(serverIp, serverPort)) {
        Serial.println("TCP connected");
        registerActuator();
    }
}

void TcpActuatorClient::registerActuator() {
    if (!client.connected()) {
        return;
    }

    client.println("REGISTER ACTUATOR");

    Serial.println("TX: REGISTER ACTUATOR");
}

void TcpActuatorClient::update() {
    if (!client.connected()) {
        unsigned long now = millis();

        if (now - lastReconnectAttempt >= 2000) {
            lastReconnectAttempt = now;
            connect();
        }

        return;
    }

    processIncomingMessages();
}

bool TcpActuatorClient::isConnected() const {
    return client.connected();
}

void TcpActuatorClient::processIncomingMessages() {
    while (client.available()) {
        String message = client.readStringUntil('\n');

        message.trim();

        if (message.length() > 0) {
            Serial.print("RX: ");
            Serial.println(message);

            processMessage(message);
        }
    }
}

void TcpActuatorClient::processMessage(const String& message) {
    if (message == "SET DANGER") {
        ledController.setState(LedState::DANGER);
        sendAck("DANGER");
        return;
    }

    if (message == "SET WARNING") {
        ledController.setState(LedState::WARNING);
        sendAck("WARNING");
        return;
    }

    if (message == "SET SAFE") {
        ledController.setState(LedState::SAFE);
        sendAck("SAFE");
        return;
    }

    if (message == "SET INVALID") {
        ledController.setState(LedState::INVALID);
        sendAck("INVALID");
        return;
    }

    Serial.print("Unknown command: ");
    Serial.println(message);
}

void TcpActuatorClient::sendAck(const char* stateName) {
    if (!client.connected()) {
        return;
    }

    client.print("ACK ");
    client.println(stateName);

    Serial.print("TX: ACK ");
    Serial.println(stateName);
}