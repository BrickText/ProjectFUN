#include <Wire.h>

#define ANODES 7
#define CATODES 5

const int ledAnodes[ANODES] = {2, 3, 4, 5, 6, 7, 8}; // LOW
const int ledCatodes[CATODES] = {9, 10, 11, 12, A0}; // HIGH

void setup() {
  Wire.begin();
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  // LED Anodes
  for (int i = 0; i < ANODES; i++) {
    pinMode(ledAnodes[i], OUTPUT);
    digitalWrite(ledAnodes[i], HIGH);
  }

  // LED Catodes
  for (int i = 0; i < CATODES; i++) {
    pinMode(ledCatodes[i], OUTPUT);
    digitalWrite(ledCatodes[i], LOW);
  }
}

void loop() {

}

void receiveEvent(int howMany) {
  int catode;
  int anode;
  while (1 <= Wire.available()) {
    catode = Wire.read();
    anode = Wire.read();
  }
  
  digitalWrite(anode, LOW);
  digitalWrite(catode, HIGH);
  
  digitalWrite(anode, HIGH);
  digitalWrite(catode, LOW);

  Serial.print(catode);
  Serial.print(" - ");
  Serial.println(anode);
}

