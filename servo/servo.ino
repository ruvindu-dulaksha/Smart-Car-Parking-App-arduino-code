#include <Servo.h>

#define IR_PIN_1 2 // Entrance IR sensor pin
#define IR_PIN_2 3 // Exit IR sensor pin

#define SERVO_PIN_1 9 // Entrance gate servo pin
#define SERVO_PIN_2 10 // Exit gate servo pin

int entranceIRState = 0;
int exitIRState = 0;

Servo entranceServo;
Servo exitServo;

void setup() {
  pinMode(IR_PIN_1, INPUT);
  pinMode(IR_PIN_2, INPUT);

  entranceServo.attach(SERVO_PIN_1);
  exitServo.attach(SERVO_PIN_2);
}

void loop() {
  entranceIRState = digitalRead(IR_PIN_1);
  exitIRState = digitalRead(IR_PIN_2);

  if (entranceIRState == LOW) {
    // Object detected at entrance, open entrance gate
    entranceServo.write(90); // Move to 90 degrees
    delay(1000); // Wait for 2 seconds
    entranceServo.write(0); // Close gate
    delay(1000); // Wait for 2 seconds
  }

  if (exitIRState == LOW) {
    // Object detected at exit, open exit gate
    exitServo.write(90); // Move to 90 degrees
    delay(1000); // Wait for 2 seconds
    exitServo.write(0); // Close gate
    delay(1000); // Wait for 2 seconds
  }
}
