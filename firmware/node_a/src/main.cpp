#include <Arduino.h>

const char* version = "v0.1.0";
const char* node = "NODE_A";

void setup() {
  Serial.begin(115200);
  Serial.print("Last reset reason: ");
  Serial.print(esp_reset_reason());
  Serial.println(" ");
  Serial.print(node);
  Serial.print(" ");
  Serial.print("boot");
  Serial.print(" ");
  Serial.print("firmware");
  Serial.print(" ");
  Serial.print(version);
  Serial.println();
}

void loop() {
  // nic nie robic
}
