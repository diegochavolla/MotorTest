#include <Arduino.h>

enum motion {FORWARD, BACK, LEFT, RIGHT, STAY};

// Left side
const int IN1 = 4;
const int IN2 = 5;
const int ENA = 9;   // PWM

// Right side
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 10;  // PWM

const int TEST_SPEED = 200;  // 0–255

const int DEFAULT_SPEED = 200;  // 0–255

void drive(motion m, int speed);

motion convertCommand(char c);

void setup() {

  //Serial.begin(9600); //uncomment for working model

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  drive(STAY, 0);
}

/**
 * Example of python implementation for pi
 * 
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)

ser.write(b'F3000')  # forward 3 seconds
time.sleep(4)

ser.write(b'L800')   # turn left
time.sleep(1)

ser.write(b'S')      # stop
 */
// void loop() { //uncomment for working model

//   if (Serial.available()) {

//     char direction = Serial.read();

//     // If stop command
//     if (direction == 'S') {
//       drive(STAY, 0);
//       return;
//     }

//     // Read movement duration (milliseconds)
//     int duration = Serial.parseInt();

//     motion m = convertCommand(direction);

//     drive(m, DEFAULT_SPEED);

//     delay(duration);

//     drive(STAY, 0);
//   }
// }

void loop() { //testing loop, comment for working model

  // STOP
  drive(STAY, 0);
  delay(2000);

  // FORWARD
  drive(FORWARD, TEST_SPEED);
  delay(3000);

  // STOP
  drive(STAY, 0);
  delay(1000);

  // BACKWARD
  drive(BACK, TEST_SPEED);
  delay(3000);

  // STOP
  drive(STAY, 0);
  delay(1000);

  // TURN LEFT
  drive(LEFT, TEST_SPEED);
  delay(1500);

  // STOP
  drive(STAY, 0);
  delay(1000);

  // TURN RIGHT
  drive(RIGHT, TEST_SPEED);
  delay(1500);

  // STOP
  drive(STAY, 0);
  delay(3000);
}

motion convertCommand(char c) {
  switch (c) {
    case 'F': return FORWARD;
    case 'B': return BACK;
    case 'L': return LEFT;
    case 'R': return RIGHT;
    default:  return STAY;
  }
}

void drive(motion m, int speed) {

  switch (m) {

    case FORWARD:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case BACK:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

    case LEFT:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case RIGHT:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

    case STAY:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      speed = 0;
      break;
  }

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}