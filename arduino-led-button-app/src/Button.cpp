#include <Arduino.h>
#include "Button.h"

Button::Button(int pin) {
    pinMode(pin, INPUT);
    _pin = pin;
}

bool Button::IsPressed() {
    return digitalRead(_pin) == HIGH;
}

int Button::GetState() {
    return digitalRead(_pin);
}