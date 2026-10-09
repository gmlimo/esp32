#include <Arduino.h>

int potPin = 0;
int value = 0;
int result = 0;
int rx_data = 0;
int actuator = 4;

void setup() {
  Serial.begin(115200);
  pinMode(actuator, OUTPUT);
}

void loop() {
  value = analogRead(potPin);
  result = map(value, 0, 4095, 0, 2700);
  Serial.print("a");
  Serial.println(result);
  delay(200);

  if (Serial.available() > 0) {
    rx_data = Serial.read();

    if (rx_data == 'e') {
      digitalWrite(actuator, HIGH);
    } 
    else if (rx_data == 'n') {
      digitalWrite(actuator, LOW);
    }
    else {
      digitalWrite(actuator, LOW);
    }
  }
}

