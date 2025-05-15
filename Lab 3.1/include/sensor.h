#ifndef SENSOR_H
#define SENSOR_H

extern volatile float temperatureC;
void TaskReadSensor(void *pvParameters);

#endif

