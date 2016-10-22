#include <Wire.h>
#include <Adafruit_NeoPixel.h>


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);


/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup(){  
  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  for (int i=0; i<3; i++){ 
    //this sequence flashes the first pixel three times as a countdown to the color reading.
    strip.setPixelColor (0, strip.Color(100, 100, 100)); //white, but dimmer-- 255 for all three values makes it blinding!
    strip.show();
    delay(1000);
    strip.setPixelColor (0, strip.Color(0, 0, 0));
    strip.show();
    delay(500);
  }

  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  if (red < blue && red < green && red < 20) {  
   Serial.println(" - (Red Color)");  
   colorWipe(strip.Color(255, 0, 0), 0);// Turn RED LED ON 
  }  

  else if (blue < red && blue < green) {  
   Serial.println(" - (Blue Color)");  
   colorWipe(strip.Color(0, 0, 255), 0);// Turn RED LED ON  // Turn BLUE LED ON  
  }  

  else if (green < red && green < blue) {  
   Serial.println(" - (Green Color)");  
   colorWipe(strip.Color(0, 255, 0), 0);// Turn RED LED ON  // Turn GREEN LED ON 
    
  }  
  else{
  Serial.println();  
  }
  delay(300);   
  strip.setPixelColor (0, strip.Color(0, 0, 0));
  
  
  
}  

    
void loop() {  
  
 }  
    
void color() {    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
