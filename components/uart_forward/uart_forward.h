#pragma once

#include "esphome.h"

class UARTForwardSensor : public Component, public Sensor {
 public:
  explicit UARTForwardSensor(UARTComponent *parent_uart) : uart_(parent_uart) {}

  void setup() override {
    // Called once when component is initialized
  }

  void loop() override {
    while (uart_->available()) {
      char c = uart_->read();
      buffer_ += c;

      // Send data when newline received
      if (c == '\n') {
        publish_state(buffer_);
        buffer_.clear();
      }
    }
  }

 protected:
  UARTComponent *uart_;
  std::string buffer_;
};
