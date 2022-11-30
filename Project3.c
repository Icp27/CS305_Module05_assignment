# Project 3 Code

#include <AFMotor.h>
#include <Wire.h>
#include <IRremote.h>

#define on 0xFFA25D
#define zero 0xFF6897
#define one 0xFF30CF
#define two 0xFF18E7
#define three 0xFF7A85
#define four 0xFF10EF
#define five 0xFF38C7
#define six 0xFF5AA5
#define seven 0xFF42BD
#define eight 0xFF4AB5
#define nine 0xFF52AD

//Setting Motors
int Lspeed=0;
int Rspeed=0;
AF_DCMotor LeftMotor(3);
AF_DCMotor RightMotor(4);
int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600); // Begin the serial
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  while(irrecv.decode(&results)==0){ 
 }
if (irrecv.decode(&results)) {
      //Serial.println(results.value, HEX);

      // Set the speed to start, from 0 (off) to 255 (max speed)
      if(results.value == on){
        Serial.println("ON");
      }
      else if(results.value == zero){
        Serial.println("ZERO");   
        LeftMotor.setSpeed(0);
        LeftMotor.run(FORWARD);
        RightMotor.setSpeed(0);
        RightMotor.run(FORWARD);
      }
      else if(results.value == one){
        Serial.println("ONE");
        Lspeed=Lspeed+25;
        Rspeed=Rspeed+25;
        LeftMotor.setSpeed(Lspeed);
        LeftMotor.run(BACKWARD);
        RightMotor.setSpeed(Rspeed);
        RightMotor.run(FORWARD);
      }
      else if(results.value == two){
        Serial.println("TWO");
        Lspeed=Lspeed+25;
        Rspeed=Rspeed+25;
        LeftMotor.setSpeed(Lspeed);
        LeftMotor.run(FORWARD);
        RightMotor.setSpeed(Rspeed);
        RightMotor.run(FORWARD);
      }
      else if(results.value == three){
        Serial.println("THREE");
        Lspeed=Lspeed+25;
        Rspeed=Rspeed+25;
        LeftMotor.setSpeed(Lspeed);
        LeftMotor.run(FORWARD);
        RightMotor.setSpeed(Rspeed);
        RightMotor.run(BACKWARD);
      }
      else if(results.value == four){
        Serial.println("FOUR");
      }
      else if(results.value == five){
        Serial.println("FIVE");
        Lspeed=Lspeed-25;
        Rspeed=Rspeed-25;
        LeftMotor.setSpeed(Lspeed);
        LeftMotor.run(FORWARD);
        RightMotor.setSpeed(Rspeed);
        RightMotor.run(FORWARD);
      }
      else if(results.value == six){
        Serial.println("SIX");
      }
      else if(results.value == seven){
        Serial.println("SEVEN");
      }
      else if(results.value == eight){
        Serial.println("EIGHT");
        Lspeed=Lspeed+25;
        Rspeed=Rspeed+25;
        LeftMotor.setSpeed(Lspeed);
        LeftMotor.run(BACKWARD);
        RightMotor.setSpeed(Rspeed);
        RightMotor.run(BACKWARD);
        
      }
      else if(results.value == nine){
        Serial.println("NINE");
      }
}
delay(200);
irrecv.resume(); // Receive the next value
  
}
