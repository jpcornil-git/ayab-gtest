#include "Arduino.h"

#include "board.h"
#include "hal.h"
#include "led.h"
#include "blinker.h"

hardwareAbstraction::Hal* hal = nullptr;

Led *led_a = nullptr;
Blinker *blinker = nullptr;

/*
 * Setup - do once before going to the main loop.
 */
void setup() {
  hal = new hardwareAbstraction::Hal();

  led_a = new Led(hal, LED_A_PIN);
  blinker = new Blinker(hal, led_a);
}

/*
 * Main Loop - repeat forever.
 */
void loop() {
  blinker->update();
}

