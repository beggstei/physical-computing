void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
  int interval = analogRead(A0)/5;

  digitalWrite(2, HIGH);
  delay(interval);
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);
  delay(interval);
  digitalWrite(3, LOW);

  digitalWrite(4, HIGH);
  delay(interval);
  digitalWrite(4, LOW);

  digitalWrite(5, HIGH);
  delay(interval);
  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);
  delay(interval);
  digitalWrite(6, LOW);
}
