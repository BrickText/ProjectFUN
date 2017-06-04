#include <Wire.h>

#define IR_CATODES 7
#define IR_INPUT 5

const int irCatodes[IR_CATODES] = {2, 3, 4, 5, 6, 7, 8}; // LOW
const int irInput[IR_INPUT] = {9, 10, 11, 12, A0};

void setup() {
  Wire.begin();
  
  Serial.begin(9600);
  // IR Catodes
  for (int i = 0; i < IR_CATODES; i++) {
    pinMode(irCatodes[i], OUTPUT);
    digitalWrite(irCatodes[i], HIGH);
  }

  // IR Input
  for (int i = 0; i < IR_INPUT; i++) {
    pinMode(irInput[i], INPUT);
  }
  digitalWrite(6, LOW);

}

void loop() {
  for (int i = 0; i < IR_CATODES; i++) {
    digitalWrite(irCatodes[i], LOW);
    delay(10);
    for (int j = 0; j < IR_INPUT; j++) {
      if (!digitalRead(irInput[j])) {
        Serial.print(i);
        Serial.print(" - ");
        Serial.println(j);
        Wire.beginTransmission(8);
        // Send catode
        Wire.write((byte)irCatodes[i]);
        // Send anode
        Wire.write((byte)irInput[j]);
        Wire.endTransmission();

      }
    }
    digitalWrite(irCatodes[i], HIGH);
  }
//  // Scan IR Matrix
//  for (int i = 0; i < IR_INPUT; i++) {
//    for (int j = 0; j < IR_CATODES; j++) {
//      digitalWrite(irCatodes[j], LOW);
//      if (!digitalRead(irInput[i])) {
//        Serial.print((byte)irCatodes[j]);
//        Serial.print(" - ");
//        Serial.println((byte)irInput[i]);
//        Wire.beginTransmission(8);
//        // Send catode
//        Wire.write((byte)irCatodes[j]);
//        // Send anode
//        Wire.write((byte)irInput[i]);
//        Wire.endTransmission();
//
//      }
//      digitalWrite(irCatodes[j], HIGH);
//    }
//  }
}
