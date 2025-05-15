#ifndef FILTERS_H
#define FILTERS_H

void saltPepperFilter(int *samples, int len);
float weightedAverage(int *samples, float *weights, int len);
int saturate(int value, int minVal, int maxVal);

#endif