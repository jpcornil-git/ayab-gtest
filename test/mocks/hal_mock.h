#ifndef HAL_MOCK_H
#define HAL_MOCK_H

#include "gmock/gmock.h"

#include "hal.h"

class Hal_mock : public hardwareAbstraction::HalInterface {
public:
    MOCK_METHOD(void, pinMode, (uint8_t pin, uint8_t mode), (override));
    MOCK_METHOD(void, digitalWrite, (uint8_t pin, uint8_t state), (override));
    MOCK_METHOD(unsigned long, millis, (), (override));
};

#endif // HAL_MOCK_H
