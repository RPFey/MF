//
// Created by peter on 2021/3/25.
//

#include "serial/Device.h"

Device::Device(std::string dev, size_t length):
    uart_length(length)
{
    // open serial port
    fd = 0;

    // start thread
    uart = std::thread(&Device::uart, this);
}

void Device::stm32_uart() {

}
