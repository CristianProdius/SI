#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include "buttonTask.h"

#define BUTTON_PIN 6
#define LED_PIN_1 13

extern SemaphoreHandle_t buttonSemaphore;

void buttonTask(void *pvParameters) {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN_1, OUTPUT);

    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(10);

    while (1) {
        if (digitalRead(BUTTON_PIN) == LOW) {
            digitalWrite(LED_PIN_1, HIGH);
            vTaskDelay(pdMS_TO_TICKS(1000));
            digitalWrite(LED_PIN_1, LOW);
            xSemaphoreGive(buttonSemaphore);
        }
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void createButtonTask() {
    xTaskCreate(buttonTask, "ButtonTask", 128, NULL, 1, NULL);
}

