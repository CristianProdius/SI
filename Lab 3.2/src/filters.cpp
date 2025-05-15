#include "filters.h"
#include <math.h>
#include <Arduino.h>

void saltPepperFilter(int *samples, int len) {
  int sum = 0;
  for (int i = 0; i < len; i++) sum += samples[i];
  int avg = sum / len;
  for (int i = 0; i < len; i++) {
    if (abs(samples[i] - avg) > 50) samples[i] = avg;
  }
}

float weightedAverage(int *samples, float *weights, int len) {
  float sum = 0;
  for (int i = 0; i < len; i++) {
    sum += samples[i] * weights[i];
  }
  return sum;
}

int saturate(int value, int minVal, int maxVal) {
  if (value < minVal) return minVal;
  if (value > maxVal) return maxVal;
  return value;
}
