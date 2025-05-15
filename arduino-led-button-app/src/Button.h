#ifndef BUTTON_H
#define BUTTON_H

class Button {
public:
    Button(int pin);
    void Begin();
    bool IsPressed();
    int GetState();

private:
    int buttonPin;
    int buttonState;
};

#endif // BUTTON_H