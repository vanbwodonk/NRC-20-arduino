#include "nrc-20.h"

#include <Arduino.h>
#include <HardwareSerial.h>

NRC20::NRC20(uint8_t rxpin) { _rxpin = rxpin; }

NRC20::~NRC20() { Serial2.end(); }

void NRC20::begin() {
  Serial2.begin(19200);
  Serial2.setPins(_rxpin, -1);
  flush();
}

uint8_t NRC20::pool() {
  if (Serial2.available()) {
    packetCounter++;
    _LY = _LX;
    _LX = _RY;
    _RY = _RX;
    _RX = _SW;
    _SW = sync;
    sync = Serial2.read();
    if (packetCounter == 6) {
      packetCounter = 0;
      if (sync != 0x0A) {
        flush();
        return 0;
      } else {
        LY = _LY;
        LX = _LX;
        RY = _RY;
        RX = _RX;
        SW = _SW;
        return 1;
      }
    }
  }
  return 0;
}

void NRC20::flush() {
  Serial2.flush();
  char c;
  while (Serial2.available())
    c = Serial2.read();
}

uint8_t NRC20::getLY() { return LY; }
uint8_t NRC20::getLX() { return LX; }
uint8_t NRC20::getRY() { return RY; }
uint8_t NRC20::getRX() { return RX; }
uint8_t NRC20::getSW() { return SW; }