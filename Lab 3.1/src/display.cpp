#include "display.h"
#include "sensor.h"
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

FILE serial_output;

int serial_putchar(char c, FILE *stream) {
    Serial.write(c);
    return 0;
}

void TaskDisplayData(void *pvParameters) {
    const TickType_t xFrequency = pdMS_TO_TICKS(500);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (1) {
        printf("Temperature: %.2f °C\n", temperatureC);

        if (temperatureC > 30.0) {
            printf("WARNING: Temperature too high!\n");
        }

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

