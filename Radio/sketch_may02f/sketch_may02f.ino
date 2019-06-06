#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);
const byte address[6] = "12345";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(20);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  char text[100];
  Serial.readBytes(text, sizeof(text));
  radio.write(&text, sizeof(text));
}
