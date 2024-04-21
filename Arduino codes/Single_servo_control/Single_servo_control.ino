#include <Servo.h>

// Define servo object
Servo servoMotor;

// Define servo pin
int servoPin = 9; // Change to the pin number connected to the servo

void setup() {
  // Attach servo to its pin
  servoMotor.attach(servoPin);
}

void loop() {
  // Set servo motor speed and direction
  for (int i = 0; i < 3; i++) {
    setVelocity(-255); // Rotate counterclockwise at full speed
    delay(50); // Wait for 50 milliseconds
  }
  setVelocity(0);
  delay(5000); // Wait for 10 seconds before repeating the loop
}

void setVelocity(int vel) {
  // Map the velocity value to the appropriate range for the servo
  int mappedVelocity = map(vel, -255, 255, 1000, 2000); // Map velocity from -100 to 100 to pulse width range
  
  // Set the speed and direction of the servo using the PWM signal
  servoMotor.writeMicroseconds(mappedVelocity);
}

