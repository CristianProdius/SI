#include <stdio.h>
#include <string.h>
#include "SerialInput.h"
#include "ButtonLED.h"
#include "StateVariable.h"

void handleSerialInput() {
    char command[10];

    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "toggle") == 0) {
        simulateButtonPress();
        printf("Toggled LED.\n");
    } else if (strcmp(command, "inc") == 0) {
        increaseVariable();
        printf("Incremented state variable.\n");
    } else if (strcmp(command, "dec") == 0) {
        decreaseVariable();
        printf("Decremented state variable.\n");
    } else {
        printf("Unknown command. Use 'toggle', 'inc', or 'dec'.\n");
    }
}
