# Arduino LED Button Application

This project is an Arduino application that changes the state of an LED when a button is pressed. It is designed with modularity in mind, allowing for easy reuse of peripheral components such as LED, Button, LCD, and Keypad.

## Project Structure

```
arduino-led-button-app
├── src
│   ├── main.cpp        # Entry point of the application
│   ├── LED.cpp         # Implementation of the LED class
│   ├── LED.h           # Header file for the LED class
│   ├── Button.cpp      # Implementation of the Button class
│   ├── Button.h        # Header file for the Button class
│   ├── LCD.cpp         # Implementation of the LCD class
│   ├── LCD.h           # Header file for the LCD class
│   ├── Keypad.cpp      # Implementation of the Keypad class
│   └── Keypad.h        # Header file for the Keypad class
```

## Setup Instructions

1. **Install Arduino IDE**: Make sure you have the Arduino IDE installed on your computer.
2. **Clone the Repository**: Clone this repository to your local machine.
3. **Open the Project**: Open the `arduino-led-button-app` folder in the Arduino IDE.
4. **Connect Your Arduino**: Connect your Arduino board to your computer.
5. **Select the Board**: In the Arduino IDE, select the appropriate board from the Tools menu.
6. **Upload the Code**: Upload the code from `src/main.cpp` to your Arduino board.

## Usage

- Press the button connected to the Arduino to toggle the LED state.
- The LED will turn on when the button is pressed and turn off when pressed again.

## Peripheral Details

### LED
- **Class**: `LED`
- **Methods**:
  - `TurnOn()`: Turns the LED on.
  - `TurnOff()`: Turns the LED off.
  - `SetBrightness(int brightness)`: Sets the brightness of the LED.

### Button
- **Class**: `Button`
- **Methods**:
  - `IsPressed()`: Checks if the button is currently pressed.
  - `GetState()`: Returns the current state of the button.

### LCD
- **Class**: `LCD`
- **Methods**:
  - `DisplayMessage(const char* message)`: Displays a message on the LCD.
  - `ClearScreen()`: Clears the LCD screen.

### Keypad
- **Class**: `Keypad`
- **Methods**:
  - `ReadKey()`: Reads the key pressed on the keypad.
  - `GetKeyState()`: Returns the current state of the keys on the keypad.

## License

This project is licensed under the MIT License. Feel free to modify and use it as per your requirements.