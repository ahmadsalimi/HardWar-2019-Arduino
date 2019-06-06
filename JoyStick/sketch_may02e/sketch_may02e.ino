void setup() {
  // put your setup code here, to run once:
  pinMode(A0 , INPUT);
  pinMode(A2 , INPUT);
  pinMode(A4 , INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("x: ");
  Serial.println(analogRead(A0));
  Serial.print("y: ");
  Serial.println(analogRead(A2));
  Serial.print("pressed: ");
  Serial.println(digitalRead(A4));
  Serial.println("-----------------");
  delay(100);
}
