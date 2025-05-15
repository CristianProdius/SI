#include <Arduino.h>
#include "LCD.h"

LCD::LCD(int rs, int en, int d4, int d5, int d6, int d7) {
    _rs = rs;
    _en = en;
    _d4 = d4;
    _d5 = d5;
    _d6 = d6;
    _d7 = d7;

    pinMode(_rs, OUTPUT);
    pinMode(_en, OUTPUT);
    pinMode(_d4, OUTPUT);
    pinMode(_d5, OUTPUT);
    pinMode(_d6, OUTPUT);
    pinMode(_d7, OUTPUT);

    // Initialize the LCD
    delay(15);
    sendCommand(0x03);
    delay(5);
    sendCommand(0x03);
    delayMicroseconds(150);
    sendCommand(0x03);
    sendCommand(0x02);
    sendCommand(0x28); // 4-bit mode, 2 lines, 5x8 font
    sendCommand(0x0C); // Display on, cursor off
    sendCommand(0x01); // Clear display
    delay(2);
    sendCommand(0x06); // Increment cursor
}

void LCD::sendCommand(int command) {
    digitalWrite(_rs, LOW);
    writeData(command);
}

void LCD::writeData(int data) {
    digitalWrite(_d4, (data >> 4) & 0x01);
    digitalWrite(_d5, (data >> 5) & 0x01);
    digitalWrite(_d6, (data >> 6) & 0x01);
    digitalWrite(_d7, (data >> 7) & 0x01);
    pulseEnable();
    digitalWrite(_d4, data & 0x01);
    digitalWrite(_d5, (data >> 1) & 0x01);
    digitalWrite(_d6, (data >> 2) & 0x01);
    digitalWrite(_d7, (data >> 3) & 0x01);
    pulseEnable();
}

void LCD::pulseEnable() {
    digitalWrite(_en, HIGH);
    delayMicroseconds(1);
    digitalWrite(_en, LOW);
    delayMicroseconds(100);
}

void LCD::DisplayMessage(const char* message) {
    sendCommand(0x01); // Clear display
    delay(2);
    digitalWrite(_rs, HIGH);
    while (*message) {
        writeData(*message++);
    }
}

void LCD::ClearScreen() {
    sendCommand(0x01); // Clear display
    delay(2);
}