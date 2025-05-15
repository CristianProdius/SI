class LED {
public:
    LED(int pin);
    void TurnOn();
    void TurnOff();
    void SetBrightness(int brightness);

private:
    int pin;
};