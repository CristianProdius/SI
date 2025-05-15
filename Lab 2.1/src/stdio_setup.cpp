#include <Arduino.h>
#include <stdio.h>
#include "stdio_setup.h"

// Redirects printf to Serial
static int serial_putchar(char c, FILE *stream) {
    Serial.write(c);
    return 0;
}

// Redirects scanf to Serial
static int serial_getchar(FILE *stream) {
    while (!Serial.available());
    return Serial.read();
}

void setupSTDIO() {
    Serial.begin(115200);
    static FILE uart_output = {0};
    static FILE uart_input = {0};
    
    fdev_setup_stream(&uart_output, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream(&uart_input, NULL, serial_getchar, _FDEV_SETUP_READ);
    
    stdout = &uart_output;
    stdin = &uart_input;
}
