include <Servo.h>

Servo servoLeft;          // Define left servo

void setup() {
    servoLeft.attach(8);  // Set left servo to digital pin 8
}

void loop() {            // Loop through motion tests
  forward();             // Example: move forward
  delay(2000);           // Wait 2000 milliseconds (2 seconds)
  reverse();
  delay(2000);
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
  stopRobot();
  delay(2000);
}

// Motion routines for forward, reverse, turns, and stop
void forward() {
    servoLeft.write(0);
}

void reverse() {
    servoLeft.write(180);
}

void turnRight() {
    servoLeft.write(180);
}
void turnLeft() {
    servoLeft.write(0);
}

void stopRobot() {
    servoLeft.write(90);
}

