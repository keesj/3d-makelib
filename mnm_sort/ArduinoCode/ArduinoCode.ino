/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 70;    // variable to store the servo position 
 
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int red = 3; // Analog output pin that the LED is attached to
const int blue = 4; // Analog output pin that the LED is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
    pinMode(red, OUTPUT);     
    pinMode(blue,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

}

int moveto(int p){
  int dir = (p >= pos)?1:-1;
  while( p != pos){
    pos += 1 * dir;
    myservo.write(pos);
    delay(10);
  }
}
int servo_max = 140;

int g_center = 90;

int g_left_pick = 150;
int g_left_drop = 45;

int g_right_pick = 25;
int g_right_drop = 123;

int DELAY = 200;

int calibrate() {
  moveto(g_center);              // tell servo to go to position in variable 'pos' 
  delay(2000);
  moveto(g_right_pick);
  delay(2000);
  moveto(g_right_drop);
  delay(2000);
 
  moveto(g_left_pick);
  delay(2000);
  moveto(g_left_drop);
  delay(2000);
  
  moveto(g_center);
  delay(5000);
}

int shake(int amount){
  int c = 5,i;
  for (i = 0 ; i < amount ; i++){ 
    myservo.write(pos + amount);
    delay(100);
    myservo.write(pos );
    delay(100);

  }
  
}

void pick_right(){
  moveto(g_right_pick);
  shake(5);
  moveto(g_right_drop);
  shake(5);
}
void pick_left(){
  moveto(g_left_pick);
  shake(5);
  moveto(g_left_drop);
  shake(5);
}
void loop() {
  
  int base;
  int max;
  int bl,y;

 
  
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  
  delay(DELAY);
  base = analogRead(analogInPin);
  
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  delay(DELAY);
  max = analogRead(analogInPin);


  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  delay(DELAY);
  bl = analogRead(analogInPin);

 
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  delay(DELAY);
  y = analogRead(analogInPin);
 
  bl -= base;
  y -= base;
  max -= base;
  
  if(bl < 0 ){
    Serial.println("Blue < 0");
    return;
  }
  if(y < 0) {
    Serial.println("Red < 0");
    return;
  }
  
  if (bl < max / 2 || y < max /2 ){
    Serial.println("Nothing detected");
  } 
  
  //scale up to 10000
  
  float up = (float)1000 / max;
  bl *= up;
  y *= up;
  max *= up;
  
  float x = (float)bl/ y;
  
    Serial.print("base,blue,red,max,up,x = " );                       
  Serial.print(base);
  Serial.print("\t");
  Serial.print(bl);      
  Serial.print("\t,");     
  Serial.print(y);      
  Serial.print("\t,");     
  Serial.print(max);      
  Serial.print("\t,");     
  Serial.print(up);
  Serial.print("\t");
  Serial.print(x);  
  Serial.println();

  // print the results to the serial monitor:
  if (x > 0.85) {
    Serial.println("Blue");
  }

  if ( up  <= 2.2 ) {
    if (x > 0.85) {
      pick_left();
      
    } else {
      pick_right();
    }
    delay(300);
    moveto(g_center);
  }
    

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
