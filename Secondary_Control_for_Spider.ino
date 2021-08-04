#include <Servo.h>

// Setting up variables
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

const int JoystickYAxis = A0;

void setup() {

  Serial.begin(9600);

  // Set up for pins
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(8);
  servo6.attach(9);
  servo7.attach(10);
  servo8.attach(11);

  // Original angle 90 degrees
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  servo7.write(90);
  servo8.write(90);
}

void loop() {
  int YAxis = analogRead(JoystickYAxis); // Read Joysticks Y-axis(Forward or Backwards)
  
  if (YAxis < 450) { 

    // Controlling left front and back leg
    servo1.write(20);
    servo2.write(20);
    servo5.write(20);
    servo6.write(20);
    delay(500);
    // Controlling right front and back leg
    servo3.write(160);
    servo4.write(160);
    servo7.write(160);
    servo8.write(160);
    delay(1200);
    // Reseting back to origianl position
    servo1.write(90);
    servo2.write(90);
    servo5.write(90);
    servo6.write(90);
    servo3.write(90);
    servo4.write(90);
    servo7.write(90);
    servo8.write(90);
    delay(1200);
  }
  else if (YAxis > 550) { 
    // Controlling left front and back leg
    servo1.write(130);
    servo2.write(130);
    servo5.write(150);
    servo6.write(150);
    delay(500);
    // Controlling right front and back leg
    servo3.write(50);
    servo4.write(50);
    servo7.write(30);
    servo8.write(30);
    delay(1200);
    // Reseting back to origianl position, with delay
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    delay(500);
    servo5.write(90);
    servo6.write(90);
    servo7.write(90);
    servo8.write(90);        
    delay(500);
  }
  // For debugging purpose
  Serial.println(YAxis);
}
