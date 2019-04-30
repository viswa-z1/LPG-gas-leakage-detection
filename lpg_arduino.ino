

#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); 
String textForSMS;
int smokeS = A1;   
int data = 0;


void setup() 
{
 randomSeed(analogRead(0));
  
  Serial.begin(9600);
 SIM900.begin(9600); 
  pinMode(smokeS, INPUT); 
}

void loop() 
{
  data = analogRead(smokeS); 
  
  Serial.print("Gas Level :"); 
  Serial.println(data); 
 
  
     if ( data >290) 
  {
       textForSMS =  "Attention Required Gas Detected";  
  sendSMS(textForSMS);
  Serial.println(textForSMS);
  Serial.println("message sent."); 
delay(3000);
while(1)
{
  
}
  }
}


void sendSMS(String message)
{
  SIM900.print("AT+CMGF=1\r");                     
  delay(1000);
 SIM900.println("AT + CMGS = \"+917010784978\""); 
 
  delay(1000);
  SIM900.println(message);                        
  delay(1000);
  SIM900.println((char)26);                       
  delay(1000); 
  SIM900.println();
  delay(100);                                     
                                   
}
