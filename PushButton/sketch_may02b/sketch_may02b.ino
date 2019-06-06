boolean state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == HIGH) {
    state = !state;
    if (state) {
       digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
    delay(5);
  }
}
