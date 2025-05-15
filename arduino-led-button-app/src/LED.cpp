void LED::TurnOn() {
  digitalWrite(pin, HIGH);
}

void LED::TurnOff() {
  digitalWrite(pin, LOW);
}

void LED::SetBrightness(int brightness) {
  analogWrite(pin, brightness);
}

LED::LED(int pinNumber) {
  pin = pinNumber;
  pinMode(pin, OUTPUT);
}