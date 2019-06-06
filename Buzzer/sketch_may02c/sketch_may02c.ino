void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(Serial.read()) {
    case 'a':
       tone(8, 440, 2000);
       break;
    case 's':
       tone(8, 493.88, 2000);
       break;
    case 'd':
       tone(8, 523.25, 2000);
       break;
    case 'f':
       tone(8, 587.33, 2000);
       break;
    case 'g':
       tone(8, 659.25, 2000);
       break;
    case 'h':
       tone(8, 698.46, 2000);
       break;
    case 'j':
       tone(8, 783.99, 2000);
       break;
    case 'k':
       tone(8, 880, 2000);
       break;
    case 'l':
       tone(8, 987.77, 2000);
       break;
  }
}
