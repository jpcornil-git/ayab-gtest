#include <gtest/gtest.h>

#include "board.h"
#include "blinker.h"
#include "mocks/hal_mock.h"
#include "mocks/led_mock.h"

using ::testing::NiceMock;
using ::testing::_;

class blinkerTest : public ::testing::Test {
protected:
    Blinker* _blinker{nullptr};
    NiceMock<Hal_mock>* _hal_mock{nullptr};
    NiceMock<Led_mock>* _led_mock{nullptr};

    virtual void SetUp() {
      //_hal_mock = new NiceMock<Hal_mock>(); 
      _led_mock = new NiceMock<Led_mock>(_hal_mock, LED_A_PIN);

      // Check Constructor
      EXPECT_CALL(*_led_mock, blink(_,_)).Times(1);
      _blinker = new Blinker(_hal_mock, _led_mock);
    }

    virtual void TearDown() {
      delete _blinker;
      delete _led_mock;
      //delete _hal_mock;
    }
};

TEST_F(blinkerTest, update) {
    EXPECT_CALL(*_led_mock, update()).Times(1);
    _blinker->update();
}

