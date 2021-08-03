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

void setup(){
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

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results.value){
      case 0xFF30CF: 
        Serial.println("1");

        servo1.write(50);
        servo2.write(50);
        delay(200);
        servo5.write(50);
        servo6.write(50);
        delay(200);
        servo3.write(50);
        servo4.write(50);
        delay(200);
        servo7.write(50);
        servo8.write(50);
        
        delay(2000);

        servo1.write(130);
        servo2.write(130);
        delay(200);
        servo5.write(130);
        servo6.write(130);
        delay(200);
        servo3.write(130);
        servo4.write(130);
        delay(200);
        servo7.write(130);
        servo8.write(130);

        delay(2000);
        
        servo1.write(90);
        servo2.write(90);
        delay(200);
        servo5.write(90);
        servo6.write(90);
        delay(200);
        servo3.write(90);
        servo4.write(90);
        delay(200);
        servo7.write(90);
        servo8.write(90);
        
        delay(1000);
        
        break ;
      case 0xFF18E7:
        Serial.println("2");

       
       
        break ;
      case 0xFF7A85:
        Serial.println("3");

        
        break ;
      case 0xFF10EF:
        Serial.println("4");

        
        break ;
      case 0xFF38C7:
        Serial.println("5");

        
        
        break ;
      case 0xFF5AA5:
        Serial.println("6");

        
        
        break ;
      case 0xFF42BD:
        Serial.println("7");

        
        break ;
      case 0xFF4AB5:
        
        
        break ;
      case 0xFF52AD:
      
        break;

      default:
        break;
      }
      key_value = results.value;
      irrecv.resume(); 
  }
}
