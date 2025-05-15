#include "BlinkingLED.h"
#include "ButtonLED.h"
#include "StateVariable.h"
#include <Arduino.h>

const int blinkLedPin = 12;
unsigned long lastBlinkTime = 0;
bool blinkState = false;

void setupBlinkingLED() {
    pinMode(blinkLedPin, OUTPUT);
}

void handleBlinkingLED() {
    if (!ledState) {
        if (millis() - lastBlinkTime >= (stateVariable * 500)) {
            blinkState = !blinkState;
            digitalWrite(blinkLedPin, blinkState);
            lastBlinkTime = millis();
        }
    } else {
        digitalWrite(blinkLedPin, LOW);
    }
}

