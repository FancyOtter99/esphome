#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace uart_forward {

class UARTForwardComponent : public Component, public uart::UARTDevice {
 public:
  explicit UARTForwardComponent(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

  void loop() override {
    std::string buffer;

    while (available()) {
      char c;
      if (read_byte((uint8_t *) &c)) {
        buffer += c;
      }
    }

    if (!buffer.empty()) {
      ESP_LOGI("uart_forward", "Received: %s", buffer.c_str());
      // You can extend this to publish to MQTT, Home Assistant event, etc.
    }
  }
};

}  // namespace uart_forward
}  // namespace esphome

