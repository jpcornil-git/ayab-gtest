#ifndef BLINKER_H
#define BLINKER_H

#include "hal.h"
#include "led.h"

class Blinker {
  public:
    Blinker(
      hardwareAbstraction::HalInterface* hal,
      LedInterface* led_a);
    ~Blinker() = default;
    void update();

  private:
    LedInterface* led_a;
};

#endif // BLINKER_H
