#include <SoftwareSerial.h>
SoftwareSerial BTserial(4,5); 

//arms
int state = 0;
int distance = 0;
const int belt = 6;

//central buzzer_left and central ultrasonic sensor
const int buzzer_central = 8;
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

void setup() {

    Serial.begin(9600);
    BTserial.begin(38400);

    pinMode(buzzer_central,OUTPUT);
}

void loop() {


  if(cm<=70.0)
    {
        digitalWrite(buzzer_central,HIGH);
        delay(200);
        digitalWrite(buzzer_central,LOW);
    }
  else if(BTSerial.available())
  {
      state=BTSerial.read();
      switch(state)
      {
            case'1':
            BTSerial.write('1');
            distance=BTSerial.read();
            if(distance<=70)
            {
                BTSerial.Write("Right_alert");
            }
            break;

            case'2':
            BTSerial.write('2');
            distance=BTSerial.read();
            if(distance<=70)
            {
                BTSerial.Write("left_alert");
            }
            break;

            default:
            break;
      }
  }
}