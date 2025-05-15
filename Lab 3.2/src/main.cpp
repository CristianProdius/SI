#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "sensor.h"           // For readFilteredTemperature()
#include "sensor_driver.h"    // For sensor_init()
#include "display.h"          // For displayTemperature(), initDisplay()

TaskHandle_t TaskReadSensor;
TaskHandle_t TaskDisplayTemp;

float filteredTemperature = 0;

void TaskReadSensorCode(void *pvParameters) {
  (void)pvParameters;

  while (1) {
    filteredTemperature = readFilteredTemperature();
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void TaskDisplayTempCode(void *pvParameters) {
  (void)pvParameters;

  while (1) {
    displayTemperature(filteredTemperature);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  sensor_init();     // <-- Use updated sensor init
  initDisplay();

  xTaskCreate(TaskReadSensorCode, "Sensor", 128, NULL, 2, &TaskReadSensor);
  xTaskCreate(TaskDisplayTempCode, "Display", 128, NULL, 1, &TaskDisplayTemp);
}

void loop() {
  // Empty - FreeRTOS takes care of everything
}
