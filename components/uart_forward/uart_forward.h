#pragma once
#include "esphome.h"

class UARTForwardComponent : public Component {
 public:
  UARTForwardComponent(UARTComponent *uart, TextSensor *text_sensor) : uart_(uart), text_sensor_(text_sensor) {}

  void loop() override;

 protected:
  UARTComponent *uart_;
  TextSensor *text_sensor_;
};
