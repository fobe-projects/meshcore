#pragma once

#include <Arduino.h>
#include <helpers/ESP32Board.h>

class FobeIdeaMeshRepeaterL1Board : public ESP32Board {
public:
  void begin() {
    ESP32Board::begin();

#ifdef P_LORA_TX_LED
    pinMode(P_LORA_TX_LED, OUTPUT);
    digitalWrite(P_LORA_TX_LED, HIGH);
#endif
  }

#if defined(P_LORA_TX_LED)
  void onBeforeTransmit() override {
    digitalWrite(P_LORA_TX_LED, LOW); // turn TX LED on
  }
  void onAfterTransmit() override {
    digitalWrite(P_LORA_TX_LED, HIGH); // turn TX LED off
  }
#endif

  const char *getManufacturerName() const override { return "FoBE IDEA Mesh Repeater L1"; }
};
