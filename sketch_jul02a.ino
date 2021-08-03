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

  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);
  servo7.attach(11);
  servo8.attach(12);
}

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results.value){
      case 0xFF30CF: 
        Serial.println("1");
        servo1.write(90);
        delay(1000);
        servo1.write(0);
        break ;
      case 0xFF18E7:
        Serial.println("2");
        servo2.write(90);
        delay(1000);
        servo2.write(0);
        break ;
      case 0xFF7A85:
        Serial.println("3");
        servo3.write(90);
        delay(1000);
        servo3.write(0);
        break ;
      case 0xFF10EF:
        Serial.println("4");
        servo4.write(90);
        delay(1000);
        servo4.write(0);
        break ;
      case 0xFF38C7:
        Serial.println("5");
        servo5.write(90);
        delay(1000);
        servo5.write(0);
        break ;
      case 0xFF5AA5:
        Serial.println("6");
        servo6.write(90);
        delay(1000);
        servo6.write(0);
        break ;
      case 0xFF42BD:
        Serial.println("7");
        servo7.write(90);
        delay(1000);
        servo7.write(0);
        break ;
      case 0xFF4AB5:
        Serial.println("8");
        servo8.write(90);
        delay(1000);
        servo8.write(0);
        break ;
      case 0xFF52AD:
        Serial.println("9");
        servo1.write(180);
        servo2.write(180);
        servo3.write(180);
        servo4.write(180);
        servo5.write(180);
        servo6.write(180);
        servo7.write(180);
        servo8.write(180);
        delay(1000);
        servo1.write(0);
        servo2.write(0);
        servo3.write(0);
        servo4.write(0);
        servo5.write(0);
        servo6.write(0);
        servo7.write(0);
        servo8.write(0);
        break ;      
      }
      key_value = results.value;
      irrecv.resume(); 
  }
}
