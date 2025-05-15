#include "ButtonLED.h"
#include <Arduino.h>

const int ledPin = 13;
bool ledState = false;

void setupButtonLED() {
    pinMode(ledPin, OUTPUT);
}

void handleButtonLED() {
    digitalWrite(ledPin, ledState);
}

void simulateButtonPress() {
    ledState = !ledState;
}
