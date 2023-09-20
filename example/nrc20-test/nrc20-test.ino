#include "nrc-20.h"

NRC20 nrc20(15);  // set serial RX on pin 15

void setup() {
  Serial.begin(115200);
  Serial.print("NRC20 serial test");
  delay(2000);
  nrc20.begin();
}

void loop() {
  if(nrc20.pool()){
    Serial.print("LY = ");
    Serial.println(nrc20.getLY());
    Serial.print("LX = ");
    Serial.println(nrc20.getLX());
    Serial.print("RY = ");
    Serial.println(nrc20.getRY());
    Serial.print("RX = ");
    Serial.println(nrc20.getRX());
    Serial.print("L1 = ");
    Serial.println(nrc20.getL1());
    Serial.print("L2 = ");
    Serial.println(nrc20.getL2());
    Serial.print("R1 = ");
    Serial.println(nrc20.getR1());
    Serial.print("R2 = ");
    Serial.println(nrc20.getR2());
  } else {
    // Serial.println("nope");
  }
  delay(1);
}

