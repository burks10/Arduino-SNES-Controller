#include "UnoJoy.h"

//NOTE: Pins 0, 1 and 13 are used by UnoJoy for Serial Comm.
int DATA_CLOCK    = 6;
int DATA_LATCH    = 7;
int DATA_SERIAL  = 12;

int buttons[12];

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set DATA_CLOCK normally HIGH
  pinMode(DATA_CLOCK, OUTPUT);
  digitalWrite(DATA_CLOCK, HIGH);
  
  // Set DATA_LATCH normally LOW
  pinMode(DATA_LATCH, OUTPUT);
  digitalWrite(DATA_LATCH, LOW);

  // Set DATA_SERIAL normally HIGH
  pinMode(DATA_SERIAL, OUTPUT);
  digitalWrite(DATA_SERIAL, HIGH);
  pinMode(DATA_SERIAL, INPUT);  
}

dataForController_t getControllerData(void){
    // Latch for 12us
    digitalWrite(DATA_LATCH, HIGH);
    delayMicroseconds(12);
    digitalWrite(DATA_LATCH, LOW);
    delayMicroseconds(6);
    
    for(int i = 0; i < 16; i++){
        digitalWrite(DATA_CLOCK, LOW);
        delayMicroseconds(6);
        if(i <= 11){
            buttons[i] = digitalRead(DATA_SERIAL);
        }
        digitalWrite(DATA_CLOCK, HIGH);
        delayMicroseconds(6);
    }
    
    
    dataForController_t controllerData = getBlankDataForController();
    if(buttons[0] == 0){
       controllerData.crossOn = 1;
    }
    
    if(buttons[1] == 0){
      controllerData.squareOn = 1;
    }
    
    if(buttons[2] == 0){
        controllerData.selectOn = 1;
    }
    
    if(buttons[3] == 0){
      controllerData.startOn = 1;
    }
    
    if(buttons[4] == 0){
      controllerData.dpadUpOn = 1;
    }
    
    if(buttons[5] == 0){
      controllerData.dpadDownOn = 1;
    }
    
    if(buttons[6] == 0){
      controllerData.dpadLeftOn = 1;
    }
    
    if(buttons[7] == 0){
      controllerData.dpadRightOn = 1;
    }
    
    if(buttons[8] == 0){
      controllerData.circleOn = 1;
    }
    
    if(buttons[9] == 0){
      controllerData.triangleOn = 1;
    }
    
    if(buttons[10] == 0){
      controllerData.l1On = 1;
    }

    if(buttons[11] == 0){
      controllerData.r1On = 1;
    }

  return controllerData;
    
}

