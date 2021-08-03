#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

Servo servo1;
Servo servo2;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

  servo1.attach(4);
  servo2.attach(5);

  
}

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results.value){
      case 0xFF30CF: 
        Serial.println("1");
        servo1.write(180);
        delay(1000);
        servo1.write(90);
        break ;
      case 0xFF18E7:
        Serial.println("2");
        servo2.write(180);
        delay(1000);
        servo2.write(90);
        break ;
      case 0xFF7A85:
        Serial.println("3");
        servo1.write(0);
        delay(1000);
        servo1.write(90);
        break ;
      case 0xFF10EF:
        Serial.println("4");
        servo2.write(0);
        delay(1000);
        servo2.write(90);
        break ;
      case 0xFF38C7:
        Serial.println("5");
        for (int pos = 0; pos <= 180; pos += 1) {
          servo1.write(pos);
          delay(15);
        }
        for (int pos = 180; pos >= 0; pos -= 1) {
          servo1.write(pos);
          delay(15);
        }
        break ;
      case 0xFF5AA5:
        Serial.println("6");
        
        break ;
      case 0xFF42BD:
        Serial.println("7");
        
        break ;
      case 0xFF4AB5:
        Serial.println("8");
        
        break ;
      case 0xFF52AD:
        Serial.println("9");
        servo1.write(180);
        servo2.write(180);
        
        delay(1000);
        servo1.write(0);
        servo2.write(0);
        
        break ;      
      }
      key_value = results.value;
      irrecv.resume(); 
  }
}
