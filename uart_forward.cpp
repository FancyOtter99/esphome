#include "uart_forward.h"
#include "esphome.h"

using namespace esphome;

UARTForwardComponent::UARTForwardComponent(UARTComponent *uart) {
  this->uart_ = uart;
}

void UARTForwardComponent::loop() {
  while (this->uart_->available()) {
    std::string data;
    while (this->uart_->available()) {
      char c = this->uart_->read();
      if (c == '\n') break;
      data += c;
    }
    if (!data.empty()) {
      this->publish_state(data);
    }
  }
}
