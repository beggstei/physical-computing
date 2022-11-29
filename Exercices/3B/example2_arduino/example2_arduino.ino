#include <Servo.h>
#define OUTPUT_PIN 11

const int DELAY_MS = 200;
int inputVal; 

Servo myservo;  // create servo object 
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  // Check to see if there is any incoming serial data
  if (Serial.available() > 0) {
    // read string until the endo of the line
    String rcvdSerialData = Serial.readStringUntil('\n');
    analogWrite(OUTPUT_PIN, rcvdSerialData.toInt());
    delay(DELAY_MS);
    pos = map(rcvdSerialData.toInt(), 0, 255, 0, 180);
    myservo.write(pos);

    /*
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      
      delay(4);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(String rcvdSerialData = Serial.readStringUntil('\n'););              // tell servo to go to position in variable 'pos'
      String rcvdSerialData = Serial.readStringUntil('\n');
      delay(rcvdSerialData.toInt()/5);                       // waits 15ms for the servo to reach the position
    }*/
  }
}
