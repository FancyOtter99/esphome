#pragma once
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace uart_forward {

class UARTForwardComponent : public Component, public uart::UARTDevice {
 public:
  UARTForwardComponent(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

  void loop() override {
    while (available()) {
      std::string data;
      while (available()) {
        char c;
        read_byte((uint8_t *)&c);
        data += c;
      }
      ESP_LOGI("UARTForward", "Received: %s", data.c_str());
      // Add HTTP post or other logic here
    }
  }
};

}  // namespace uart_forward
}  // namespace esphome
