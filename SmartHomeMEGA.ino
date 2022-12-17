// Libraries for servo and remote - garage control
#include <IRremote.hpp>
#include <Servo.h>

// Garage Door parameters:
#define Garage_Open 12
#define Garage_Close 24
#define IR_Receive_Pin 33
Servo garage;

int incomingChar = 0; //For serial communication between the UNO WiFi Rev.2, and MEGA

// Sensor and Room Light Parameters:
int IRSensor1 = 2;
int IRSensor2 = 3;
int IRSensor3 = 4;
int IRSensor4 = 5;
int IRSensor5 = 6;
int IRSensor6 = 7;
int IRSensor7 = 8;
int IRSensor8 = 9;

int RoomLight1 = 22;
int RoomLight2 = 23; 
int RoomLight3 = 24; 
int RoomLight4 = 25; 
int RoomLight5 = 26; 
int RoomLight6 = 27; 
int RoomLight7 = 28; 
int RoomLight8 = 29; 
int RoomLight9 = 30; 


void setup() {
  //Communication scheme for IR signals
  IrReceiver.begin(IR_Receive_Pin);
  //Serial communication setup for UNO and MEGA - default baud rate
  Serial.begin(9600);
  Serial1.begin(9600);
  //Sensors act as inputs
  pinMode (IRSensor1, INPUT);
  pinMode (IRSensor2, INPUT);
  pinMode (IRSensor3, INPUT);
  pinMode (IRSensor4, INPUT);
  pinMode (IRSensor5, INPUT);
  pinMode (IRSensor6, INPUT);
  pinMode (IRSensor7, INPUT);
  pinMode (IRSensor8, INPUT);
  //Lights act as outputs
  pinMode (RoomLight1, OUTPUT);
  pinMode (RoomLight2, OUTPUT);
  pinMode (RoomLight3, OUTPUT);
  pinMode (RoomLight4, OUTPUT);
  pinMode (RoomLight5, OUTPUT);
  pinMode (RoomLight6, OUTPUT);
  pinMode (RoomLight7, OUTPUT);
  pinMode (RoomLight8, OUTPUT);
  pinMode (RoomLight9, OUTPUT);
  //Garage door parameters, setting initial position to 0 degrees (closed)
  garage.attach(32);
  garage.write(0);
}

void loop() {
  // Occupancy-based lighting - read input from the sensors
  int sensorstatus1 = digitalRead(IRSensor1);
  int sensorstatus2 = digitalRead(IRSensor2);
  int sensorstatus3 = digitalRead(IRSensor3);
  int sensorstatus4 = digitalRead(IRSensor4);
  int sensorstatus5 = digitalRead(IRSensor5);
  int sensorstatus6 = digitalRead(IRSensor6);
  int sensorstatus7 = digitalRead(IRSensor7);
  int sensorstatus8 = digitalRead(IRSensor8);

 //Defined heirarchy - the sensor input takes precedence over the manual input over WiFi
  if (sensorstatus1 != 1)
  {
    digitalWrite(RoomLight1, HIGH);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, LOW);
  }
  else if (sensorstatus2 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, HIGH);
    digitalWrite(RoomLight3, HIGH);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, LOW);
  }
  //Due to sensor malfunctioning, sensor 2 takes over sensor 3's corresponding room light.
  //else if (sensorstatus3 != 1)
  //{
   // digitalWrite(RoomLight1, LOW);
    //digitalWrite(RoomLight2, LOW);
    //digitalWrite(RoomLight3, HIGH);
    //digitalWrite(RoomLight4, LOW);
    //digitalWrite(RoomLight5, LOW);
    //digitalWrite(RoomLight6, LOW);
    //digitalWrite(RoomLight7, LOW);
    //digitalWrite(RoomLight8, LOW);
  //}
  else if (sensorstatus4 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, HIGH);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, LOW);
  }
  else if (sensorstatus5 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, HIGH);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, LOW);
  }
  else if (sensorstatus6 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, HIGH);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, LOW);
  }
  else if (sensorstatus7 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, HIGH);
    digitalWrite(RoomLight8, LOW);
  }
  else if (sensorstatus8 != 1)
  {
    digitalWrite(RoomLight1, LOW);
    digitalWrite(RoomLight2, LOW);
    digitalWrite(RoomLight3, LOW);
    digitalWrite(RoomLight4, LOW);
    digitalWrite(RoomLight5, LOW);
    digitalWrite(RoomLight6, LOW);
    digitalWrite(RoomLight7, LOW);
    digitalWrite(RoomLight8, HIGH);
  }  

// Wifi-Controlled Lights at will, priority lower than sensor input
    if (Serial1.available()>0){
    incomingChar = Serial1.read();
    Serial1.flush();
    switch(incomingChar){
      case 'A':
        digitalWrite(RoomLight1,HIGH);break;
      case 'a':
        digitalWrite(RoomLight1,LOW); break;
      
      case 'B':
        digitalWrite(RoomLight2,HIGH);break;
      case 'b':
        digitalWrite(RoomLight2,LOW); break;

      case 'C':
        digitalWrite(RoomLight3,HIGH);break;
      case 'c':
        digitalWrite(RoomLight3,LOW); break;
      
      case 'D':
        digitalWrite(RoomLight4,HIGH);break;
      case 'd':
        digitalWrite(RoomLight4,LOW); break;
        
      case 'E':
        digitalWrite(RoomLight5,HIGH);break;
      case 'e':
        digitalWrite(RoomLight5,LOW); break;

      case 'F':
        digitalWrite(RoomLight6,HIGH);break;
      case 'f':
        digitalWrite(RoomLight6,LOW); break;

      case 'G':
        digitalWrite(RoomLight7,HIGH);break;
      case 'g':
        digitalWrite(RoomLight7,LOW); break;

      case 'H':
        digitalWrite(RoomLight8,HIGH);break;
      case 'h':
        digitalWrite(RoomLight8,LOW); break;

      case 'I':
        digitalWrite(RoomLight9,HIGH);break;
      case 'i':
        digitalWrite(RoomLight9,LOW); break;
      default:
        break;

    //Garage door control scheme
    if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      //if OPEN signal received - open garage door and turn on light
      case Garage_Open: break;
      {
      garage.write(90);
      digitalWrite(RoomLight9, HIGH);
      }
      break;

      //if CLOSE signal received - close garage door and turn off light
      case Garage_Close: 
      {
      garage.write(0);
      digitalWrite(RoomLight9, LOW);
      }
      break;
      }
    }
  }
}
}

