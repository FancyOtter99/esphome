#include "uart_forward.h"
#include "esphome/core/log.h"
#include "esphome/components/http_request/http_request_component.h"

namespace esphome {
namespace uart_forward {

static const char *const TAG = "uart_forward";

void UARTForwardComponent::loop() {
  while (available()) {
    char c = read();
    buffer_ += c;

    // Optional: terminate on newline and send it
    if (c == '\n') {
      ESP_LOGI(TAG, "Received UART data: %s", buffer_.c_str());

      // Send HTTP request (requires http_request integration setup in YAML)
      // id(my_http).post("https://your.server", buffer_);

      buffer_.clear();
    }
  }
}

}  // namespace uart_forward
}  // namespace esphome




