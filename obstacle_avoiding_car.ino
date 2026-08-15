#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

Servo scanServo;
long duration;
int distance;

// -------- SETUP --------
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  scanServo.attach(6);
  scanServo.write(0);   // Start at 0 degrees
  Serial.begin(9600);
}

// -------- MAIN LOOP --------
void loop() {
  scanServo.write(0);        // Look straight
  delay(200);
  distance = measureDistance();
  Serial.println(distance);

  if (distance > 0 && distance < 15) {
    stopCar();
    delay(300);

    // Rotate servo to 45° (check left)
    scanServo.write(45);
    delay(400);
    int leftDistance = measureDistance();
    scanServo.write(0);  // Return to center
    delay(300);

    if (leftDistance > 15) {
      turnLeft();
      delay(500);
    } else {
      turnRight();
      delay(500);
    }
  }
  else {
    moveForward();
  }
}

// -------- DISTANCE FUNCTION --------
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 20000);
  int dist = duration * 0.034 / 2;
  return dist;
}

// -------- MOVEMENT FUNCTIONS --------
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
