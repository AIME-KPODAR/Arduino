#include <Servo.h>

Servo barriere;

// HC-SR04
const int trigPin = 2;
const int echoPin = 3;

long duration;
float distance;

bool voitureDetectee = false;

void setup() {
  barriere.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  barriere.write(0); // barrière fermée
  Serial.begin(9600);
}

void loop() {

  distance = mesurerDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  // Détection voiture (ajuste 10-15 cm selon ton montage)
  if (distance > 0 && distance < 12 && voitureDetectee == false) {
    voitureDetectee = true;
    ouvrirBarriere();
  }

  if (distance > 15) {
    voitureDetectee = false;
  }
}

float mesurerDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}

void ouvrirBarriere() {
  barriere.write(90);   // ouverture
  delay(3000);          // temps ouvert
  barriere.write(0);    // fermeture
  delay(1000);
}