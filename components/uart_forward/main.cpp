#include "uart_forward.h"

void setup() {
  auto my_uart = new esphome::uart_forward::UARTForwardComponent(id(my_uart));
  App.register_component(my_uart);
}
