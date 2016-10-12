import processing.serial.*;

Serial serial;  
int sensorValue;
PImage cat;
PImage mouse;

void setup() {
  size(480, 300);
  serial = new Serial(this, Serial.list()[1], 9600);
  cat = loadImage("cat.png");
  mouse = loadImage("mouse.png");
}

void draw() {
  if ( serial.available() > 0) {
    sensorValue = serial.read();
    println(sensorValue);
    
    background(255);  
    image(cat, sensorValue+50, 210);
    image(mouse, sensorValue+20, 165);
  }   
}