int ledRouge = 13;
int ledJaune = 12;
int ledVerte = 11;

void setup() {
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVerte, OUTPUT);
}

void loop() {
  // Vert
  digitalWrite(ledVerte, HIGH);
  digitalWrite(ledJaune, LOW);
  digitalWrite(ledRouge, LOW);
  delay(5000); // 5 sec

  // Jaune
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledJaune, HIGH);
  digitalWrite(ledRouge, LOW);
  delay(2000); // 2 sec

  // // Rouge
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledJaune, LOW);
  digitalWrite(ledRouge, HIGH);
  delay(5000); // 5 sec
}
