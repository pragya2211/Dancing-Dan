#include <SoftwareSerial.h>

int sensoroutput = A3; // the analog pin connected to the sensor
int ledPin = 12; // pin connected to LED
int THRESHOLD = 1;
void setup()
{
//pinMode(ledPin, OUTPUT);   // this function is used to declare led connected pin as output
Serial.begin(9600);
//Serial.println(1);
}
void loop()
{
  //Serial.begin(100);
 //Serial.println(THRESHOLD);
  //Serial.println("2");
int value = analogRead(sensoroutput);  // function to read analog voltage from sensor
if (value > THRESHOLD)                    // function to check voltage level from sensor
{
  Serial.println(value);
digitalWrite(ledPin, HIGH);
delay(100); // to make the LED visible
}
else
{
  //Serial.println(value);
digitalWrite(ledPin, LOW);
}
} 
