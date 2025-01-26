#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

const int pressureSensorPin = 13;
const int distanceSensorPin = A0;

unsigned long pressureActivatedTime = 0;
const unsigned long holdThreshold = 60000; // 1 minute hold threshold

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode(pressureSensorPin, INPUT);
  pinMode(distanceSensorPin, INPUT);
  Serial.println("Pressure and Distance Sensor with Servo Control Initialized");
}

void loop() {
  int pressureState = digitalRead(pressureSensorPin);
  int distanceValue = analogRead(distanceSensorPin);
  const int distanceThreshold = 500; // Threshold for object proximity

  // Silent Mode: No pressure detected and no nearby object
  if (pressureState == LOW && distanceValue > distanceThreshold) {
    setServosToPosition(0, 0, 0, 0);
    Serial.println("Silent Mode: Tentacles at Rest");
  }

  // Hunting Mode: Nearby object detected
  if (distanceValue <= distanceThreshold) {
    setServosToPosition(90, 90, 90, 90);
    Serial.println("Hunting Mode: Tentacles Contract");
    delay(500);
    setServosToPosition(45, 45, 45, 45);
    delay(500);
  }

  // Motion Mode: Both pressure and nearby object detected
  if (pressureState == HIGH && distanceValue <= distanceThreshold) {
    for (int i = 0; i < 5; i++) {
      setServosToPosition(90, 90, 0, 0); // Alternating positions
      delay(200);
      setServosToPosition(0, 0, 90, 90);
      delay(200);
    }
    Serial.println("Motion Mode: Tentacles Twitching");
  }

  // Centering Mode: Pressure held for over 1 minute
  if (pressureState == HIGH) {
    if (pressureActivatedTime == 0) {
      pressureActivatedTime = millis(); // Record activation time
    } else if (millis() - pressureActivatedTime > holdThreshold) {
      setServosToPosition(45, 135, 135, 45); // Move tentacles toward center
      Serial.println("Centering Mode: Tentacles Moving to Center");
    }
  } else {
    pressureActivatedTime = 0; // Reset timer when pressure is released
  }

  delay(100); // Small delay to stabilize loop
}

// Function to move all servos to specified positions
void setServosToPosition(int pos1, int pos2, int pos3, int pos4) {
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
}
