
#include <Joystick.h>
#include <Keypad.h>

// define Input Pins
#define joyX A0
#define joyY A1
#define joyZ A2

#define row1 D2
#define row2 D3
#define row3 D4
#define row4 D5
#define row5 D6
#define col1 D7
#define col2 D8
#define col3 D9
#define col4 D10

// configuration
Joystick_ Joystick(0x1, JOYSTICK_TYPE_JOYSTICK, 20, 0, true, true, true, false, false, false, false, false, false, false, false);

// always send data
const bool initAutoSendState = true;

// setup joystick axis
int xAxis_ = 0;
int yAxis_ = 0;
int zAxis_ = 0;

void setup() {
  Joystick.begin();
}

   
void loop() {
  CheckButtons();

  CheckJoystick();
}

void CheckJoystick(void) {
  xAxis_ = analogRead(joyX);
  xAxis_ = map(xAxis_, 0, 1023, 0, 1023);
  Joystick.setXAxis(xAxis_);

  yAxis_ = analogRead(joyY);
  yAxis_ = map(yAxis_, 0, 1023, 0, 1023);
  Joystick.setYAxis(yAxis_);

  zAxis_ = analogRead(joyZ);
  zAxis_ = map(zAxis_, 0, 1023, 0, 1023);
  Joystick.setZAxis(zAxis_);
}

void CheckButtons(void) {

  Joystick.setButton(0, 1);
}
