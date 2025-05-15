#include "display.h"
#include <stdio.h>

void initDisplay() {
    // Add code to initialize your display
    printf("Display Initialized\n");  // or LCD init code
}

void displayTemperature(float temperature) {
    printf("Filtered Temp: %.2f°C\n", temperature);
}