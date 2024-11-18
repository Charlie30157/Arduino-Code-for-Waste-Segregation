#include <Servo.h>

Servo s1;
Servo s2;

const int trig = 7;
const int echo = 6;
const int Resistance_signal = A0;
const int Resistance_signalt =A1;

long timeInMicro;
long distanceInCm;

void setup() {
  Serial.begin(9600);
  s1.attach(9);
  s2.attach(8);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = timeInMicro / 29 / 2;  // Calculate distance in centimeters
  Serial.print("Distance: ");
  Serial.print(distanceInCm);
  Serial.println(" cm");

  // Delay condition
  if (distanceInCm <= 20) {
    delay(3000);  // Delay for 3 seconds after detecting an object within 20 cm
  }

  // Measure resistance level
  int resistance = analogRead(Resistance_signal);
  Serial.print("Resistance level: ");
  Serial.println(resistance);

  int resistancet = analogRead(Resistance_signalt);
  Serial.print("Resistance level 2 : ");
  Serial.println(resistancet);

  // Servo control based on conditions
  if (distanceInCm <= 20 && resistance < 600 || distanceInCm <= 20 && resistancet < 600) {
    // Low resistance (moist soil) - Perform watering action
    s2.write(120);
    delay(2000);
    s1.write(90);
    delay(1500);
    s1.write(0);
    delay(1500);
    s2.write(0);
  } else if (distanceInCm <= 20 && resistance > 600 || distanceInCm <= 20 && resistancet > 600) {
    // High resistance (dry soil) - Perform alternate action
    s2.write(180);
    delay(2000);
    s1.write(90);
    delay(2000);
    s1.write(0);
    delay(1000);
    s2.write(0);
  } else {
    // Reset servos to default positions if conditions are not met
    s1.write(0);
    s2.write(0);
  }

  delay(500);  // Delay between loop iterations
}
