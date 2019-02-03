#include <SoftwareSerial.h>
SoftwareSerial BTserial(4,5); 

//arms
int state = 0;
int distance = 0;
const int left_arm = 6;

//central buzzer_left and central ultrasonic sensor
const int buzzer_left = 8;
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

void setup() {

    Serial.begin(9600);
    BTserial.begin(38400);

    pinMode(buzzer_left,OUTPUT);
}

void loop() {


  if(cm<=70.0)
    {
        if(BTSerial.available())
        {
        BTSerial.write('2');
        if(BTSerial.read()=='2')
        {
            BTSerial.write(cm);
            if(BTSerial.read()=="left_alert")
            {
            digitalWrite(buzzer_left,HIGH);
            delay(200);
            digitalWrite(buzzer_left,LOW);
            }
       
        }

        }
        
        
    }
  
}