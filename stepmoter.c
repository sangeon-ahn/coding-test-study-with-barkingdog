#include <stdio.h>
#include <Arduino.h>
#include <stdlib.h>
#define ENABLE 8
#define X_STEP 2
#define Y_STEP 3
#define Z_STEP 4
#define X_DIR  5
#define Y_DIR  6
#define Z_DIR  7
int a; //변수 설정
void setup() {
  // 디스플레이 핀 번호 설정
  pinMode(X_STEP, OUTPUT);
  pinMode(Y_STEP, OUTPUT);
  pinMode(Z_STEP, OUTPUT);
  pinMode(X_DIR,  OUTPUT);
  pinMode(Y_DIR,  OUTPUT);
  pinMode(Z_DIR,  OUTPUT);
  pinMode(ENABLE, OUTPUT);
  // 모든 드라이버에 대한 제어 활성
  digitalWrite(ENABLE, LOW);
  Serial.begin(9600);
}

// void loop() {
//   if(Serial.available()){
//     a=Serial.parseInt();

//     switch(a){
//       case 0://오전 7시부터 11시59분까지 약시간일때 시리얼통신으로 0을 받아온다. 0일때 x모터가 시계방향으로 1/8바퀴 회전한다.
//       movementAxis(false, X_DIR, X_STEP, 256);
//       delay(1000);
//       break;
//       case 1://12시부터 5시59분까지 약시간일때 시리얼통신으로 1을 받아온다. 1일때 y모터가 시계방향으로 1/8바퀴 회전한다.
//       movementAxis(false, Y_DIR, Y_STEP, 256);
//       delay(1000);
//       break;
//       case 2://6시부터 11시59분까지 약시간일 때 시리얼통신으로 2를 받아온다. 2일때 z모터가 시계방향으로 1/8만큼 회전한다.
//       movementAxis(false, Z_DIR, Z_STEP, 256);
//       delay(1000);
//       break;
//     }
//   }

void loop() {
  while (1) {
    movementAxis(false, X_DIR, X_STEP, 256);
    delay(1000);
    movementAxis(true, X_DIR, X_STEP, 256);
    delay(1000);

    movementAxis(false, Y_DIR, Y_STEP, 256);
    delay(1000);
    movementAxis(true, Y_DIR, Y_STEP, 256);
    delay(1000);

    movementAxis(false, Z_DIR, Z_STEP, 256);
    delay(1000);
    movementAxis(true, Z_DIR, Z_STEP, 256);
    delay(1000);
  }
}
  // X축을 시계방향으로 1/8바퀴 회전
  //movementAxis(false, X_DIR, X_STEP, 256);
  //delay(1000);
  //movementAxis(true, X_DIR, X_STEP, 256);
  //delay(1000);
  // Y축을 시계방향으로 1/8바퀴 회전
 // movementAxis(false, Y_DIR, Y_STEP, 256);
  //delay(1000);
  //movementAxis(true, Y_DIR, Y_STEP, 256);
  //delay(1000);
  // Z축을 시계방향으로 1/8바퀴 회전
  //movementAxis(false, Z_DIR, Z_STEP, 256);
 // delay(1000);
 // movementAxis(true, Z_DIR, Z_STEP, 256);
  //delay(1000);
}

void movementAxis(boolean direction, byte dirPin, byte stepPin, int steps) {
  // 적절한 핀에 방향 쓰기 DIR
  digitalWrite (dirPin, direction);
  delay(50);
  // 통과된 단계 수를 수행하는 루프
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds (800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds (800);
  }
}