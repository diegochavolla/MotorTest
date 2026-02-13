#include <Arduino.h>

enum motion {FORWARD, BACK, LEFT, RIGHT, STAY};

// Motor A (Left)
const int IN1 = 4;
const int IN2 = 5;
const int ENA = 9;   // PWM

// Motor B (Right)
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 10;  // PWM

const int DEFAULT_SPEED = 200;  // 0–255

void chooseMode(motion m, int speed);
motion convertCommand(char c);

void setup() {

  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  chooseMode(STAY, 0);
}

void loop() {

  if (Serial.available()) {

    char direction = Serial.read();

    // If stop command
    if (direction == 'S') {
      chooseMode(STAY, 0);
      return;
    }

    // Read movement duration (milliseconds)
    int duration = Serial.parseInt();

    motion m = convertCommand(direction);

    chooseMode(m, DEFAULT_SPEED);

    delay(duration);

    chooseMode(STAY, 0);
  }
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

void chooseMode(motion m, int speed) {

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
