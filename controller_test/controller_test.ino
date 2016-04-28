int DATA_CLOCK    = 6;
int DATA_LATCH    = 7;
int DATA_SERIAL  = 12;

int buttons[12];

void setup(){
  Serial.begin(9600);
  setupPins();
}

void loop(){
  getControllerData();
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

void getControllerData(void){
    // Latch for 12us
    digitalWrite(DATA_LATCH, HIGH);
    delayMicroseconds(12);
    digitalWrite(DATA_LATCH, LOW);
    delayMicroseconds(6);
    
    // Retrieve button presses from shift register by pulling the clock high for 6us
    for(int i = 0; i < 16; i++){
        digitalWrite(DATA_CLOCK, LOW);
        delayMicroseconds(6);
        if(i < 11){
            buttons[i] = digitalRead(DATA_SERIAL);
        }
        digitalWrite(DATA_CLOCK, HIGH);
    }
  printButtons();  
}

// Prints which buttons are pressed
void printButtons(void){
    if(buttons[0] == 0){
        Serial.println("B");
    }
    if(buttons[1] == 0){
        Serial.println("Y");
    }
    if(buttons[2] == 0){
        Serial.println("SELECT");
    }
    if(buttons[3] == 0){
        Serial.println("START");
    }
    if(buttons[4] == 0){
        Serial.println("UP");
    }
    if(buttons[5] == 0){
        Serial.println("DOWN");
    }
    if(buttons[6] == 0){
        Serial.println("LEFT");
    }
    if(buttons[7] == 0){
        Serial.println("RIGHT");
    }
    if(buttons[8] == 0){
        Serial.println("A");
    }
    if(buttons[9] == 0){
        Serial.println("X");
    }
    if(buttons[10] == 0){
        Serial.println("LB");
    }
    if(buttons[11] == 0){
        Serial.println("RB");
    }
}
