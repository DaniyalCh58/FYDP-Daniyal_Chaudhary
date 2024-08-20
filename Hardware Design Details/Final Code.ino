#include <SoftwareSerial.h>
#include <Arduino.h>
#define BT_RX 3 // Connect HC-05 TX to Arduino pin 3
#define BT_TX 2 // Connect HC-05 RX to Arduino pin 2
// Define the pins connected to the relays
const int pump = 4;
const int solenoid_close = 5;
const int solenoid_open = 6;
const int thumb = 7;
const int ind = 8;
const int middle = 9;
const int ring = 10;
const int pinky = 11;
char receivedChar;

SoftwareSerial BTSerial(BT_RX, BT_TX); // RX, TX

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  BTSerial.begin(9600);
  pinMode(pump, OUTPUT);
  pinMode(solenoid_close, OUTPUT);
  pinMode(solenoid_open, OUTPUT);
  pinMode(thumb, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(ring, OUTPUT);
  pinMode(pinky, OUTPUT);

  digitalWrite(pump, HIGH);
  digitalWrite(solenoid_close, HIGH);
  digitalWrite(solenoid_open, HIGH);
  digitalWrite(thumb, HIGH);
  digitalWrite(ind, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(ring, HIGH);
  digitalWrite(pinky, HIGH);}

void loop() {

 if (BTSerial.available()>0){
    // Read data from HC-05 and print it to the Serial monitor
    receivedChar = BTSerial.read();
    Serial.print(receivedChar);
 
  
if(receivedChar=='O')
{
  solenoid_close_all();
  //delay(3000);
  releas();
  Serial.print("Hand Opening");
}
if(receivedChar=='C')
{
  solenoid_open_all();
  //delay(3000);
  releas();
  Serial.print("Hand Closing");
}
 }
  
/*
  //Hand Close 3 Sec
  solenoid_close_all();
  delay(3000);
  releas();
  //Hand Open 3 Sec
  solenoid_open_all();
  delay(3000);
  releas();
  delay(5000);
  //COMB 1 Thumb Only 3 Sec
  comb1();
  delay(3000);
releas();
//COMB 1 Thumb Only 3 Sec
  comb2();
  delay(3000);   
releas();
*/
}

void solenoid_close_all()
{
  digitalWrite(pump, LOW);
  digitalWrite(solenoid_close, LOW);
  delay(3000);
  digitalWrite(pump, HIGH);
  digitalWrite(solenoid_close, HIGH);

}

//Thumb Only
void comb1()
{
  digitalWrite(thumb, HIGH);
  digitalWrite(ind, LOW);
  digitalWrite(middle, LOW);     // thumb only
  digitalWrite(ring, LOW);
  digitalWrite(pinky, LOW);

  digitalWrite(pump, LOW);
  digitalWrite(solenoid_close, LOW);
  delay(3000);

  digitalWrite(thumb, HIGH);
  digitalWrite(ind, HIGH);
  digitalWrite(middle, HIGH);   
  digitalWrite(ring, HIGH);
  digitalWrite(pinky, HIGH);
  
  digitalWrite(pump, HIGH);
  digitalWrite(solenoid_close, HIGH);
}

//All Fingers Except Thumb
void comb2()
{
  digitalWrite(thumb, HIGH);
  digitalWrite(ind, HIGH);
  digitalWrite(middle, HIGH);   
  digitalWrite(ring, LOW);
  digitalWrite(pinky, LOW);

  digitalWrite(pump, LOW);
  digitalWrite(solenoid_close, LOW);
  delay(3000);

  digitalWrite(thumb, HIGH);
  digitalWrite(ind, HIGH);
  digitalWrite(middle, HIGH);   
  digitalWrite(ring, HIGH);
  digitalWrite(pinky, HIGH);
  
  digitalWrite(pump, HIGH);
  digitalWrite(solenoid_close, HIGH);
}


void solenoid_open_all()
{
  digitalWrite(pump, LOW);
  digitalWrite(solenoid_open, LOW);
  delay(3000);
  digitalWrite(pump, HIGH);
  digitalWrite(solenoid_open, HIGH);
}
void releas()
{

  digitalWrite(solenoid_close, HIGH);
  digitalWrite(solenoid_open, LOW);
  delay(2000);
  digitalWrite(solenoid_close, LOW);
  digitalWrite(solenoid_open, HIGH);
  delay(2000);
  digitalWrite(solenoid_close, HIGH);
  digitalWrite(solenoid_open, HIGH);
}
