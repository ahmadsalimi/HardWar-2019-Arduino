#include <math.h>

#define ROW_0 2
#define ROW_1 3
#define ROW_2 4
#define ROW_3 5
#define ROW_4 6
#define ROW_5 7
#define ROW_6 8
#define ROW_7 9
#define RED_COL 11
#define GREEN_COL 10
#define GREEN_CLOCK 13
#define RED_CLOCK 12
#define JOY_X A0
#define JOY_Y A2
#define BUTTON A4

int redMatrix[8][8] = {0};
int greenMatrix[8][8] = {0};


int rowToNumber(int row[]) {
  int number = 0;
  int power = 1;
  for (int i = 0; i < 8; i++) {
    number += row[i] * power;
    power *= 2;
  }
  return number;
}


void byteToBit(byte Byte) {
  for(int i=0 ; i<4; i++){
    int Bit = Byte%4;
    
  }
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ROW_0,OUTPUT); // row
  pinMode(ROW_1,OUTPUT); // row
  pinMode(ROW_2,OUTPUT); // row
  pinMode(ROW_3,OUTPUT); // row
  pinMode(ROW_4,OUTPUT); // row
  pinMode(ROW_5,OUTPUT); // row
  pinMode(ROW_6,OUTPUT); // row
  pinMode(ROW_7,OUTPUT); // row
  pinMode(RED_COL,OUTPUT); // red column
  pinMode(GREEN_COL,OUTPUT); // green column
  pinMode(RED_CLOCK,OUTPUT); // red clock
  pinMode(GREEN_CLOCK,OUTPUT); // green clock
  pinMode(JOY_X,INPUT);
  pinMode(JOY_Y,INPUT);
  pinMode(BUTTON,INPUT);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2) {
        greenMatrix[i][j] = 1;
      } else {
        redMatrix[i][j] = 1;
      }
    }
  }
  draw();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    byte info[16];
  Serial.readBytes(info, 16);

  for (int i = 0; i < 8; i++) {
    byte one = info[i * 2];
    byte two = info[i * 2 + 1];
    for (int j=0; j < 4; j++) {
      int bits = one % 4;
      switch (bits) {
        case 0:
          greenMatrix[i][3 - j] = 1;
          redMatrix[i][3 - j] = 1;
          break;
         case 1:
          greenMatrix[i][3 - j] = 1;
          redMatrix[i][3 - j] = 0;
          break;
        case 2:
          greenMatrix[i][3 - j] = 0;
          redMatrix[i][3 - j] = 1;
          break;
        case 3:
          greenMatrix[i][3 - j] = 0;
          redMatrix[i][3 - j] = 0;
          break;
      }
      one /= 4;
    }
    for (int j=0; j < 4; j++) {
      int bits = two % 4;
      switch (bits) {
        case 0:
          greenMatrix[i][7 - j] = 1;
          redMatrix[i][7 - j] = 1;
          break;
         case 1:
          greenMatrix[i][7 - j] = 1;
          redMatrix[i][7 - j] = 0;
          break;
        case 2:
          greenMatrix[i][7 - j] = 0;
          redMatrix[i][7 - j] = 1;
          break;
        case 3:
          greenMatrix[i][7 - j] = 0;
          redMatrix[i][7 - j] = 0;
          break;
      }
      two /= 4;
    }
  }

  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);
  int button = digitalRead(BUTTON);
  byte bytes[5] = {0x55, x * 1024 / 800, (800 - y) * 1024 / 800, button * (0xFF), 0xAA};
  for (int i = 0; i < 5; i++) {
      Serial.write(bytes[i]);
  }
  }

void draw() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
    shiftOut(GREEN_COL, GREEN_CLOCK  ,MSBFIRST , rowToNumber(greenMatrix[i - 2]));
    shiftOut(RED_COL, RED_CLOCK  ,MSBFIRST , rowToNumber(redMatrix[i - 2]));
    delayMicroseconds(200000);
    digitalWrite(i, LOW);
  }
}
