//
// Created by peter on 2021/3/25.
//

#ifndef SRC_DEVICE_H
#define SRC_DEVICE_H
#include <string>
#include <thread>
#include <iostream>

class Device {
public:
    Device(std::string dev, size_t length);
    void stm32_uart();

    int fd;
    size_t uart_length;
    std::thread uart;
};


#endif //SRC_DEVICE_H
