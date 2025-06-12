// uart_forward.h
#pragma once
#include "esphome.h"

class UARTForwardComponent : public esphome::Component {
 public:
  explicit UARTForwardComponent(esphome::UARTComponent *uart);
  void loop() override;

 protected:
  esphome::UARTComponent *uart_;
};
