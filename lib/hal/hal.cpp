#include "Arduino.h"
#include "hal.h"

namespace hardwareAbstraction{

void Hal::pinMode(uint8_t pin, uint8_t mode) {
    ::pinMode(pin, mode);
}

void Hal::digitalWrite(uint8_t pin, uint8_t state) {
    ::digitalWrite(pin, state);
}

unsigned long Hal::millis() {
    return ::millis();
}

} // hardwareAbstraction
