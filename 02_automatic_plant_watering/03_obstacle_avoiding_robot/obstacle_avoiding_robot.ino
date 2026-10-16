// Obstacle-Avoiding Robot
// HC-SR04 Ultrasonic Sensor
// TRIG -> Pin 9
// ECHO -> Pin 10
//
// Motor Driver Inputs:
// IN1 -> Pin 2
// IN2 -> Pin 3
// IN3 -> Pin 4
// IN4 -> Pin 5

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

const int OBSTACLE_DISTANCE = 20;

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return 999;
  }

  return duration / 58;
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  stopRobot();
}

void loop() {
  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > OBSTACLE_DISTANCE) {
    moveForward();
  } else {
    stopRobot();
    delay(200);

    moveBackward();
    delay(350);

    stopRobot();
    delay(150);

    turnRight();
    delay(450);

    stopRobot();
  }

  delay(50);
}
