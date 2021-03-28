//
// Created by tkm36 on 2021/3/28.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include "wiringSerial.h"
#include "wiringPi.h"
#include <stdio.h>
#define Debug

#ifdef __cplusplus
extern "C"{
#endif

int stm32_uart(int fd, char* data, int max_length);
int stm32_uart_TX(int fd, char* data, int length, int num_trial);
int open_serial(const char* dev, int baud);

#ifdef __cplusplus
}
#endif
#endif //SERIAL_SERIAL_H
