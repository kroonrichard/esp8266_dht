#include <Arduino.h>

/**
 * Let's do a simple test to test our board.
 */
void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("Whatever");
  delay(1000);
}
