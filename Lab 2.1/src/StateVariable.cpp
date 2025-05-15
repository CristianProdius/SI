#include "StateVariable.h"

int stateVariable = 1;

void setupStateVariable() {
    // No physical pins required
}

void handleStateVariable() {
    // No logic here since it’s controlled via Serial
}

void increaseVariable() {
    stateVariable++;
}

void decreaseVariable() {
    if (stateVariable > 1) {
        stateVariable--;
    }
}
