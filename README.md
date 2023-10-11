# ayab-gtest

## Overview

Blinker example illustrating usage of gtest with no/minimal operational code impact that could be applied to ayab-firmware project
- Based on dependency injection using interfaces
- Applied to all objects requiring unit tests (Led and Blinker here) and the hardware abstraction layer (HAL)
   - All (arduino) platform calls are made thru HAL that is replaced by a mocked implementation during tests
- No dependencies to 3rd party libraries (gtest installed thru platformio, own arduino mock, ...)
- Cooperative scheduling architecture including an "async" Led implementation 

## Setup
Install platformio on your machine and update platformio.ini to match your hardware

Build application:
```sh
$ pio run
```
or (build and upload):
```sh
$ pio run /upload
```
Run gtest:
```
$ pio test -e native
```
