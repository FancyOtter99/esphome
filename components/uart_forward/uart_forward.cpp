#include "uart_forward.h"
namespace esphome {
namespace uart_forward {

// No setup required, everything is in loop
void register_uart_forward(UARTForwardComponent *comp) {
  App.register_component(comp);
}

}  // namespace uart_forward
}  // namespace esphome





