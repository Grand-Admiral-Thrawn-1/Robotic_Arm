#include <Servo.h>

// Define servo object
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// input the coordinates needed to be moved to
int x,y,z,t;

// x= x coordinate
// y= y coordinate
// z= z coordinate
// t= tool type

void setup() {
  // Attach servo to its pin
  servo1.attach(9);
  servo1.attach(10);
  servo1.attach(11);
  servo1.attach(12);
}

void loop() {
  
}

void setVelocity(int vel) {
  // Map the velocity value to the appropriate range for the servo
  int mappedVelocity = map(vel, -255, 255, 1000, 2000); // Map velocity from -100 to 100 to pulse width range
  
  // Set the speed and direction of the servo using the PWM signal
  servo1.writeMicroseconds(mappedVelocity);
  servo2.writeMicroseconds(mappedVelocity);
  servo3.writeMicroseconds(mappedVelocity);
  servo4.writeMicroseconds(mappedVelocity);
}
