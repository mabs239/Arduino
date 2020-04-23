  /*   
HC05 - Bluetooth AT-Command mode  
modified on 10 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
*/ 
#include <SoftwareSerial.h> 
#include <Servo.h>

SoftwareSerial MyBlue(2, 3); // RX | TX 
Servo myservo;  // create servo object to control a servo

char flag = '0'; 
int LED = 13; 
int pos = 90;    // variable to store the servo position

void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(LED, OUTPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
 MyBlue.write("Allah \n");
 myservo.attach(8);  // attaches the servo on pin 9 to the servo object

} 
void loop() 
{ 
 if (MyBlue.available()) 
   flag = MyBlue.read(); 
 if (flag == '1') 
 { pos = 0;
   digitalWrite(LED, HIGH); 
   myservo.write(pos); 
   Serial.println("LED On"); 
 } 
 else if (flag == '0') 
 { pos = 180;
   digitalWrite(LED, LOW); 
   myservo.write(pos); 
   Serial.println("LED Off"); 
 } 
 flag = 'a';
 if(pos<1 || pos>179) pos = 90;
 
}  
