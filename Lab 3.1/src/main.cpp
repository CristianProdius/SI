#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "sensor.h"
#include "display.h"

TaskHandle_t TaskReadSensorHandle;
TaskHandle_t TaskDisplayDataHandle;

void TaskReadSensor(void *pvParameters);
void TaskDisplayData(void *pvParameters);

void setup() {
    Serial.begin(9600);

    fdev_setup_stream(&serial_output, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_output;

    xTaskCreate(TaskReadSensor, "Read Sensor", 128, NULL, 2, &TaskReadSensorHandle);
    xTaskCreate(TaskDisplayData, "Display Data", 128, NULL, 1, &TaskDisplayDataHandle);

    vTaskStartScheduler();
}

void loop() {
}
