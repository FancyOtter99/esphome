#include "esphome.h"
#include "uart_forward.h"

using namespace esphome;

void setup() {
  auto *my_uart = new uart_forward::UARTForwardComponent(get_uart_by_id("my_uart"));
  App.register_component(my_uart);
}

