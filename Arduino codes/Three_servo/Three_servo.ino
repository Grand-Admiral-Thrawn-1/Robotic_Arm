#include <Servo.h>

// Define servo object
Servo servo1;
Servo servo2;
Servo servo3;
//Servo servo4;

// input the coordinates needed to be moved to
int x,y,z,t;

// x= x coordinate
// y= y coordinate
// z= z coordinate
// t= tool type

void setup() {
  // Attach servo to its pin
  servo1.attach(10);
  servo2.attach(7);  
  servo3.attach(12);
//  servo4.attach(13);
// servo1 base rotation
  for (int i = 0; i < 2; i++) {
    setVelocity(servo1, -255); // Move servo 1 at full speed clockwise
    delay(1000);// prev 1500
  }
  setVelocity(servo1, 0);
  delay(500);

//servo2 base arm rotation
  for (int i = 0; i < 3; i++) {
    setVelocity(servo2, 255); // Move servo 2 at full speed anticlockwise
    delay(150);
  }
  setVelocity(servo2, 0);
  delay(100);

//servo3 end effector rotation
  for (int i = 0; i < 2; i++) {
    setVelocity(servo3, 255); // Move servo 3 at full speed clockwise
    delay(500);
  }
  setVelocity(servo3, 0);
  delay(500);

}

//servo4 mid arm rotation
  for (int i = 0; i < 2; i++) {
    setVelocity(servo3, 255); // Move servo 4 at full speed clockwise
    delay(500);
  }
  setVelocity(servo3, 0);
  delay(100);

}
*/
void loop() {
  
}

void setVelocity(Servo servo, int vel) {
  // Map the velocity value to the appropriate range for the servos
  int mappedVelocity = map(vel, -255, 255, 1000, 2000); // Map velocity from -255 to 255 to pulse width range
  
  // Set the speed and direction of the servo using the PWM signal
  servo.writeMicroseconds(mappedVelocity);
}
