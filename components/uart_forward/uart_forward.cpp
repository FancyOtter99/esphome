#include "uart_forward.h"

void UARTForwardComponent::loop() {
  if (uart_->available()) {
    std::string data;
    while (uart_->available()) {
      char c = uart_->read();
      data.push_back(c);
    }
    text_sensor_->publish_state(data.c_str());
  }
}

