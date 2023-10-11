#ifndef LED_H
#define LED_H

#include "hal.h"

class LedInterface {
  public:
    virtual ~LedInterface() = default;

    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;
    virtual void blink(unsigned long timeOff, unsigned long timeOn) = 0;
    virtual void flash(unsigned long timeOn) = 0;
    virtual void update() = 0;
};

class Led : public LedInterface {
  public:
    Led(hardwareAbstraction::HalInterface* hal, uint8_t pin);
    Led(hardwareAbstraction::HalInterface* hal, uint8_t pin, uint8_t low, uint8_t high);
    ~Led() = default;

    void on() override;
    void off() override;
    void toggle() override;
    void blink(unsigned long timeOff, unsigned long timeOn) override;
    void flash(unsigned long timeOn) override;
    void update() override;
    // reset, blink with duration, flash with count

  private:
    enum class State {Off, On};
    enum class Mode {Solid, Blink, Flash};

    hardwareAbstraction::HalInterface *_hal;
    uint8_t        _pin;
    State          _state;
    Mode           _mode;
    uint8_t        _low, _high;

    unsigned long _timeOff, _timeOn;
    unsigned long _lasttime;

    void _write();
};

#endif

