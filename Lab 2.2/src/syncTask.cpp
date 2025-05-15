#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>
#include "syncTask.h"

#define LED_PIN_2 12

extern SemaphoreHandle_t buttonSemaphore;
extern QueueHandle_t dataQueue;

void syncTask(void *pvParameters) {
    pinMode(LED_PIN_2, OUTPUT);
    static int N = 0;

    while (1) {
        if (xSemaphoreTake(buttonSemaphore, portMAX_DELAY) == pdTRUE) {
            N++;
            for (int i = 1; i <= N; i++) {
                xQueueSendToFront(dataQueue, &i, portMAX_DELAY);
                vTaskDelay(pdMS_TO_TICKS(50));
            }
            int zero = 0;
            xQueueSendToFront(dataQueue, &zero, portMAX_DELAY);

            for (int i = 0; i < N; i++) {
                digitalWrite(LED_PIN_2, HIGH);
                vTaskDelay(pdMS_TO_TICKS(300));
                digitalWrite(LED_PIN_2, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
            }
        }
    }
}

void createSyncTask() {
    xTaskCreate(syncTask, "SyncTask", 128, NULL, 1, NULL);
}
