#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int state = 0;
const int ledPin = 8;  //the pin your led is connected to
const int buttonPin = 2;  //the pin your button is connected to

int buttonState = 0;

void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);

  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {

  buttonState = digitalRead(2);
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    //delay(20);
    BTserial.write('1');  //sends a 1 through the bluetooth serial link
    delay (20);
    digitalWrite(ledPin, LOW);
  }

  else {
    BTserial.write('0');
    digitalWrite(ledPin, LOW);
    delay(20);
  }
}
