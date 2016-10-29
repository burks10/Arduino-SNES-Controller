#include <Joystick2.h>

/** Creator: Anthony Burkholder
 ** Date: Sept 24, 2016
 ** Project: USBSNES Controller
 ** Version: 0.0.1
 **/

/** PINS **/
int DATA_CLOCK    = 2;
int DATA_LATCH    = 4;
int DATA_SERIAL   = 6;

/** Data store for current state of buttons **/
int buttons[12];

void setup () {
  Joystick[0].begin();
  setupPins ();
}

void loop () {
  RXTXControllerData ();
}

void setupPins () {
  /** Set DATA_CLOCK normally HIGH **/
  pinMode (DATA_CLOCK, OUTPUT);
  digitalWrite (DATA_CLOCK, HIGH);
  
  /** Set DATA_LATCH normally LOW **/
  pinMode (DATA_LATCH, OUTPUT);
  digitalWrite (DATA_LATCH, LOW);

  /** Set DATA_SERIAL normally HIGH **/
  pinMode (DATA_SERIAL, OUTPUT);
  digitalWrite (DATA_SERIAL, HIGH);
  pinMode (DATA_SERIAL, INPUT);  
}

void RXTXControllerData () {
  /** Latch for 12us **/
  digitalWrite(DATA_LATCH, HIGH);
  delayMicroseconds(12);
  digitalWrite(DATA_LATCH, LOW);
  delayMicroseconds(6);

  /** Read data bit by bit from SR **/
  for (int i = 0; i < 16; i++) {
    digitalWrite (DATA_CLOCK, LOW);
    delayMicroseconds (6);
    if (i <= 11) {
      buttons[i] = digitalRead (DATA_SERIAL);
    }
    digitalWrite (DATA_CLOCK, HIGH);
    delayMicroseconds (6);
  }

  /** Set Joystick buttons based on SNES input **/
  for (int i = 0; i <= 11; i++) {
    Joystick[0].setButton(i, !buttons[i]);      // 1=XBOX(A)
  }
}

