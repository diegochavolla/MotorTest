#include <Arduino.h>

// put function declarations here:

int chooseMode(enum motion);

int in1_1 = 4;
int in1_2 = 5;
int in2_1 = 6;
int in2_2 = 7;
motion checkMotion;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1_1, OUTPUT);
  pinMode(in1_2, OUTPUT);
  pinMode(in2_1, OUTPUT);
  pinMode(in2_2, OUTPUT);
  enum motion {FORWARD, BACK, LEFT, RIGHT};
}

void loop() {
  motion = FORWARD;
  delay(2000);
  motion = BACK;
  delay(2000);
  motion = LEFT;
  delay(2000);
  motion = RIGHT;
  delay(2000);
}

int chooseMode(enum motion) {
  switch (motion) {
    case FORWARD:
    //left motors
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, LOW);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    //right motors
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, LOW);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    break;
    case BACK:
    //left motors
      digitalWrite(in1_1, LOW);
      digitalWrite(in1_2, HIGH);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    //right motors
      digitalWrite(in1_1, LOW);
      digitalWrite(in1_2, HIGH);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    break;
    case LEFT:
    //left motors
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, LOW);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    //right motors
      digitalWrite(in1_1, LOW);
      digitalWrite(in1_2, HIGH);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    break;
    case RIGHT:
    //left motors
      digitalWrite(in1_1, LOW);
      digitalWrite(in1_2, HIGH);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    //right motors
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, LOW);
      digitalWrite(in1_1, HIGH);
      digitalWrite(in1_2, HIGH);
    break;
  }

}