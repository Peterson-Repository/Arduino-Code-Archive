//Author: Marco Peterson
//Class: Digital Image Prossecing
//Date: 2-9-2015

//Homework 4

//Use the Rotary Potentiometer to increase and decrease the amount of voltage inputed into a LED Light

#include <Servo.h>
 #define O0 11
 #define I0 A0
 
  Servo esc;
  const int throttlePin = I0;
  const uint8_t analogOutPin1= 11; // Analog output pin that the LED is attached to
  
   int sensorValue1 = 0; // value read from the Potentiometer's first pin
   int outputValue1 = 0; // value output to the PWM (analog out)
   int throttle;

void setup()
{
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(throttlePin , INPUT); 

  pinMode(analogOutPin1 , OUTPUT); 
  esc.attach(9);
}
 
void loop()
{ 
  throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 255);
  Serial.print(throttle);
  Serial.print("\n");
  analogWrite(analogOutPin1, throttle);
}

