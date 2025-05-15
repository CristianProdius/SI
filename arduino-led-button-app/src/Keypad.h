#ifndef KEYPAD_H
#define KEYPAD_H

class Keypad {
public:
    Keypad(int pin);
    char ReadKey();
    int GetKeyState();

private:
    int _pin;
};

#endif // KEYPAD_H