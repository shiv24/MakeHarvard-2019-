// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int nudge = 7
// defines variables
long duration;
int distance;


void setup() {
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(nudge, OUTPUT);
    Serial.begin(9600); 
}


void loop() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;

    if (distance < 70) {
      digitalWrite(nudge, HIGH)
    } else {
      digitalWrite(nudge, LOW)
    }
    Serial.print("Distance: ");
    Serial.println(distance);
}
