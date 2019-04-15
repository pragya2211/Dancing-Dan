#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int state = 0;

void setup() {
  // initialize digital pin 8 as an output.

  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(8, OUTPUT);

}

void loop() {
  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read();
    Serial.write("aabb");
    //ata from the serial port
    //Serial.write(state);
  }
  // Controlling the LED
  if (state == 120) {
    
    digitalWrite(8, HIGH); // LED ON
    delay (20);
    state = 0;
    digitalWrite(8, LOW);
  }
  else if (state == '0') {
    digitalWrite(8, LOW); // LED ON
    state = 0;
  }
}
