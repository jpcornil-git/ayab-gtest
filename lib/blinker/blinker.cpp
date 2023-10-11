
#include "blinker.h"

Blinker::Blinker(
  hardwareAbstraction::HalInterface* hal,
  LedInterface* led_a) : led_a(led_a) {
  led_a->blink(900,100);
}

void Blinker::update() {
  led_a->update();
}
