#include "RelayControl.h"

void setup() {
  Serial.begin(9600);
  setupRelay(); 
  Serial.println("Enter command (e.g., 'relay on' or 'relay off'):");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    processCommand(input.c_str());
  }
}
