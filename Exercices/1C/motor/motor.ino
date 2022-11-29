void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(1000);
  */

  /*
  for(int i = 0; i < 255; i++){
    analogWrite(9, i);
    delay(100);
  }
  delay(1000);
  
  for(int i = 255; i > 0; i--){
    analogWrite(9, i);
    delay(100);
  }

  delay(1000);

  */

  int speed1 = analogRead(A0);
  int speed2 = map(speed1, 0, 1023, 0, 255);
  analogWrite(9, speed2);
  Serial.println(speed2);
}
