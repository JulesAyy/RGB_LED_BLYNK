/*
* Name: Jules A. Beszant
* Date: 04/08/20
* 
* This project is to introduce myself to the Arduino and the HC-05/06 Bluetooth module.
* The code will allow controlling of a RGB led through the HC-06 module with the
* Blynk app through my mobile phone.
* 
*   PCB Design:       https://i.imgur.com/U8HFBtFh.jpg
*               *** Correction ***
*               HC-06 replaced with HC-05
*               Red pin to pin D11
*               Green pin to pin D10
*               Blue pin to pin D9
*
*
* 15/08/20
*   Replaced HC-06 with HC-05 as the HC-06 seems faulty
*   Realised the pins shown on the board isn't the same as actual pins on datasheet
*
* 19/08/20
*   HC-06 Not faulty
*   
* 20/18/20
*   HC-06 is faulty but it does connect via bluetooth
*   Project Completed
*/

#define BLYNK_USE_DIRECT_CONNECT

#include <SoftwareSerial.h>
SoftwareSerial hc05(0,1); // RX, TX

#define BLYNK_PRINT hc05
#include <BlynkSimpleSerialBLE.h>

char auth[] = "UJ1ORPc18mMN8LkkBIfNVA4lODvB2hDI";

#define RED     11   // Define the pins for RGB
#define GREEN   10
#define BLUE    9

void setup() 
{
  Startup();
  
  // Setup bluetooth connection
  // HC05 uses a baud rate of 9600, not 38400
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop() 
{  
  Blynk.run();
}


BLYNK_WRITE(V3) // zeRGBa
{
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();

  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void Startup()
{
  // Setting up Pin for RGB LED, and set initial value to LOW
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  // Start up sequence
  digitalWrite(RED, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  
  digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(GREEN, LOW);
  
  digitalWrite(BLUE, HIGH);
  delay(1000);
  digitalWrite(BLUE, LOW);
}
