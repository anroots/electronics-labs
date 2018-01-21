
void setup() {
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, INPUT);
}


bool doorIsOpen(){
  return digitalRead(A1) == LOW;
}

bool makeSomeNoise() {
  digitalWrite(A3, HIGH);
  delay(1000);
  digitalWrite(A3, LOW);
}

bool turnLEDOn() {
  digitalWrite(A2, HIGH);
}

bool turnLEDOff() {
  digitalWrite(A2, LOW);
}

// the loop function runs over and over again forever
void loop() {
  
  turnLEDOff();
  
  if (doorIsOpen()) {
    turnLEDOn();
    delay(4000);
    
    while (doorIsOpen()) {  
      makeSomeNoise();  
      delay(3000);
    }
  }
}
