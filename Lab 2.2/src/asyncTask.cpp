#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <stdio.h>
#include "asyncTask.h"

extern QueueHandle_t dataQueue;

void asyncTask(void *pvParameters) {
    int data;

    while (1) {
        if (xQueueReceive(dataQueue, &data, pdMS_TO_TICKS(200))) {
            if (data == 0) {
                printf("\n");
            } else {
                printf("%d ", data);
            }
        }
    }
}

void createAsyncTask() {
    xTaskCreate(asyncTask, "AsyncTask", 128, NULL, 1, NULL);
}
