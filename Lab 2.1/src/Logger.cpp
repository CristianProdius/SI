#include <stdio.h>
#include "Logger.h"
#include "ButtonLED.h"
#include "StateVariable.h"

void logSystemState() {
    printf("LED Principal: %s | LED Intermitent: %s | State Variable: %d\n",
           ledState ? "ON" : "OFF",
           !ledState ? "ACTIVE" : "INACTIVE",
           stateVariable);
}

