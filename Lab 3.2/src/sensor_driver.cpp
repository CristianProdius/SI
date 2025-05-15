#include "sensor_driver.h"
#include <Arduino.h>

#define SENSOR_PIN A0

void sensor_init() {
    pinMode(SENSOR_PIN, INPUT);
    analogReference(DEFAULT);
}

int read_sensor_raw() {
    return analogRead(SENSOR_PIN);
}
