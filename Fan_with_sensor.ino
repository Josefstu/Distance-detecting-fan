#include <SR04.h>

#define TRIG_PIN 11
#define ECHO_PIN 10
#define FAN 2

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;


void setup() {
  pinMode(FAN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);//Initialization of Serial Port
  delay(1000);

}

void loop() {
  // Clears the trigPin condition
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 100) {
    digitalWrite(FAN, HIGH);
  }
  else {
    digitalWrite(FAN, LOW);
  }

}
