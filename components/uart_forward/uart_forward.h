#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace uart_forward {

class UARTForwardComponent : public Component, public uart::UARTDevice {
 public:
  explicit UARTForwardComponent(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

  void loop() override;

 protected:
  std::string buffer_;
};

}  // namespace uart_forward
}  // namespace esphome
