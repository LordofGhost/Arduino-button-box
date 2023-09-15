
#include <Joystick.h>
#include <Keypad.h>

// Joystick pins
#define joyX A0
#define joyY A1
#define joyZ A2

// Button iniclisation
#define ENABLE_PULLUPS
#define NUMROWS 5
#define NUMCOLS 4

byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15},
  {16,17,18,19}
};

byte rowPins[NUMROWS] = {2,3,4,5,6}; 
byte colPins[NUMCOLS] = {7,8,9,10}; 

Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

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
  CheckAllButtons();

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

void CheckAllButtons(void) {
      if (buttbx.getKeys())
    {
       for (int i=0; i<LIST_MAX; i++)   
        {
           if ( buttbx.key[i].stateChanged )   
            {
            switch (buttbx.key[i].kstate) {  
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(buttbx.key[i].kchar, 1);
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(buttbx.key[i].kchar, 0);
                              break;
            }
           }   
         }
     }
}
