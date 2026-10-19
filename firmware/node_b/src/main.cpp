#include <Arduino.h>

const char* version = "v0.1.0";
const char* node = "NODE_B";

void setup() {
  Serial.begin(115200);
  Serial.print(node);
  Serial.print(" ");
  Serial.print("boot");
  Serial.print(" ");
  Serial.print("firmware");
  Serial.print(" ");
  Serial.print(version);
}

void loop() {
  // nic nie robic
}
