#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); 

int interruptPin = 3;
#define bulb 5
#define PIR 6

int bulbread;
void setup()
{
  Serial.begin(9600);   
  pinMode(bulb,OUTPUT);
  digitalWrite(bulb,HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin),Inc1,FALLING);
  pinMode(PIR, INPUT);
  dht.begin();  
  
  }

int unit=0;
int p=0;
int t;
int Flag=1;
void loop() 
{ 
  int Val=2; // threshold   
  t = (int)dht.readTemperature();
  int pd=digitalRead(PIR); 
 if (unit<Val){
  if(pd==1){
    digitalWrite(bulb,LOW);
    delay(1000);
    }
  if(t>30){
    digitalWrite(bulb,LOW);
    delay(1000);
    }  
  if(pd==0 && t<30){
    digitalWrite(bulb,HIGH);
    }
 }
 else{
     digitalWrite(bulb,HIGH);
     if(Flag==1){
      Serial.println("E");
      Flag=2;
      } 
 }    

     
 if(p==3){
    p=0;
    unit++;}
    
  Serial.println(unit); 
  
  delay(2000);
}


void Inc1(){
  p++;
  }
