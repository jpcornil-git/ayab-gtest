#ifndef HAL_H
#define HAL_H

#include "arduino_types.h"

namespace hardwareAbstraction {

class HalInterface {
public:
    virtual ~HalInterface() = default;

    virtual void pinMode(uint8_t pin, uint8_t mode) = 0;
    virtual void digitalWrite(uint8_t pin, uint8_t state) = 0;
    virtual unsigned long millis() = 0;
};

class Hal : public HalInterface {
public:
    Hal() = default;
    ~Hal() = default;

    void pinMode(uint8_t pin, uint8_t mode) override;
    void digitalWrite(uint8_t pin, uint8_t state) override;
    unsigned long millis() override;
};

} // hardwareAbstraction

#endif // HAL_H
