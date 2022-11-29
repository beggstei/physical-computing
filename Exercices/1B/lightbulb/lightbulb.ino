void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);
  */
  for(int i = 0; i < 255; i++){
    analogWrite(9, i);
    delay(2);
  }
  delay(200);
  for(int i = 255; i > 0; i--){
    analogWrite(9, i);
    delay(5);
  }
  
}
