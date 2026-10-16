// Two-Sensor Line-Following Robot
// Left IR Sensor -> Pin 6
// Right IR Sensor -> Pin 7
//
// Motor Driver:
// IN1 -> Pin 2
// IN2 -> Pin 3
// IN3 -> Pin 4
// IN4 -> Pin 5

const int LEFT_SENSOR = 6;
const int RIGHT_SENSOR = 7;

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// Set according to your IR sensor output.
const bool LINE_IS_LOW = true;

bool detectsLine(int pin) {
  int value = digitalRead(pin);

  if (LINE_IS_LOW) {
    return value == LOW;
  }

  return value == HIGH;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
}

void loop() {
  bool leftLine = detectsLine(LEFT_SENSOR);
  bool rightLine = detectsLine(RIGHT_SENSOR);

  if (leftLine && rightLine) {
    moveForward();
  }
  else if (leftLine && !rightLine) {
    turnLeft();
  }
  else if (!leftLine && rightLine) {
    turnRight();
  }
  else {
    stopRobot();
  }

  delay(10);
}
