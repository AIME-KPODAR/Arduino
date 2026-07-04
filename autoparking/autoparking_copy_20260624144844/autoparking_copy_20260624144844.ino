#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo barriere;

int ledVerte = 7;
int ledRouge = 8;
int entree = A0;
int sortie = A1;

int places = 5;

void setup() {
  barriere.attach(9);

  pinMode(entree, INPUT);
  pinMode(sortie, INPUT);

  pinMode(ledVerte, OUTPUT);
  pinMode(ledRouge, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Parking System");

  barriere.write(0); // barrière fermée
}

void loop() {

  // Gestion entrée
  if (digitalRead(entree) == HIGH && places > 0) {
    barriere.write(90);
    places--;
    delay(2000);
    barriere.write(0);
  }

  // Gestion sortie
  if (digitalRead(sortie) == HIGH) {
    if (places < 5) {
      places++;
    }
    delay(1000);
  }

  // Gestion des LEDs
  if (places > 0) {
    digitalWrite(ledVerte, HIGH);
    digitalWrite(ledRouge, LOW);
  } else {
    digitalWrite(ledVerte, LOW);
    digitalWrite(ledRouge, HIGH);
  }

  // Affichage LCD
  lcd.setCursor(0, 1);
  lcd.print("Places: ");
  lcd.print(places);
  lcd.print("   ");
}