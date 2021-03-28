//
// Created by tkm36 on 2021/3/28.
//

#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H
#include "serial.h"
#include <cstring>
#include <iostream>

class Device {
    int fd;
    char buffer[60];
    // in order (Position, Velocity) x,y,z,r,p,a
    double message[12];

    Device();
    Device(const char* dev, int baud);
    void UART_RX();
};


#endif //SERIAL_DEVICE_H
