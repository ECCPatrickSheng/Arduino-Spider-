#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>

// Setting up variables
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

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

  // Setting up pins
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

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results.value){
      case 0xFF6897:
        Serial.println("0");

        // Lift up left front leg
        servo1.write(20);
        servo2.write(20);
        delay(2000);
        
        break ;
      case 0xFF18E7:
        Serial.println("2");

        // Moving forward

        // Controlling left front and back legs
        servo1.write(20);
        servo2.write(20);
        servo5.write(20);
        servo6.write(20);
        delay(500);
        // Controlling right front and back legs
        servo3.write(160);
        servo4.write(160);
        servo7.write(160);
        servo8.write(160);
        delay(1200);
        // Reseting legs back to 90 degrees
        servo1.write(90);
        servo2.write(90);
        servo5.write(90);
        servo6.write(90);
        servo3.write(90);
        servo4.write(90);
        servo7.write(90);
        servo8.write(90);
        delay(500);
       
        break ;
      case 0xFF7A85:
        Serial.println("3");

        // Lift up right front leg
        servo3.write(160);
        servo4.write(160);
        delay(2000);
        
        break ;
      case 0xFF10EF:
        Serial.println("4");

        // Lift up both left front and back legs
        servo1.write(20);
        servo2.write(20);
        servo5.write(20);
        servo6.write(20);
        delay(2000);
        
        
        break ;
      case 0xFF38C7:
        Serial.println("5");

        // Dancing movement
        servo1.write(180);
        delay(1000);
        servo2.write(180);
        delay(1000);
        servo3.write(180);
        delay(1000);
        servo4.write(180);
        delay(1000);
        servo5.write(180);
        delay(1000);
        servo6.write(180);
        delay(1000);
        servo7.write(180);
        delay(1000);
        servo8.write(180);
        delay(1000);
        servo1.write(90);
        servo2.write(90);
        servo7.write(90);
        servo8.write(90);
        delay(1000);
        servo3.write(90);
        servo4.write(90);
        servo5.write(90);
        servo6.write(90);
        delay(1000);
        
        break ;
      case 0xFF5AA5:
        Serial.println("6");

        // Lift up both right front and back legs
        servo3.write(160);
        servo4.write(160);
        servo7.write(160);
        servo8.write(160);
        delay(2000);
         
        break ;
      case 0xFF42BD:
        Serial.println("7");

        // Lift up left back leg
        servo5.write(20);
        servo6.write(20);
        delay(2000);
        
        break ;
      case 0xFF4AB5:
        Serial.println("8");

        // Moving backwards

        // Controlling left front and back legs
        servo1.write(130);
        servo2.write(130);
        servo5.write(150);
        servo6.write(150);
        delay(500);
        // Controlling right front and back legs
        servo3.write(50);
        servo4.write(50);
        servo7.write(30);
        servo8.write(30);
        delay(1200);
        // Reseting legs back to 90 degrees
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

        break ;
      case 0xFF52AD:
        Serial.println("9");

        // Lift up right back leg
        servo7.write(160);
        servo8.write(160);
        delay(2000);
        
        break ;

      default:

        // Reset angle if no action were detected
        servo1.write(90);
        servo2.write(90);
        servo5.write(90);
        servo6.write(90);
        servo3.write(90);
        servo4.write(90);
        servo7.write(90);
        servo8.write(90);
        delay(500);
        break;
      }

      // Read last key value if same key was pressed
      key_value = results.value;

      // Repeat and collect IR signal
      irrecv.resume(); 
  }
}
