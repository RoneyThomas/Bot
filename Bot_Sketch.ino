#include <Servo.h>
char incomingByte;  // incoming data
int  LED = 12;      // LED pin
Servo servo1;
Servo servo2;
 
void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}
 
void loop() {
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    if(incomingByte == '1') {
       attach();
       servo1.write(0);
       servo2.write(180);
       Serial.println("Forwards");  
    }
    if(incomingByte == '2') {
       attach();
       servo1.write(180);
       servo2.write(0);
       digitalWrite(LED, HIGH); 
       Serial.println("Backwards");
    }
    if(incomingByte == '3') {
       attach();
       servo1.write(0);
       servo2.detach();
       digitalWrite(LED, HIGH); 
       Serial.println("Right");
    }
    if(incomingByte == '4') {
       attach();
       servo2.write(180);
       servo1.detach();
       digitalWrite(LED, HIGH); 
       Serial.println("Left");
    }
    if(incomingByte == '5') {
       servo2.detach();
       servo1.detach();
       digitalWrite(LED, LOW); 
       Serial.println("Off");
    }
  }
}

void attach(){
  servo1.attach(9);
  servo2.attach(10);
  Serial.println("On");
}
