// uart_forward.cpp
#include "uart_forward.h"

UARTForwardComponent::UARTForwardComponent(esphome::UARTComponent *uart) : uart_(uart) {}

void UARTForwardComponent::loop() {
  while (uart_->available()) {
    int c = uart_->read();
    if (c != -1) {
      // Send via HTTP or do whatever processing here
      ESP_LOGD("uart_forward", "Got char: %c", (char)c);
    }
  }
}



