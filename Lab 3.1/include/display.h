#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>

extern FILE serial_output;
void TaskDisplayData(void *pvParameters);
int serial_putchar(char c, FILE *stream);

#endif


