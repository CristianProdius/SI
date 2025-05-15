#include "RelayControl.h"
#include <Arduino.h>
#include <string.h>

const int relayPin = 2;

void setupRelay() {
  pinMode(relayPin, OUTPUT);
  Serial.println("Relay Pin Initialized");
}

void processCommand(const char* command) {
  if (strcmp(command, "relay on") == 0) {
    digitalWrite(relayPin, HIGH); 
    Serial.println("Relay ON");
  }
  else if (strcmp(command, "relay off") == 0) {
    digitalWrite(relayPin, LOW);
    Serial.println("Relay OFF");
  }
  else {
    Serial.println("Invalid Command");
  }
}
