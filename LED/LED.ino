int turn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (turn % 2) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  turn++;
  delay(500);
} 
