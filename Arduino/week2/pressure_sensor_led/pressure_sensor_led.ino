int ledg = 3;
int ledr = 4;



void setup() {
  Serial.begin(9600);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
}

void loop() {

  int pressureValue = analogRead(A0);
  Serial.println(pressureValue);
  
  if ( pressureValue > 0 && pressureValue < 500) {
    digitalWrite(ledg, HIGH);
    digitalWrite(ledr, LOW);
  }
  else if (pressureValue >= 500) {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, HIGH);
  } 
  else {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, LOW);
  }
}


