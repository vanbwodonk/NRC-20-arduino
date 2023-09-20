
#ifndef NRC20_H_
#define NRC20_H_

#include <Arduino.h>
#include <HardwareSerial.h>
#pragma once

class NRC20 {
private:
  uint8_t packetCounter = 0;
  char sync = 0x0A;
  uint8_t _LY, _LX, _RY, _RX, _SW;
  uint8_t LY, LX, RY, RX, SW;
  uint8_t _rxpin;

public:
  NRC20(uint8_t rxpin);
  ~NRC20();
  void begin();
  uint8_t pool();
  void flush();
  uint8_t getLY();
  uint8_t getLX();
  uint8_t getRY();
  uint8_t getRX();
  uint8_t getSW();
};

#endif