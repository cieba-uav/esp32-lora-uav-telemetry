#include <Arduino.h>

const char* version = "v0.1.0";
const char* node = "NODE_A";
unsigned long myTime;
unsigned long startTime = 0;
const unsigned long interval_ms = 1000;
unsigned long start = 0 ;

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
  myTime = millis();
  if (myTime - startTime >= interval_ms)
  {
    startTime = startTime + interval_ms;
    start = start + 1;
    Serial.println(start);
  }
  
}
