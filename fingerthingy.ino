// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
const int servoPin = 3; 
const int switchPin = 4;
const int buttonPinR = 5;
const int buttonPinM = 6;
const int buttonPinL = 7;
const int trigPin = 9;
const int echoPin = 10;
const int rourkePin = 8;
int marr = 0;
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(switchPin, INPUT);
   pinMode(buttonPinR, INPUT);
   pinMode(buttonPinM, INPUT);
   pinMode(buttonPinL, INPUT);
   pinMode(rourkePin, INPUT);
   Serial.begin(9600);
  Servo1.write(180);   

}


void loop(){ 
   
   
   int valR = digitalRead(buttonPinR);
   int valM = digitalRead(buttonPinM);
   int valL = digitalRead(buttonPinL);
   int morrissey = digitalRead(switchPin);
   int rourke = digitalRead(rourkePin);   


      long duration, inches, cm;
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
  


 
if (marr ==   1){
     if(cm <= 15){
      int theta = cm * (180 / 15);        

      Serial.println(theta);
  
    Servo1.write(theta); }  
       

    else{Servo1.write(180);}

    delay(100);

   if(rourke == 1){
     marr = 0;
     Servo1.write(180);
   }
}
else{
  if(valR == 1 ){Servo1.write(180);}
   if(valM == 1 ){Servo1.write(90);}
   if(valL == 1 ){Servo1.write(0);}
     if(morrissey == 1){
     marr = 1;
   }
}

}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
