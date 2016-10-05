int buzzerPin = 12;
int pressurePin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  int notes[10]={261, 294, 330, 349, 392, 440, 493, 523};
  //            mid C  D    E    F    G    A

  for(int i = 0; i < 10; i++){
    tone(12, notes[i]); 
    delay(1000);
  }

 noTone(12);

}
