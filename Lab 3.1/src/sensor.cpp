#include "sensor.h"
#include <Arduino.h>
#include <math.h>
#include <Arduino_FreeRTOS.h>


#define TEMP_SENSOR_PIN A0
#define BETA 3950        // Beta value for the NTC thermistor
#define R0 10000         // Resistance at 25°C
#define T0 298.15        // 25°C in Kelvin
#define VCC 5.0          // Reference voltage
#define Rseries 10000    // Series resistor (10kΩ)

volatile float temperatureC = 0.0;

void TaskReadSensor(void *pvParameters) {
    const TickType_t xFrequency = pdMS_TO_TICKS(1000);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (1) {
        int rawValue = analogRead(TEMP_SENSOR_PIN);
        float voltage = rawValue * (VCC / 1023.0);
        float resistance = (Rseries * voltage) / (VCC - voltage);

        // Steinhart-Hart Equation
        temperatureC = 1 / (0.001129148 + (0.000234125 * log(resistance)) + (0.0000000876741 * pow(log(resistance), 3))) - 273.15;

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
