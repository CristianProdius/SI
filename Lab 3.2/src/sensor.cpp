#include "sensor.h"
#include "sensor_driver.h"
#include "filters.h"
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <math.h>

const int numSamples = 10;
int readings[numSamples];
float weights[numSamples] = {0.1, 0.09, 0.1, 0.11, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

float analogToCelsius(int analogValue) {
    float voltage = analogValue * (5.0 / 1023.0);
    float resistance = (10000.0 * voltage) / (5.0 - voltage);
    return 1.0 / (0.001129148 + 0.000234125 * log(resistance) +
                  0.0000000876741 * pow(log(resistance), 3)) - 273.15;
}

float readFilteredTemperature() {
    for (int i = 0; i < numSamples; i++) {
        readings[i] = read_sensor_raw();
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    saltPepperFilter(readings, numSamples);
    float saltPepperTemp = analogToCelsius(readings[0]);

    float weightedAvg = weightedAverage(readings, weights, numSamples);
    int saturated = saturate((int)weightedAvg, 0, 1023);
    float filteredTemp = analogToCelsius(saturated);

    Serial.print("Raw Value: ");
    Serial.print(readings[0]);
    Serial.print(" | Salt-Pepper Filtered Temp: ");
    Serial.print(saltPepperTemp, 2);
    Serial.print(" °C | Weighted Avg Temp: ");
    Serial.print(analogToCelsius(weightedAvg), 2);
    Serial.print(" °C | Saturated Temp: ");
    Serial.println(filteredTemp, 2);

    return filteredTemp;
}
