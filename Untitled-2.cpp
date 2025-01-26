#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

const int pressureSensorPin = 13;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode(pressureSensorPin, INPUT);
  Serial.println("Pressure Sensor and Servo Motor Control Initialized");
}

void loop() {
  int pressureState = digitalRead(pressureSensorPin);

  if (pressureState == HIGH) {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    Serial.println("Servos: Activated (90°)");
  } else {
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);
    Serial.println("Servos: Reset Position (0°)");
  }

  delay(100);
}