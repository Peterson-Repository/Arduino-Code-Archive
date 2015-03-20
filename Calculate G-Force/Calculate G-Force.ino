/*
Double Analog input, Double analog output, serial output
Reads from two analog input pins, a T000020 Accelerometer Module connected
to I0 and I1, maps the result to a range from 0 to 255
and uses the result to set the pulsewidth modulation (PWM) on two T010111
LED Modules connected on O0 and O1.
Also prints the results to the serial monitor.
created 29 Dec. 2008
Modified 4 Sep 2010
by Tom Igoe
modified 7 dec 2010
by Davide Gomba
This example code is in the public domain.
*/

#define O0 11
#define O1 10
#define O2 9
#define O3 6
#define O4 5
#define O5 3
#define I0 A0
#define I1 A1
#define I2 A2
#define I3 A3
#define I4 A4
#define I5 A5

// These constants won't change. They're used to give names

// to the pins used:
const int analogInPin1 = I0; // Analog input pin that the Accelerometer's first pin is attached to
const int analogInPin2 = I1; // Analog input pin that the Accelerometer's second pin is attached to
const int analogOutPin1= O0; // Analog output pin that the LED is attached to
const int analogOutPin2= O1; // Analog output pin that the LED is attached to

int sensorValue1 = 0; // value read from the Accelerometer's first pin
int sensorValue2 = 0; // value read from the Accelerometer's second pin

float volt1 = 0;
float volt2 = 0;

float gforce1 = 0;
float gforce2 = 0;

int outputValue1 = 0; // value output to the PWM (analog out)
int outputValue2 = 0; // value output to the PWM (analog out)


void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
}


void loop() {
  
// read the both analog in values:
sensorValue1 = analogRead(analogInPin1);
sensorValue2 = analogRead(analogInPin2);

// map it to the range of the analog out:
outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
outputValue2 = map(sensorValue2, 0, 1023, 0, 255);

// change the analog out value:
//analogWrite(analogOutPin1, outputValue1);
//analogWrite(analogOutPin2, outputValue2);

//calculate volts
volt1 = (sensorValue1*5)/1023;
volt2 = (sensorValue2*5)/1023;

//calculate gforce
//gforce1 = ((volt1)/9.8)/1024.0;
//gforce2 = ((volt2)/9.8)/1024.0;

gforce1 = ((volt1-2.5)/2.5)*3.5;
gforce2 = ((volt2-2.5)/2.5)*3.5;

// print the results to the serial monitor:

//Raw Reading
//Serial.print("accelerometer X = " );

Serial.print(sensorValue1);

//Serial.print("\t accelerometer Y = " );
Serial.print("\t");
Serial.print(sensorValue2);

//Voltage
//Serial.print("\t voltage X = " );
Serial.print("\t");
Serial.print(volt1);

//Serial.print("\t voltage Y = " );
Serial.print("\t");
Serial.print(volt2);

//G-Force
//Serial.print("\t G - X = " );
Serial.print("\t");
Serial.print(gforce1);

//Serial.print("\t G - Y = " );
Serial.print("\t");
Serial.println(gforce2);

/*Serial.print("\t output 1 = ");
Serial.print(outputValue1);

Serial.print("\t output 2 = ");
Serial.println(outputValue2);*/


// wait 10 milliseconds before the next loop
// for the analog-to-digital converter to settle
// after the last reading:
delay(200);
}
