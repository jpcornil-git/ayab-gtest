#ifndef LED_MOCK_H
#define LED_MOCK_H

#include "gmock/gmock.h"

#include "led.h"

class Led_mock  : public LedInterface {
public:
    Led_mock(hardwareAbstraction::HalInterface* hal, uint8_t pin) {};
    Led_mock(hardwareAbstraction::HalInterface* hal, uint8_t pin, uint8_t low, uint8_t high) {};

    MOCK_METHOD(void, on, (), (override));
    MOCK_METHOD(void, off, (), (override));
    MOCK_METHOD(void, toggle, (), (override));
    MOCK_METHOD(void, blink, (unsigned long timeOff, unsigned long timeOn), (override));
    MOCK_METHOD(void, flash, (unsigned long timeOn), (override));
    MOCK_METHOD(void, update, (), (override));
};

#endif // LED_MOCK_H
