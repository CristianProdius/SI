#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <stdio.h>
#include <queue.h>
#include <semphr.h>
#include "buttonTask.h"
#include "syncTask.h"
#include "asyncTask.h"

SemaphoreHandle_t buttonSemaphore;
QueueHandle_t dataQueue;

int serial_putchar(char c, FILE *stream) {
    Serial.write(c);
    return 0;
}

void setup() {
    Serial.begin(9600);
    
    static FILE serial_stdout;
    fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_stdout;

    buttonSemaphore = xSemaphoreCreateBinary();
    dataQueue = xQueueCreate(10, sizeof(int));

    createButtonTask();
    createSyncTask();
    createAsyncTask();
}

void loop() {
    // Empty - FreeRTOS handles everything
}

