#include <Arduino.h>

// put function declarations here:

/*
function chooseMode chooses whether the robot goes forwards, backwards, left, or right based on input m
*/
int chooseMode(motion m);

/*
enum to define the cases that the motors will go through
*/
enum motion {FORWARD, BACK, LEFT, RIGHT, STAY};
  

int in1_1 = 4;
int in1_2 = 5;
int in2_1 = 6;
int in2_2 = 7;
motion checkMotion;

void setup() {
  pinMode(in1_1, OUTPUT); //
  pinMode(in1_2, OUTPUT); //
  pinMode(in2_1, OUTPUT); //
  pinMode(in2_2, OUTPUT); //
  motion m = STAY;
}

void loop() {
  motion m;
  m = FORWARD;
  delay(2000);
  m = BACK;
  delay(2000);
  m = LEFT;
  delay(2000);
  m = RIGHT;
  delay(2000);
}

int chooseMode(motion m) {
  switch (m) {
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
    case STAY:
    break;
  }

}