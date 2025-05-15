#include <Arduino.h>
#include <stdio.h>
#include <stdio_setup.h>
#include "ButtonLED.h"
#include "BlinkingLED.h"
#include "StateVariable.h"
#include "SerialInput.h"
#include "Logger.h"

void setup() {
    setupSTDIO();
    setupButtonLED();
    setupBlinkingLED();
    setupStateVariable();
    
    printf("System Initialized.\n");
}

void loop() {
    handleSerialInput();
    handleButtonLED();
    handleBlinkingLED();
    handleStateVariable();
    logSystemState(); 
    delay(100); 
}

