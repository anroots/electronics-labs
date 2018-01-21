
void setup() {
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, INPUT);
}


bool doorIsOpen(){
  return digitalRead(A3) == LOW;
}

bool makeSomeNoise() {
  digitalWrite(A4, HIGH);
  delay(1000);
  digitalWrite(A4, LOW);
}

bool turnLEDOn() {
  digitalWrite(A5, HIGH);
}

bool turnLEDOff() {
  digitalWrite(A5, LOW);
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
