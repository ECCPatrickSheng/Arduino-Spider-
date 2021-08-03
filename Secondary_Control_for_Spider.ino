#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

const int JoystickYAxis = A1;
const int JoystickXAxis = A0;

void setup() {

  Serial.begin(9600);

  irrecv.enableIRIn();

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);

  servo5.attach(8);
  servo6.attach(9);
  servo7.attach(10);
  servo8.attach(11);

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
  
  
  if (YAxis < 500) { 
    servo1.write(20);
    servo2.write(20);
    servo5.write(20);
    servo6.write(20);
    delay(500);

    servo3.write(160);
    servo4.write(160);
    servo7.write(160);
    servo8.write(160);
    
    delay(1200);

    servo1.write(90);
    servo2.write(90);
    servo5.write(90);
    servo6.write(90);
    servo3.write(90);
    servo4.write(90);
    servo7.write(90);
    servo8.write(90);
    delay(500);
    
  }
  else if (YAxis > 524) { 
    servo1.write(160);
    servo2.write(160);
    servo5.write(160);
    servo6.write(160);
    delay(500);

    servo3.write(20);
    servo4.write(20);
    servo7.write(20);
    servo8.write(20);
    
    delay(1200);

    servo1.write(90);
    servo2.write(90);
    servo5.write(90);
    servo6.write(90);
    servo3.write(90);
    servo4.write(90);
    servo7.write(90);
    servo8.write(90);
    delay(500);
  }

  Serial.println(YAxis);
}
