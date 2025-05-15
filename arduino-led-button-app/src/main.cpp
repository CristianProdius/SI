#include <Arduino.h>
#include "LED.h"
#include "Button.h"

LED myLed(9); // LED connected to pin 9
Button myButton(2); // Button connected to pin 2

void setup() {
  Serial.begin(9600);
  myLed.TurnOff(); // Ensure LED is off at startup
}

void loop() {
  if (myButton.IsPressed()) {
    myLed.Toggle(); // Change LED state when button is pressed
    delay(200); // Debounce delay
  }
}