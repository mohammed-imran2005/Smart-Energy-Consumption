const int ldrPin = A0;
const int pirSensorPin1 = 2;
const int pirSensorPin2 = 3;
const int pirSensorPin3 = 4;
const int pirSensorPin4 = 5;
const int fanPin1 = 6;
const int fanPin2 = 7;
const int fanPin3 = 8;
const int fanPin4 = 9;
const int lightPin1 = 10;
const int lightPin2 = 11;
const int lightPin3 = 12;
const int lightPin4 = 13;
const int buzzPin = A2;
const int flamePin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(pirSensorPin1, INPUT);
  pinMode(pirSensorPin2, INPUT);
  pinMode(pirSensorPin3, INPUT);
  pinMode(pirSensorPin4, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  pinMode(fanPin3, OUTPUT);
  pinMode(fanPin4, OUTPUT);
  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);
  pinMode(lightPin3, OUTPUT);
  pinMode(lightPin4, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(flamePin, INPUT);

  delay(1000);
}

void loop() {
  int pirState1 = digitalRead(pirSensorPin1);
  int pirState2 = digitalRead(pirSensorPin2);
  int pirState3 = digitalRead(pirSensorPin3);
  int pirState4 = digitalRead(pirSensorPin4);
  int ldrValue = analogRead(ldrPin);
  int flameState = analogRead(flamePin);

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (pirState1 == HIGH) {
    digitalWrite(fanPin1, HIGH);
    Serial.println("Motion detected-P1!");
  } else {
    digitalWrite(fanPin1, LOW);
    Serial.println("No motion-P1");
  }
  if (pirState1 == HIGH) {
    if (ldrValue < 500){
    digitalWrite(lightPin1, HIGH);
    }
    Serial.println("Light ON-L1!");
  } else {
    digitalWrite(lightPin1, LOW);
    Serial.println("Light OFF-L1");
  }
if (pirState2 == HIGH) {
    digitalWrite(fanPin2, HIGH);
    Serial.println("Motion detected-P2!");
  } else {
    digitalWrite(fanPin2, LOW);
    Serial.println("No motion-P2");
  }
    if (pirState2 == HIGH) {
      if (ldrValue < 500){
    digitalWrite(lightPin2, HIGH);
      }
    Serial.println("Light ON-L2!");
  } else {
    digitalWrite(lightPin2, LOW);
    Serial.println("Light OFF-L2");
  }
  if (pirState3 == HIGH) {
    digitalWrite(fanPin3, HIGH);
    Serial.println("Motion detected-P3!");
  } else {
    digitalWrite(fanPin3, LOW);
    Serial.println("No motion-P3");
  }
  if (pirState3 == HIGH) {
    if (ldrValue < 500){
    digitalWrite(lightPin3, HIGH);
    }
    Serial.println("Light ON-L3!");
  } else {
    digitalWrite(lightPin3, LOW);
    Serial.println("Light OFF-L3");
  }
  if (pirState4 == HIGH) {
    digitalWrite(fanPin4, HIGH);
    Serial.println("Motion detected-P4!");
  } else {
    digitalWrite(fanPin4, LOW);
    Serial.println("No motion-P4");
  }
  if (pirState4 == HIGH) {
    if (ldrValue < 500){
    digitalWrite(lightPin4, HIGH);
    }
    Serial.println("Light ON-L4!");
  } else {
    digitalWrite(lightPin4, LOW);
    Serial.println("Light OFF-L4");
  }
  // Repeat similar pattern for other PIR sensors
  Serial.print("Flame value: ");
  Serial.println(flameState);

  // Check if flame is detected
  if (flameState < 900) {
    digitalWrite(buzzPin, HIGH);
  } else{
    digitalWrite(buzzPin, LOW);
  }
  // ...

  // Wait for a short time before checking again
  delay(1000);
}
