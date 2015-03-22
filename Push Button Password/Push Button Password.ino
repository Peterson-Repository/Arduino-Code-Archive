#include <TinkerKit.h>


// The following enumeration is used to represent the possible
// states that the security device can be in.
enum SecurityState {INIT , ONE_CORRECT , TWO_CORRECT , THREE_CORRECT ,
ONE_WRONG , TWO_WRONG , THREE_WRONG};

// The following variable represents the current state of the
// security device.
SecurityState state;

// Inputs
TKButton button1(I0);
TKButton button2(I1);
TKTouchSensor button3(I2);

// Outputs
TKLed red(O0);
TKLed green(O1);

//Count attempts
int attemps = 0;

void button1Clicked() {
  if (state == INIT) {
    state = ONE_CORRECT;
  }
  else if (state == ONE_CORRECT) {
    state = TWO_WRONG;
  }
  else if (state == TWO_CORRECT) {
    state = THREE_WRONG;
  }
  else if (state == THREE_CORRECT) {
    // Nothing to do
  }
  else if (state == ONE_WRONG) {
    state = TWO_WRONG;
  }
  else if (state == TWO_WRONG) {
    state = THREE_WRONG;
    red.on(); // Turn on the red led
  }
  else if (state == THREE_WRONG) {
    // Blink both LEDs three times and reset
  }
}
void button2Clicked() {
  if (state == INIT) {
    state = ONE_WRONG;
  }
  else if (state == ONE_CORRECT) {
    state = TWO_CORRECT;
  }
  else if (state == TWO_CORRECT) {
    state = THREE_WRONG;
  }
  else if (state == THREE_CORRECT) {
    // Nothing to do
  }
  else if (state == ONE_WRONG) {
    state = TWO_WRONG;
  }
  else if (state == TWO_WRONG) {
    state = THREE_WRONG;
    red.on(); // Turn on the red led
  }
  else if (state == THREE_WRONG) {
    // Nothing to do
  }
}
void button3Clicked() {
  if (state == INIT) {
    state = ONE_WRONG;
  }
  else if (state == ONE_CORRECT) {
    state = TWO_WRONG;
  }
  else if (state == TWO_CORRECT) {
    state = THREE_CORRECT;
    green.on(); // Turn on the green LED
  }
  else if (state == THREE_CORRECT) {
    // Nothing to do
  }
  else if (state == ONE_WRONG) {
    state = TWO_WRONG;
  }
  else if (state == TWO_WRONG) {
    state = THREE_WRONG;
    red.on(); // Turn on the red led
  }
  else if (state == THREE_WRONG) {
    // Blink both LEDs three times and reset
  }
}

void setup() {
  // put your setup code here, to run once:
  state = INIT; // Start the security device in the initial state.
}

void loop() {
  // put your main code here, to run repeatedly:
  if (button1.pressed()) {
    button1Clicked();
  }
  else if (button2.pressed()) {
    button2Clicked();
  }
  else if (button3.pressed()) {
    button3Clicked();
  }
  button1.released();
  button2.released();
  button3.released();
}
